#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addrecipedialog.h"
#include "recipeviewdialog.h"
#include "searchdialog.h"
#include "profiledialog.h"

#include <QFile>
#include <QPixmap>
#include <QLabel>
#include <QListWidgetItem>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dialogOpen(false)
    , searchDialogOpen(false)
{
    ui->setupUi(this);
    showLoginForm();

    //connect(ui->addRecipeButton, &QToolButton::clicked, this, &MainWindow::on_addRecipeButton_clicked);
    connect(ui->navFavoritesButton, &QToolButton::clicked, this, &MainWindow::on_navFavoritesButton_clicked);
    connect(ui->navRecipesButton, &QToolButton::clicked, this, &MainWindow::on_navRecipesButton_clicked);
    connect(ui->favoritesNavFavoritesButton, &QToolButton::clicked, this, &MainWindow::on_favoritesNavFavoritesButton_clicked);
    connect(ui->favoritesNavRecipesButton, &QToolButton::clicked, this, &MainWindow::on_favoritesNavRecipesButton_clicked);
    connect(ui->favoritesNavProfileButton, &QToolButton::clicked, this, &MainWindow::on_favoritesNavProfileButton_clicked);
    
    // Подключаем обработчик клика на карточки рецептов
    connect(ui->recipesListWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::on_recipeItemDoubleClicked);
    connect(ui->favoritesListWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::on_recipeItemDoubleClicked);
    
    // Подключаем кнопки поиска
    //connect(ui->searchButton, &QToolButton::clicked, this, &MainWindow::on_searchButton_clicked);
    //connect(ui->favoritesSearchButton, &QToolButton::clicked, this, &MainWindow::on_favoritesSearchButton_clicked);
    
    // Подключаем кнопки навигации профиля
    connect(ui->navProfileButton, &QToolButton::clicked, this, &MainWindow::on_navProfileButton_clicked);
    connect(ui->profileNavFavoritesButton, &QToolButton::clicked, this, &MainWindow::on_profileNavFavoritesButton_clicked);
    connect(ui->profileNavRecipesButton, &QToolButton::clicked, this, &MainWindow::on_profileNavRecipesButton_clicked);
    connect(ui->profileNavProfileButton, &QToolButton::clicked, this, &MainWindow::on_profileNavProfileButton_clicked);
    //connect(ui->profileEditButton, &QPushButton::clicked, this, &MainWindow::on_profileEditButton_clicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::on_logoutButton_clicked);
    //connect(ui->dataManagementComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_dataManagementComboBox_currentIndexChanged);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QLabel *heartLabel = qobject_cast<QLabel*>(obj);
        if (heartLabel && heartLabel->property("recipeId").isValid()) {
            int recipeId = heartLabel->property("recipeId").toInt();
            toggleFavourite(heartLabel, recipeId);
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLoginForm()
{
    ui->stackedLayout->setCurrentIndex(0);  // Экран авторизации
    ui->statusLabel->clear();
}

void MainWindow::showMainInterface()
{
    ui->stackedLayout->setCurrentIndex(1);  // Главный экран
    ui->welcomeLabel->setText("Мои рецепты");
    loadRecipes();  // Загружаем рецепты пользователя
}

void MainWindow::showFavoritesInterface()
{
    ui->stackedLayout->setCurrentIndex(2);  // Страница избранного
    loadFavorites();  // Загружаем избранные рецепты
}

void MainWindow::showProfileInterface()
{
    ui->stackedLayout->setCurrentIndex(3);  // Страница профиля
    loadProfile();  // Загружаем данные профиля
    
    // Инициализируем ComboBox управления данными
    ui->dataManagementComboBox->clear();
    ui->dataManagementComboBox->addItem("Управление данными", QVariant());
    ui->dataManagementComboBox->addItem("Экспорт", QVariant(1));
    ui->dataManagementComboBox->addItem("Импорт", QVariant(2));
    ui->dataManagementComboBox->setCurrentIndex(0);

}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->statusLabel->setText("Заполните все поля");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT id, password FROM users WHERE username = ?");
    query.addBindValue(username);
    if (!query.exec()) {
        ui->statusLabel->setText("Ошибка базы данных");
        return;
    }

    if (query.next()) {
        QString storedPassword = query.value(1).toString();
        if (storedPassword == password) {
            currentUser = User(query.value(0).toInt(), username, password);
            showMainInterface();
        } else {
            ui->statusLabel->setText("Неверный пароль");
        }
    } else {
        ui->statusLabel->setText("Пользователь не найден");
    }
}

void MainWindow::on_registerButton_clicked()
{
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->statusLabel->setText("Заполните все поля");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);

    if (query.exec()) {
        ui->statusLabel->setText("Регистрация успешна! Теперь войдите.");
    } else {
        ui->statusLabel->setText("Ошибка: " + query.lastError().text());
        // Часто ошибка — пользователь уже существует
    }
}

