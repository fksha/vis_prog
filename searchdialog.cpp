#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "recipeviewdialog.h"
#include "filterstrategy.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QTimer>
#include <QSet>
#include <QDebug>
#include <QBrush>
#include <QColor>
#include <algorithm>
#include <QCompleter>
#include <QStringListModel>

SearchDialog::SearchDialog(int userId, SearchMode mode, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
    , currentUserId(userId)
    , searchMode(mode)
    , minTime(5)
    , maxTime(300)
{
    ui->setupUi(this);
    
    // Настраиваем таймер для поиска в реальном времени
    searchTimer = new QTimer(this);
    searchTimer->setSingleShot(true);
    searchTimer->setInterval(300); // Задержка 300мс
    connect(searchTimer, &QTimer::timeout, this, &SearchDialog::performSearch);
    
    // Инициализация слайдеров и спинбоксов времени
    ui->timeMinSlider->setValue(5);
    ui->timeMaxSlider->setValue(300);
    ui->timeMinSpinBox->setValue(5);
    ui->timeMaxSpinBox->setValue(300);
    minTime = 5;
    maxTime = 300;
    updateTimeLabels();
    
    // Загружаем категории и ингредиенты
    loadCategories();
    loadIngredients();
    
    // Применяем начальные стили к кнопкам фильтров
    updateFilterButtons();
    
    // Подключаем сигналы
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &SearchDialog::on_searchLineEdit_textChanged);
    connect(ui->categoriesComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SearchDialog::on_categoriesComboBox_currentIndexChanged);
    connect(ui->ingredientsComboBox, &QComboBox::editTextChanged, this, &SearchDialog::on_ingredientsComboBox_editTextChanged);
    connect(ui->ingredientsComboBox, QOverload<int>::of(&QComboBox::activated), this, &SearchDialog::on_ingredientsComboBox_activated);
    connect(ui->ingredientsComboBox->lineEdit(), &QLineEdit::returnPressed, this, &SearchDialog::handleIngredientReturnPressed);
    connect(ui->ingredientsComboBox->lineEdit(), &QLineEdit::editingFinished, this, &SearchDialog::handleIngredientEditingFinished);
    connect(ui->timeMinSlider, &QSlider::valueChanged, this, &SearchDialog::on_timeMinSlider_valueChanged);
    connect(ui->timeMaxSlider, &QSlider::valueChanged, this, &SearchDialog::on_timeMaxSlider_valueChanged);
    connect(ui->timeMinSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &SearchDialog::on_timeMinSpinBox_valueChanged);
    connect(ui->timeMaxSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &SearchDialog::on_timeMaxSpinBox_valueChanged);
    connect(ui->resultsListWidget, &QListWidget::itemDoubleClicked, this, &SearchDialog::on_recipeItemDoubleClicked);
    
    // Устанавливаем фокус на поле поиска
    ui->searchLineEdit->setFocus();
    
    // Загружаем все рецепты при открытии
    loadResults();
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::closeEvent(QCloseEvent *event)
{
    event->accept();
    QDialog::reject();
}

bool SearchDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QLabel *heartLabel = qobject_cast<QLabel*>(obj);
        if (heartLabel && heartLabel->property("recipeId").isValid()) {
            int recipeId = heartLabel->property("recipeId").toInt();
            toggleFavourite(heartLabel, recipeId);
            return true;
        }
        
        // Обработка удаления чипса фильтра
        QLabel *chipLabel = qobject_cast<QLabel*>(obj);
        if (chipLabel && chipLabel->property("filterType").isValid()) {
            QString filterType = chipLabel->property("filterType").toString();
            removeFilterChip(filterType);
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

void SearchDialog::on_backButton_clicked()
{
    QDialog::reject();
}

void SearchDialog::handleIngredientEditingFinished()
{
    QString ingredient = ui->ingredientsComboBox->currentText().trimmed();
    if (!ingredient.isEmpty() && !selectedIngredients.contains(ingredient)) {
        // Проверяем, что ингредиент существует в базе
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM ingredients WHERE name = ?");
        checkQuery.addBindValue(ingredient);
        if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
            selectedIngredients.insert(ingredient);
            updateSelectedFilters();
            performSearch();
            // Очищаем поле ввода после выбора
            ui->ingredientsComboBox->setEditText("");
            ui->ingredientsComboBox->lineEdit()->setPlaceholderText("Введите название ингредиентов...");
        }
    }
}

void SearchDialog::on_clearSearchButton_clicked()
{
    ui->searchLineEdit->clear();
    searchText.clear();
    performSearch();
}

void SearchDialog::on_searchLineEdit_textChanged(const QString &text)
{
    searchText = text.trimmed();
    // Запускаем таймер для поиска в реальном времени
    searchTimer->start();
}

void SearchDialog::on_categoriesComboBox_currentIndexChanged(int index)
{
    if (index > 0) { // 0 - это placeholder "Категории"
        QVariant data = ui->categoriesComboBox->currentData();
        if (data.isValid() && data.toInt() > 0) {
            int categoryId = data.toInt();
            selectedCategoryIds.clear();
            selectedCategoryIds.insert(categoryId);
        } else {
            selectedCategoryIds.clear();
        }
    } else {
        selectedCategoryIds.clear();
    }
    updateSelectedFilters();
    performSearch();
}

void SearchDialog::on_ingredientsComboBox_editTextChanged(const QString &text)
{
    // Игнорируем изменения, если это placeholder
    if (text == "Ингредиенты" || text.trimmed().isEmpty()) {
        return;
    }
}

void SearchDialog::on_ingredientsComboBox_activated(int index)
{
    if (index >= 0) {
        QString ingredient = ui->ingredientsComboBox->itemText(index).trimmed();
        if (!ingredient.isEmpty() && !selectedIngredients.contains(ingredient)) {
            selectedIngredients.insert(ingredient);
            updateSelectedFilters();
            performSearch();
            // Очищаем поле ввода после выбора
            ui->ingredientsComboBox->setEditText("");
            ui->ingredientsComboBox->lineEdit()->setPlaceholderText("Введите название ингредиентов...");
        }
    }
}

void SearchDialog::handleIngredientReturnPressed()
{
    QString ingredient = ui->ingredientsComboBox->currentText().trimmed();
    if (!ingredient.isEmpty() && !selectedIngredients.contains(ingredient)) {
        // Проверяем, что ингредиент существует в базе
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM ingredients WHERE name = ?");
        checkQuery.addBindValue(ingredient);
        if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
            selectedIngredients.insert(ingredient);
            updateSelectedFilters();
            performSearch();
            // Очищаем поле ввода после выбора
            ui->ingredientsComboBox->setEditText("");
            ui->ingredientsComboBox->lineEdit()->setPlaceholderText("Введите название ингредиентов...");
        }
    }
}