void MainWindow::loadRecipes()
{
    ui->recipesListWidget->clear();

    QSqlQuery query;
    query.prepare("SELECT id, name, time, photo_path, category_id FROM recipes WHERE user_id = ?");
    query.addBindValue(currentUser.getId());
    query.exec();

    while (query.next()) {
        int recipeId = query.value(0).toInt();
        QString name = query.value(1).toString();
        int time = query.value(2).toInt();
        QString photoPath = query.value(3).toString();

        // Проверяем, есть ли рецепт в избранном
        QSqlQuery favQuery;
        favQuery.prepare("SELECT COUNT(*) FROM favourites WHERE user_id = ? AND recipe_id = ?");
        favQuery.addBindValue(currentUser.getId());
        favQuery.addBindValue(recipeId);
        favQuery.exec();
        favQuery.next();
        bool isFavourite = favQuery.value(0).toInt() > 0;

        // Создаём красивую карточку
        QListWidgetItem *item = new QListWidgetItem();
        item->setData(Qt::UserRole, recipeId);  // Сохраняем ID рецепта

        QWidget *card = new QWidget();
        card->setStyleSheet("background-color: white; border-radius: 16px;");
        card->setMinimumWidth(600); // Увеличиваем минимальную ширину карточки
        card->setMinimumHeight(120);
        // Добавляем тень для карточки
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
        shadow->setBlurRadius(10);
        shadow->setColor(QColor(0, 0, 0, 30));
        shadow->setOffset(0, 2);
        card->setGraphicsEffect(shadow);
        
        QHBoxLayout *layout = new QHBoxLayout(card);
        layout->setContentsMargins(16, 16, 16, 16);
        layout->setSpacing(16);

        // Фото (если есть, иначе placeholder)
        QLabel *photoLabel = new QLabel();
        photoLabel->setFixedSize(100, 100);
        photoLabel->setStyleSheet("border-radius: 12px; background-color: #f0f0f0;");
        photoLabel->setAlignment(Qt::AlignCenter);
        
        if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
            QPixmap pix(photoPath);
            photoLabel->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
            photoLabel->setStyleSheet("border-radius: 12px;");
        } else {
            photoLabel->setText("📷");
            photoLabel->setStyleSheet("border-radius: 12px; background-color: #f0f0f0; font-size: 40px;");
        }
        layout->addWidget(photoLabel);

        // Текст справа от фото
        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(8);
        textLayout->setContentsMargins(0, 0, 0, 0);
        
        // Название и сердечко в одной строке
        QHBoxLayout *nameLayout = new QHBoxLayout();
        nameLayout->setContentsMargins(0, 0, 0, 0);
        nameLayout->setSpacing(8);
        
        QLabel *nameLabel = new QLabel(name);
        nameLabel->setStyleSheet("font-weight: bold; font-size: 18px; color: #212529;");
        nameLabel->setWordWrap(true);
        nameLayout->addWidget(nameLabel);
        nameLayout->addStretch();
        
        // Сердечко избранного - используем иконку для избранных, эмодзи для не избранных
        QLabel *heart = new QLabel();
        if (isFavourite) {
            heart->setPixmap(QPixmap(":/icons/icons/favorites.png").scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            heart->setText("🤍");
            heart->setStyleSheet("font-size: 24px; color: #ff3333;");
        }
        heart->setCursor(Qt::PointingHandCursor);
        heart->setProperty("recipeId", recipeId);
        heart->setProperty("isFavourite", isFavourite);
        // Используем mousePressEvent через eventFilter
        heart->installEventFilter(this);
        nameLayout->addWidget(heart);
        
        textLayout->addLayout(nameLayout);
        
        QLabel *timeLabel = new QLabel(QString("Время приготовления: %1 минут").arg(time));
        timeLabel->setStyleSheet("color: #666; font-size: 14px;");
        textLayout->addWidget(timeLabel);
        
        textLayout->addStretch();
        layout->addLayout(textLayout, 1);

        card->setLayout(layout);
        item->setSizeHint(QSize(0, 150));  // Высота карточки соответствует минимальной высоте

        ui->recipesListWidget->addItem(item);
        ui->recipesListWidget->setItemWidget(item, card);
    }

    if (ui->recipesListWidget->count() == 0) {
        ui->recipesListWidget->addItem("Нет рецептов. Нажмите + чтобы добавить!");
    }
}

void MainWindow::loadFavorites()
{
    ui->favoritesListWidget->clear();

    QSqlQuery query;
    // Выбираем рецепты, которые есть в избранном у текущего пользователя
    query.prepare("SELECT r.id, r.name, r.time, r.photo_path, r.category_id "
                  "FROM recipes r "
                  "INNER JOIN favourites f ON r.id = f.recipe_id "
                  "WHERE f.user_id = ?");
    query.addBindValue(currentUser.getId());
    query.exec();

    while (query.next()) {
        int recipeId = query.value(0).toInt();
        QString name = query.value(1).toString();
        int time = query.value(2).toInt();
        QString photoPath = query.value(3).toString();

        // Создаём красивую карточку
        QListWidgetItem *item = new QListWidgetItem();
        item->setData(Qt::UserRole, recipeId);  // Сохраняем ID рецепта

        QWidget *card = new QWidget();
        card->setStyleSheet("background-color: white; border-radius: 16px;");
        card->setMinimumWidth(600); // Увеличиваем минимальную ширину карточки
        card->setMinimumHeight(120);
        
        // Добавляем тень для карточки
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
        shadow->setBlurRadius(10);
        shadow->setColor(QColor(0, 0, 0, 30));
        shadow->setOffset(0, 2);
        card->setGraphicsEffect(shadow);
        
        QHBoxLayout *layout = new QHBoxLayout(card);
        layout->setContentsMargins(16, 16, 16, 16);
        layout->setSpacing(16);

        // Фото (если есть, иначе placeholder)
        QLabel *photoLabel = new QLabel();
        photoLabel->setFixedSize(100, 100);
        photoLabel->setStyleSheet("border-radius: 12px; background-color: #f0f0f0;");
        photoLabel->setAlignment(Qt::AlignCenter);
        
        if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
            QPixmap pix(photoPath);
            photoLabel->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
            photoLabel->setStyleSheet("border-radius: 12px;");
        } else {
            photoLabel->setText("📷");
            photoLabel->setStyleSheet("border-radius: 12px; background-color: #f0f0f0; font-size: 40px;");
        }
        layout->addWidget(photoLabel);

        // Текст справа от фото
        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(8);
        textLayout->setContentsMargins(0, 0, 0, 0);
        
        // Название и сердечко в одной строке
        QHBoxLayout *nameLayout = new QHBoxLayout();
        nameLayout->setContentsMargins(0, 0, 0, 0);
        nameLayout->setSpacing(8);
        
        QLabel *nameLabel = new QLabel(name);
        nameLabel->setStyleSheet("font-weight: bold; font-size: 18px; color: #212529;");
        nameLabel->setWordWrap(true);
        nameLayout->addWidget(nameLabel);
        nameLayout->addStretch();
        
        // Сердечко избранного - используем иконку (всегда избранное на странице избранного)
        QLabel *heart = new QLabel();
        heart->setPixmap(QPixmap(":/icons/icons/favorites.png").scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        heart->setCursor(Qt::PointingHandCursor);
        heart->setProperty("recipeId", recipeId);
        heart->setProperty("isFavourite", true);
        // Используем mousePressEvent через eventFilter
        heart->installEventFilter(this);
        nameLayout->addWidget(heart);
        
        textLayout->addLayout(nameLayout);
        
        QLabel *timeLabel = new QLabel(QString("Время приготовления: %1 минут").arg(time));
        timeLabel->setStyleSheet("color: #666; font-size: 14px;");
        textLayout->addWidget(timeLabel);
        
        textLayout->addStretch();
        layout->addLayout(textLayout, 1);

        card->setLayout(layout);
        item->setSizeHint(QSize(0, 150));  // Высота карточки соответствует минимальной высоте

        ui->favoritesListWidget->addItem(item);
        ui->favoritesListWidget->setItemWidget(item, card);
    }

    if (ui->favoritesListWidget->count() == 0) {
        ui->favoritesListWidget->addItem("Нет избранных рецептов. Добавьте рецепты в избранное на странице 'Мои рецепты'!");
    }
}