void SearchDialog::on_timeFilterButton_clicked()
{
    bool visible = ui->timePanel->isVisible();
    ui->timePanel->setVisible(!visible);
    updateFilterButtons();
}

void SearchDialog::on_resetFiltersButton_clicked()
{
    // Сбрасываем все фильтры
    searchText.clear();
    ui->searchLineEdit->clear();
    selectedCategoryIds.clear();
    selectedIngredients.clear();
    ui->categoriesComboBox->setCurrentIndex(0);
    ui->ingredientsComboBox->setEditText("");
    ui->timeMinSlider->setValue(5);
    ui->timeMaxSlider->setValue(300);
    ui->timeMinSpinBox->setValue(5);
    ui->timeMaxSpinBox->setValue(300);
    minTime = 5;
    maxTime = 300;
    updateTimeLabels();
    ui->timePanel->setVisible(false);
    
    // Очищаем выбранные фильтры
    QLayoutItem *item;
    while ((item = ui->selectedFiltersLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    
    // Обновляем UI
    loadCategories();
    loadIngredients();
    updateFilterButtons();
    performSearch();
}

void SearchDialog::on_timeMinSlider_valueChanged(int value)
{
    minTime = value;
    if (minTime > maxTime) {
        maxTime = minTime;
        ui->timeMaxSlider->setValue(maxTime);
        ui->timeMaxSpinBox->setValue(maxTime);
    }
    ui->timeMinSpinBox->blockSignals(true);
    ui->timeMinSpinBox->setValue(minTime);
    ui->timeMinSpinBox->blockSignals(false);
    updateTimeLabels();
    performSearch();
}

void SearchDialog::on_timeMaxSlider_valueChanged(int value)
{
    maxTime = value;
    if (maxTime < minTime) {
        minTime = maxTime;
        ui->timeMinSlider->setValue(minTime);
        ui->timeMinSpinBox->setValue(minTime);
    }
    ui->timeMaxSpinBox->blockSignals(true);
    ui->timeMaxSpinBox->setValue(maxTime);
    ui->timeMaxSpinBox->blockSignals(false);
    updateTimeLabels();
    performSearch();
}

void SearchDialog::on_timeMinSpinBox_valueChanged(int value)
{
    minTime = value;
    if (minTime > maxTime) {
        maxTime = minTime;
        ui->timeMaxSlider->setValue(maxTime);
        ui->timeMaxSpinBox->setValue(maxTime);
    }
    ui->timeMinSlider->blockSignals(true);
    ui->timeMinSlider->setValue(minTime);
    ui->timeMinSlider->blockSignals(false);
    updateTimeLabels();
    performSearch();
}

void SearchDialog::on_timeMaxSpinBox_valueChanged(int value)
{
    maxTime = value;
    if (maxTime < minTime) {
        minTime = maxTime;
        ui->timeMinSlider->setValue(minTime);
        ui->timeMinSpinBox->setValue(minTime);
    }
    ui->timeMaxSlider->blockSignals(true);
    ui->timeMaxSlider->setValue(maxTime);
    ui->timeMaxSlider->blockSignals(false);
    updateTimeLabels();
    performSearch();
}

void SearchDialog::on_recipeItemDoubleClicked(QListWidgetItem *item)
{
    int recipeId = item->data(Qt::UserRole).toInt();
    if (recipeId > 0) {
        RecipeViewDialog dialog(recipeId, currentUserId, this);
        dialog.exec();
        // Обновляем результаты после просмотра/редактирования
        loadResults();
    }
}

void SearchDialog::performSearch()
{
    loadResults();
}

void SearchDialog::loadCategories()
{
    ui->categoriesComboBox->clear();
    ui->categoriesComboBox->addItem("Категории", QVariant());
    
    QSqlQuery query("SELECT id, name FROM categories ORDER BY name");
    while (query.next()) {
        int categoryId = query.value(0).toInt();
        QString categoryName = query.value(1).toString();
        ui->categoriesComboBox->addItem(categoryName, categoryId);
    }
    
    // Устанавливаем на placeholder
    ui->categoriesComboBox->setCurrentIndex(0);
}

void SearchDialog::loadIngredients()
{
    ui->ingredientsComboBox->clear();
    
    // Загружаем все уникальные ингредиенты
    QSqlQuery query("SELECT DISTINCT name FROM ingredients ORDER BY name");
    QStringList allIngredients;
    while (query.next()) {
        allIngredients.append(query.value(0).toString());
    }
    
    // Добавляем ингредиенты в ComboBox для выпадающего списка
    ui->ingredientsComboBox->addItems(allIngredients);
    
    // Настраиваем автодополнение
    QCompleter *completer = new QCompleter(allIngredients, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->ingredientsComboBox->setCompleter(completer);
    
    // Устанавливаем placeholder текст
    ui->ingredientsComboBox->lineEdit()->setPlaceholderText("Введите название ингредиентов...");
    ui->ingredientsComboBox->setEditText("");
}

void SearchDialog::updateSelectedFilters()
{
    // Очищаем старые чипсы
    QLayoutItem *item;
    while ((item = ui->selectedFiltersLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    
    // Добавляем чипс категории
    if (!selectedCategoryIds.isEmpty()) {
        QSqlQuery query;
        query.prepare("SELECT name FROM categories WHERE id = ?");
        query.addBindValue(*selectedCategoryIds.begin());
        if (query.exec() && query.next()) {
            QString categoryName = query.value(0).toString();
            addFilterChip("Категория", categoryName, "category");
        }
    }
    
    // Добавляем чипсы ингредиентов
    for (const QString &ingredient : selectedIngredients) {
        addFilterChip("Ингредиент", ingredient, "ingredient_" + ingredient);
    }
    
    // Добавляем чипс времени, если оно изменено
    if (minTime > 5 || maxTime < 300) {
        QString timeText = QString("%1-%2 мин").arg(minTime).arg(maxTime);
        addFilterChip("Время", timeText, "time");
    }
}

void SearchDialog::addFilterChip(const QString &label, const QString &value, const QString &type)
{
    QLabel *chip = new QLabel(QString("%1: %2 ✕").arg(label).arg(value));
    chip->setProperty("filterType", type);
    chip->setStyleSheet("background-color: #ff3333; color: white; border-radius: 15px; padding: 6px 12px; font-size: 13px;");
    chip->setCursor(Qt::PointingHandCursor);
    chip->installEventFilter(this);
    
    ui->selectedFiltersLayout->addWidget(chip);
}

void SearchDialog::removeFilterChip(const QString &type)
{
    if (type == "category") {
        selectedCategoryIds.clear();
        ui->categoriesComboBox->setCurrentIndex(0);
    } else if (type == "time") {
        minTime = 5;
        maxTime = 300;
        ui->timeMinSlider->setValue(5);
        ui->timeMaxSlider->setValue(300);
        ui->timeMinSpinBox->setValue(5);
        ui->timeMaxSpinBox->setValue(300);
        updateTimeLabels();
    } else if (type.startsWith("ingredient_")) {
        QString ingredient = type.mid(11); // Убираем "ingredient_"
        selectedIngredients.remove(ingredient);
    }
    
    // Удаляем виджет чипса
    for (int i = 0; i < ui->selectedFiltersLayout->count(); ++i) {
        QLayoutItem *item = ui->selectedFiltersLayout->itemAt(i);
        if (item && item->widget()) {
            QLabel *chip = qobject_cast<QLabel*>(item->widget());
            if (chip && chip->property("filterType").toString() == type) {
                ui->selectedFiltersLayout->removeItem(item);
                delete chip;
                delete item;
                break;
            }
        }
    }
    
    updateSelectedFilters();
    performSearch();
}

void SearchDialog::updateTimeLabels()
{
    ui->timeMinLabel->setText(QString("От: %1 мин").arg(minTime));
    ui->timeMaxLabel->setText(QString("До: %1 мин").arg(maxTime));
}

void SearchDialog::updateFilterButtons()
{
    // Обновляем стиль кнопки времени в зависимости от того, активен ли фильтр
    QString selectedStyle = "background-color: #ff3333; color: white; border: 2px solid #ff3333; border-radius: 20px; padding: 8px 16px; font-size: 14px; text-align: left;";
    QString normalStyle = "background-color: #e9ecef; color: #212529; border: 2px solid #ced4da; border-radius: 20px; padding: 8px 16px; font-size: 14px; text-align: left;";
    
    ui->timeFilterButton->setStyleSheet(
        (minTime > 5 || maxTime < 300) ? selectedStyle : normalStyle
    );
}

QList<int> SearchDialog::getRelevantRecipeIds()
{
    // Базовый запрос в зависимости от режима поиска
    QString baseQuery;
    if (searchMode == SearchFavorites) {
        baseQuery = "SELECT DISTINCT r.id, r.name, r.time, r.photo_path, r.category_id "
                    "FROM recipes r "
                    "INNER JOIN favourites f ON r.id = f.recipe_id "
                    "WHERE f.user_id = ?";
    } else {
        baseQuery = "SELECT id, name, time, photo_path, category_id FROM recipes WHERE user_id = ?";
    }
    
    QSqlQuery query;
    query.prepare(baseQuery);
    query.addBindValue(currentUserId);
    query.exec();
    
    // Собираем данные рецептов
    QList<RecipeFilterData> recipes;
    while (query.next()) {
        int recipeId = query.value(0).toInt();
        QString name = query.value(1).toString();
        int time = query.value(2).toInt();
        int categoryId = query.value(4).toInt();
        
        RecipeFilterData recipeData(recipeId, name, time, categoryId);
        
        // Загружаем ингредиенты для рецепта
        QSqlQuery ingQuery;
        ingQuery.prepare("SELECT name FROM ingredients WHERE recipe_id = ?");
        ingQuery.addBindValue(recipeId);
        ingQuery.exec();
        
        while (ingQuery.next()) {
            recipeData.ingredients.insert(ingQuery.value(0).toString());
        }
        
        recipes.append(recipeData);
    }
    
    // Используем паттерн Strategy для фильтрации
    FilterContext filterContext;
    
    // Добавляем стратегии в зависимости от активных фильтров
    if (!searchText.isEmpty()) {
        filterContext.addStrategy(new NameFilterStrategy(searchText));
    }
    
    if (!selectedCategoryIds.isEmpty()) {
        filterContext.addStrategy(new CategoryFilterStrategy(selectedCategoryIds));
    }
    
    if (minTime > 5 || maxTime < 300) {
        filterContext.addStrategy(new TimeFilterStrategy(minTime, maxTime));
    }
    
    if (!selectedIngredients.isEmpty()) {
        filterContext.addStrategy(new IngredientFilterStrategy(selectedIngredients));
    }
    
    // Применяем фильтры
    QList<int> recipeIds = filterContext.filterRecipes(recipes);
    
    return recipeIds;
}

void SearchDialog::loadResults()
{
    ui->resultsListWidget->clear();
    
    QList<int> recipeIds = getRelevantRecipeIds();
    
    if (recipeIds.isEmpty()) {
        ui->resultsListWidget->addItem("Рецепты не найдены");
        return;
    }
    
    for (int recipeId : recipeIds) {
        QSqlQuery query;
        query.prepare("SELECT name, time, photo_path FROM recipes WHERE id = ?");
        query.addBindValue(recipeId);
        query.exec();
        
        if (query.next()) {
            QString name = query.value(0).toString();
            int time = query.value(1).toInt();
            QString photoPath = query.value(2).toString();
            
            // Проверяем, есть ли рецепт в избранном
            QSqlQuery favQuery;
            favQuery.prepare("SELECT COUNT(*) FROM favourites WHERE user_id = ? AND recipe_id = ?");
            favQuery.addBindValue(currentUserId);
            favQuery.addBindValue(recipeId);
            favQuery.exec();
            favQuery.next();
            bool isFavourite = favQuery.value(0).toInt() > 0;
            
            showRecipeCard(recipeId, name, time, photoPath, isFavourite);
        }
    }
}

void SearchDialog::showRecipeCard(int recipeId, const QString &name, int time, const QString &photoPath, bool isFavourite)
{
    QListWidgetItem *item = new QListWidgetItem();
    item->setData(Qt::UserRole, recipeId);
    
    QWidget *card = new QWidget();
    card->setStyleSheet("background-color: white; border-radius: 16px;");
    card->setMinimumWidth(600);
    card->setMinimumHeight(120);
    
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(10);
    shadow->setColor(QColor(0, 0, 0, 30));
    shadow->setOffset(0, 2);
    card->setGraphicsEffect(shadow);
    
    QHBoxLayout *layout = new QHBoxLayout(card);
    layout->setContentsMargins(16, 16, 16, 16);
    layout->setSpacing(16);
    
    // Фото
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
    
    // Текст
    QVBoxLayout *textLayout = new QVBoxLayout();
    textLayout->setSpacing(8);
    textLayout->setContentsMargins(0, 0, 0, 0);
    
    QHBoxLayout *nameLayout = new QHBoxLayout();
    nameLayout->setContentsMargins(0, 0, 0, 0);
    nameLayout->setSpacing(8);
    
    QLabel *nameLabel = new QLabel(name);
    nameLabel->setStyleSheet("font-weight: bold; font-size: 18px; color: #212529;");
    nameLabel->setWordWrap(true);
    nameLayout->addWidget(nameLabel);
    nameLayout->addStretch();
    
    // Сердечко избранного - используем иконку для избранных, эмодзи для не избранных (как в MainWindow)
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
    
    ui->resultsListWidget->addItem(item);
    ui->resultsListWidget->setItemWidget(item, card);
}

void SearchDialog::toggleFavourite(QLabel *heartLabel, int recipeId)
{
    bool isFavourite = heartLabel->property("isFavourite").toBool();
    
    QSqlQuery query;
    if (isFavourite) {
        query.prepare("DELETE FROM favourites WHERE user_id = ? AND recipe_id = ?");
    } else {
        query.prepare("INSERT OR IGNORE INTO favourites (user_id, recipe_id) VALUES (?, ?)");
    }
    query.addBindValue(currentUserId);
    query.addBindValue(recipeId);
    query.exec();
    
    // Обновляем иконку (как в MainWindow)
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
}