void MainWindow::on_navFavoritesButton_clicked()
{
    showFavoritesInterface();
}

void MainWindow::on_navRecipesButton_clicked()
{
    showMainInterface();
}

void MainWindow::on_favoritesNavFavoritesButton_clicked()
{
    showFavoritesInterface();
}

void MainWindow::on_favoritesNavRecipesButton_clicked()
{
    showMainInterface();
}

void MainWindow::on_favoritesNavProfileButton_clicked()
{
    showProfileInterface();
}

void MainWindow::on_recipeItemDoubleClicked(QListWidgetItem *item)
{
    int recipeId = item->data(Qt::UserRole).toInt();
    if (recipeId > 0) {
        RecipeViewDialog dialog(recipeId, currentUser.getId(), this);
        if (dialog.exec() == QDialog::Accepted) {
            // Если рецепт был удален, обновляем список
            loadRecipes();
            loadFavorites();
        }
    }
}

void MainWindow::on_addRecipeButton_clicked()
{
    // Предотвращаем повторное открытие диалога
    if (dialogOpen) {
        return;
    }
    
    dialogOpen = true;
    
    // Блокируем кнопку, чтобы предотвратить повторные нажатия
    ui->addRecipeButton->setEnabled(false);
    
    AddRecipeDialog dialog(currentUser.getId(), this);
    int result = dialog.exec();
    
    // Разблокируем кнопку после закрытия диалога
    ui->addRecipeButton->setEnabled(true);
    dialogOpen = false;
    
    if (result == QDialog::Accepted) {
        loadRecipes(); // Обновляем список
        ui->statusbar->showMessage("Рецепт успешно добавлен!", 3000); // Показываем сообщение на 3 секунды
    }
}

void MainWindow::toggleFavourite(QLabel *heartLabel, int recipeId)
{
    bool isFavourite = heartLabel->property("isFavourite").toBool();
    
    QSqlQuery query;
    if (isFavourite) {
        // Удаляем из избранного
        query.prepare("DELETE FROM favourites WHERE user_id = ? AND recipe_id = ?");
    } else {
        // Добавляем в избранное
        query.prepare("INSERT OR IGNORE INTO favourites (user_id, recipe_id) VALUES (?, ?)");
    }
    query.addBindValue(currentUser.getId());
    query.addBindValue(recipeId);
    query.exec();
    
    // Обновляем иконку
    isFavourite = !isFavourite;
    if (isFavourite) {
        heartLabel->clear();
        heartLabel->setPixmap(QPixmap(":/icons/icons/favorites.png").scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        heartLabel->setStyleSheet("");
    } else {
        heartLabel->clear();
        heartLabel->setText("🤍");
        heartLabel->setStyleSheet("font-size: 24px; color: #ff3333;");
    }
    heartLabel->setProperty("isFavourite", isFavourite);
    
    // Если мы на странице избранного и удалили рецепт, обновляем список
    if (ui->stackedLayout->currentIndex() == 2 && !isFavourite) {
        loadFavorites();
    }
    
    // Если мы на главной странице, обновляем список рецептов
    if (ui->stackedLayout->currentIndex() == 1) {
        loadRecipes();
    }
}

void MainWindow::on_searchButton_clicked()
{
    if (searchDialogOpen) {
        return;
    }
    searchDialogOpen = true;
    SearchDialog dialog(currentUser.getId(), SearchDialog::SearchAllRecipes, this);
    dialog.setModal(true);
    int result = dialog.exec();
    searchDialogOpen = false;
    // Обновляем список после закрытия диалога поиска только если диалог действительно закрыт
    if (result == QDialog::Rejected || result == QDialog::Accepted) {
        loadRecipes();
        loadFavorites();
    }
}

void MainWindow::on_favoritesSearchButton_clicked()
{
    if (searchDialogOpen) {
        return;
    }
    searchDialogOpen = true;
    SearchDialog dialog(currentUser.getId(), SearchDialog::SearchFavorites, this);
    dialog.setModal(true);
    int result = dialog.exec();
    searchDialogOpen = false;
    // Обновляем список после закрытия диалога поиска только если диалог действительно закрыт
    if (result == QDialog::Rejected || result == QDialog::Accepted) {
        loadRecipes();
        loadFavorites();
    }
}

void MainWindow::on_navProfileButton_clicked()
{
    showProfileInterface();
}

void MainWindow::on_profileNavFavoritesButton_clicked()
{
    showFavoritesInterface();
}

void MainWindow::on_profileNavRecipesButton_clicked()
{
    showMainInterface();
}

void MainWindow::on_profileNavProfileButton_clicked()
{
    showProfileInterface();
}

void MainWindow::on_profileEditButton_clicked()
{
    ProfileDialog dialog(currentUser.getId(), this);
    if (dialog.exec() == QDialog::Accepted) {
        loadProfile();  // Обновляем данные профиля
    }
}

void MainWindow::on_logoutButton_clicked()
{
    showLoginForm();
    currentUser = User();  // Сбрасываем текущего пользователя
}

void MainWindow::on_dataManagementComboBox_currentIndexChanged(int index)
{
    if (index == 1) { // Экспорт
        exportData();
        ui->dataManagementComboBox->setCurrentIndex(0); // Возвращаем на placeholder
    } else if (index == 2) { // Импорт
        importData();
        ui->dataManagementComboBox->setCurrentIndex(0); // Возвращаем на placeholder
    }
}

void MainWindow::loadProfile()
{
    QSqlQuery query;
    query.prepare("SELECT first_name, last_name, position, photo_path FROM users WHERE id = ?");
    query.addBindValue(currentUser.getId());
    
    if (query.exec() && query.next()) {
        QString firstName = query.value(0).toString();
        QString lastName = query.value(1).toString();
        QString position = query.value(2).toString();
        QString photoPath = query.value(3).toString();
        
        ui->profileNameLabel->setText("Имя: " + (firstName.isEmpty() ? "-" : firstName));
        ui->profileLastNameLabel->setText("Фамилия: " + (lastName.isEmpty() ? "-" : lastName));
        ui->profilePositionLabel->setText("Должность: " + (position.isEmpty() ? "-" : position));
        
        // Загружаем фото профиля
        if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
            QPixmap pix(photoPath);
            ui->profilePhotoLabel->setPixmap(pix.scaled(160, 160, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
            ui->profilePhotoLabel->setStyleSheet("border: 2px solid #ced4da; border-radius: 80px;");
        } else {
            ui->profilePhotoLabel->setText("👤");
            ui->profilePhotoLabel->setStyleSheet("border: 2px solid #ced4da; border-radius: 80px; background-color: #f8f9fa; font-size: 80px;");
        }
    }
    
    // Загружаем статистику
    QSqlQuery recipesQuery;
    recipesQuery.prepare("SELECT COUNT(*) FROM recipes WHERE user_id = ?");
    recipesQuery.addBindValue(currentUser.getId());
    recipesQuery.exec();
    recipesQuery.next();
    int totalRecipes = recipesQuery.value(0).toInt();
    
    QSqlQuery favQuery;
    favQuery.prepare("SELECT COUNT(*) FROM favourites WHERE user_id = ?");
    favQuery.addBindValue(currentUser.getId());
    favQuery.exec();
    favQuery.next();
    int favoritesCount = favQuery.value(0).toInt();
    
    ui->totalRecipesButton->setText(QString("Всего рецептов: %1").arg(totalRecipes));
    ui->favoritesCountButton->setText(QString("В избранном: %1").arg(favoritesCount));
}

void MainWindow::exportData()
{
    static bool isExporting = false;
    if (isExporting) return;
    isExporting = true;
    // Подсчитываем количество рецептов и фотографий
    QSqlQuery recipesQuery;
    recipesQuery.prepare("SELECT COUNT(*), COUNT(CASE WHEN photo_path IS NOT NULL AND photo_path != '' THEN 1 END) FROM recipes WHERE user_id = ?");
    recipesQuery.addBindValue(currentUser.getId());
    recipesQuery.exec();
    recipesQuery.next();
    int recipesCount = recipesQuery.value(0).toInt();
    int photosCount = recipesQuery.value(1).toInt();
    
    QString dateStr = QDateTime::currentDateTime().toString("yyyy_MM_dd");
    QString fileName = QString("backup_%1.json").arg(dateStr);
    
    // Показываем информацию ПЕРЕД выбором файла
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Экспорт данных");
    msgBox.setText(QString("Будет сохранено %1 рецептов, %2 фотографий.\nФайл: %3")
        .arg(recipesCount).arg(photosCount).arg(fileName));
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    
    if (msgBox.exec() != QMessageBox::Ok) {
        return; // Пользователь отменил
    }
    
    // Создаем JSON объект с данными
    QJsonObject rootObj;
    rootObj["export_date"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    rootObj["user_id"] = currentUser.getId();
    
    // Экспортируем рецепты
    QJsonArray recipesArray;
    QSqlQuery query;
    query.prepare("SELECT id, name, time, photo_path, category_id FROM recipes WHERE user_id = ?");
    query.addBindValue(currentUser.getId());
    query.exec();
    
    while (query.next()) {
        QJsonObject recipeObj;
        recipeObj["id"] = query.value(0).toInt();
        recipeObj["name"] = query.value(1).toString();
        recipeObj["time"] = query.value(2).toInt();
        recipeObj["photo_path"] = query.value(3).toString();
        recipeObj["category_id"] = query.value(4).toInt();
        
        // Экспортируем ингредиенты
        QJsonArray ingredientsArray;
        QSqlQuery ingQuery;
        ingQuery.prepare("SELECT name, quantity FROM ingredients WHERE recipe_id = ?");
        ingQuery.addBindValue(recipeObj["id"].toInt());
        ingQuery.exec();
        while (ingQuery.next()) {
            QJsonObject ingObj;
            ingObj["name"] = ingQuery.value(0).toString();
            ingObj["quantity"] = ingQuery.value(1).toString();
            ingredientsArray.append(ingObj);
        }
        recipeObj["ingredients"] = ingredientsArray;
        
        // Экспортируем шаги
        QJsonArray stepsArray;
        QSqlQuery stepsQuery;
        stepsQuery.prepare("SELECT step_number, description FROM steps WHERE recipe_id = ? ORDER BY step_number");
        stepsQuery.addBindValue(recipeObj["id"].toInt());
        stepsQuery.exec();
        while (stepsQuery.next()) {
            QJsonObject stepObj;
            stepObj["step_number"] = stepsQuery.value(0).toInt();
            stepObj["description"] = stepsQuery.value(1).toString();
            stepsArray.append(stepObj);
        }
        recipeObj["steps"] = stepsArray;
        
        recipesArray.append(recipeObj);
    }
    rootObj["recipes"] = recipesArray;
    
    // Сохраняем в файл
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить резервную копию", fileName, "JSON Files (*.json)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            QJsonDocument doc(rootObj);
            file.write(doc.toJson());
            file.close();
            QMessageBox::information(this, "Успех", "Данные успешно экспортированы!");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл");
        }
    }
    isExporting = false;
}

void MainWindow::importData()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Импортировать данные", "", "JSON Files (*.json)");
    if (filePath.isEmpty()) {
        return;
    }
    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
        return;
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        QMessageBox::critical(this, "Ошибка", "Неверный формат файла");
        return;
    }
    
    QJsonObject rootObj = doc.object();
    QJsonArray recipesArray = rootObj["recipes"].toArray();
    
    int recipesCount = recipesArray.size();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Импорт данных",
        QString("Будет импортировано %1 рецептов. Продолжить?").arg(recipesCount),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        QSqlDatabase db = QSqlDatabase::database();
        db.transaction();
        
        int imported = 0;
        for (const QJsonValue &value : recipesArray) {
            QJsonObject recipeObj = value.toObject();
            
            // Импортируем рецепт
            QSqlQuery query;
            query.prepare("INSERT INTO recipes (user_id, name, time, photo_path, category_id) VALUES (?, ?, ?, ?, ?)");
            query.addBindValue(currentUser.getId());
            query.addBindValue(recipeObj["name"].toString());
            query.addBindValue(recipeObj["time"].toInt());
            query.addBindValue(recipeObj["photo_path"].toString());
            query.addBindValue(recipeObj["category_id"].toInt());
            
            if (query.exec()) {
                int recipeId = query.lastInsertId().toInt();
                
                // Импортируем ингредиенты
                QJsonArray ingredientsArray = recipeObj["ingredients"].toArray();
                for (const QJsonValue &ingValue : ingredientsArray) {
                    QJsonObject ingObj = ingValue.toObject();
                    QSqlQuery ingQuery;
                    ingQuery.prepare("INSERT INTO ingredients (recipe_id, name, quantity) VALUES (?, ?, ?)");
                    ingQuery.addBindValue(recipeId);
                    ingQuery.addBindValue(ingObj["name"].toString());
                    ingQuery.addBindValue(ingObj["quantity"].toString());
                    ingQuery.exec();
                }
                
                // Импортируем шаги
                QJsonArray stepsArray = recipeObj["steps"].toArray();
                for (const QJsonValue &stepValue : stepsArray) {
                    QJsonObject stepObj = stepValue.toObject();
                    QSqlQuery stepQuery;
                    stepQuery.prepare("INSERT INTO steps (recipe_id, step_number, description) VALUES (?, ?, ?)");
                    stepQuery.addBindValue(recipeId);
                    stepQuery.addBindValue(stepObj["step_number"].toInt());
                    stepQuery.addBindValue(stepObj["description"].toString());
                    stepQuery.exec();
                }
                
                imported++;
            }
        }
        
        if (db.commit()) {
            QMessageBox::information(this, "Успех", QString("Импортировано %1 рецептов").arg(imported));
            loadRecipes();
            loadFavorites();
        } else {
            db.rollback();
            QMessageBox::critical(this, "Ошибка", "Не удалось импортировать данные");
        }
    }
}
