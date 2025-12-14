#include "addrecipedialog.h"
#include "ui_addrecipedialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPixmap>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>

AddRecipeDialog::AddRecipeDialog(int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecipeDialog),
    currentUserId(userId),
    currentRecipeId(0),
    photoPath(""),
    currentStepNumber(1),
    photoDialogOpen(false)
{
    ui->setupUi(this);
    loadCategories();

    // Инициализация единиц измерения
    ui->ingredientUnitComboBox->addItems({"ед.", "г", "кг", "мл", "л", "шт", "ч.л.", "ст.л.", "по вкусу"});
    ui->ingredientUnitComboBox->setCurrentIndex(0);

    // Автоматическая нумерация шагов
    updateCurrentStepLabel();

    // Удаление ингредиентов и шагов двойным кликом
    connect(ui->ingredientsListWidget, &QListWidget::itemDoubleClicked, this, &AddRecipeDialog::removeIngredient);
    connect(ui->stepsListWidget, &QListWidget::itemDoubleClicked, this, &AddRecipeDialog::removeStep);
    
    // Выбор фото
    //connect(ui->addPhotoButton, &QPushButton::clicked, this, &AddRecipeDialog::on_addPhotoButton_clicked);
    
    // Делаем photoLabel кликабельным
    ui->photoLabel->setCursor(Qt::PointingHandCursor);
    ui->photoLabel->installEventFilter(this);
    
    // Устанавливаем начальное изображение для фото
    updatePhotoDisplay();
}

AddRecipeDialog::AddRecipeDialog(int userId, int recipeId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecipeDialog),
    currentUserId(userId),
    currentRecipeId(recipeId),
    photoPath(""),
    currentStepNumber(1)
{
    ui->setupUi(this);
    loadCategories();

    // Инициализация единиц измерения
    ui->ingredientUnitComboBox->addItems({"ед.", "г", "кг", "мл", "л", "шт", "ч.л.", "ст.л.", "по вкусу"});
    ui->ingredientUnitComboBox->setCurrentIndex(0);

    // Загружаем данные рецепта для редактирования
    loadRecipeData();

    // Удаление ингредиентов и шагов двойным кликом
    connect(ui->ingredientsListWidget, &QListWidget::itemDoubleClicked, this, &AddRecipeDialog::removeIngredient);
    connect(ui->stepsListWidget, &QListWidget::itemDoubleClicked, this, &AddRecipeDialog::removeStep);
    
    // Выбор фото
    connect(ui->addPhotoButton, &QPushButton::clicked, this, &AddRecipeDialog::on_addPhotoButton_clicked);
    
    // Делаем photoLabel кликабельным
    ui->photoLabel->setCursor(Qt::PointingHandCursor);
    ui->photoLabel->installEventFilter(this);
    
    // Устанавливаем начальное изображение для фото
    updatePhotoDisplay();
    
    // Меняем текст кнопки на "Сохранить"
    ui->saveButton->setText("Сохранить");
}

AddRecipeDialog::~AddRecipeDialog()
{
    delete ui;
}

bool AddRecipeDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        // Обрабатываем клик только по photoLabel
        if (obj == ui->photoLabel) {
            on_addPhotoButton_clicked();
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

void AddRecipeDialog::loadCategories()
{
    ui->categoryComboBox->clear();
    ui->categoryComboBox->addItem("Выберите из списка...", QVariant()); // Пустой элемент для placeholder
    QSqlQuery query("SELECT name FROM categories ORDER BY name");
    while (query.next()) {
        ui->categoryComboBox->addItem(query.value(0).toString());
    }
    ui->categoryComboBox->setCurrentIndex(0); // Устанавливаем на placeholder
}

void AddRecipeDialog::updateCurrentStepLabel()
{
    ui->currentStepLabel->setText(QString("ШАГ %1:").arg(currentStepNumber));
}

// void AddRecipeDialog::on_addPhotoButton_clicked()
// {
//     // Блокируем повторное открытие диалога, если он уже открыт
//     static bool dialogOpen = false;
//     if (dialogOpen) {
//         return;
//     }
    
//     dialogOpen = true;
//     QString fileName = QFileDialog::getOpenFileName(this,
//         tr("Выберите фото"), "",
//         tr("Изображения (*.png *.jpg *.jpeg *.bmp);;Все файлы (*)"));
//     dialogOpen = false;
    
//     if (!fileName.isEmpty()) {
//         photoPath = fileName;
//         updatePhotoDisplay();
//     }
// }

void AddRecipeDialog::on_addPhotoButton_clicked()
{
    // Предотвращаем повторное открытие диалога
    if (photoDialogOpen) {
        return;
    }

    photoDialogOpen = true;

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Выберите фото"), "",
        tr("Изображения (*.png *.jpg *.jpeg *.bmp);;Все файлы (*)"));

    photoDialogOpen = false;

    if (!fileName.isEmpty()) {
        photoPath = fileName;
        updatePhotoDisplay();
    }
}

void AddRecipeDialog::updatePhotoDisplay()
{
    if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
        QPixmap pix(photoPath);
        ui->photoLabel->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        ui->photoLabel->setStyleSheet("border: 2px solid #ced4da; border-radius: 20px;");
    } else {
        // Показываем иконку плюса на фото
        ui->photoLabel->setText("📷");
        ui->photoLabel->setStyleSheet("border: 2px dashed #ced4da; border-radius: 20px; background-color: #f8f9fa; font-size: 60px;");
    }
}

void AddRecipeDialog::loadRecipeData()
{
    if (currentRecipeId <= 0) {
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT name, time, photo_path, category_id FROM recipes WHERE id = ? AND user_id = ?");
    query.addBindValue(currentRecipeId);
    query.addBindValue(currentUserId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Ошибка", "Рецепт не найден");
        return;
    }
    
    QString name = query.value(0).toString();
    int time = query.value(1).toInt();
    QString savedPhotoPath = query.value(2).toString();
    int categoryId = query.value(3).toInt();
    
    // Заполняем поля
    ui->nameLineEdit->setText(name);
    ui->timeSpinBox->setValue(time);
    
    // Устанавливаем категорию
    QSqlQuery catQuery;
    catQuery.prepare("SELECT name FROM categories WHERE id = ?");
    catQuery.addBindValue(categoryId);
    if (catQuery.exec() && catQuery.next()) {
        QString categoryName = catQuery.value(0).toString();
        int index = ui->categoryComboBox->findText(categoryName);
        if (index >= 0) {
            ui->categoryComboBox->setCurrentIndex(index);
        }
    }
    
    // Загружаем фото
    if (!savedPhotoPath.isEmpty()) {
        photoPath = savedPhotoPath;
    }
    
    // Загружаем ингредиенты
    QSqlQuery ingQuery;
    ingQuery.prepare("SELECT name, quantity FROM ingredients WHERE recipe_id = ? ORDER BY id");
    ingQuery.addBindValue(currentRecipeId);
    ingQuery.exec();
    
    while (ingQuery.next()) {
        QString name = ingQuery.value(0).toString();
        QString quantity = ingQuery.value(1).toString();
        
        QString itemText = name;
        if (!quantity.isEmpty() && quantity != "по вкусу") {
            itemText += " — " + quantity;
        }
        
        ui->ingredientsListWidget->addItem(itemText);
    }
    
    // Загружаем шаги
    QSqlQuery stepsQuery;
    stepsQuery.prepare("SELECT step_number, description FROM steps WHERE recipe_id = ? ORDER BY step_number");
    stepsQuery.addBindValue(currentRecipeId);
    stepsQuery.exec();
    
    while (stepsQuery.next()) {
        QString desc = stepsQuery.value(1).toString();
        ui->stepsListWidget->addItem(QString("%1. %2").arg(currentStepNumber).arg(desc));
        currentStepNumber++;
    }
    updateCurrentStepLabel();
}

void AddRecipeDialog::on_backButton_clicked()
{
    reject();
}

void AddRecipeDialog::on_addIngredientButton_clicked()
{
    QString name = ui->ingredientNameEdit->text().trimmed();
    int quantity = ui->ingredientQuantitySpinBox->value();
    QString unit = ui->ingredientUnitComboBox->currentText();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название ингредиента");
        return;
    }

    QString itemText = name;
    if (quantity > 0) {
        itemText += QString(" — %1 %2").arg(quantity).arg(unit);
    } else if (!unit.isEmpty() && unit != "по вкусу" && unit != "ед.") {
        itemText += QString(" — %1").arg(unit);
    }

    ui->ingredientsListWidget->addItem(itemText);

    ui->ingredientNameEdit->clear();
    ui->ingredientQuantitySpinBox->setValue(0);
    ui->ingredientUnitComboBox->setCurrentIndex(0);
}

void AddRecipeDialog::removeIngredient(QListWidgetItem *item)
{
    delete ui->ingredientsListWidget->takeItem(ui->ingredientsListWidget->row(item));
}

void AddRecipeDialog::on_addStepButton_clicked()
{
    QString desc = ui->stepDescriptionEdit->toPlainText().trimmed();
    if (desc.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите описание шага");
        return;
    }

    QString itemText = QString("%1. %2").arg(currentStepNumber).arg(desc);
    ui->stepsListWidget->addItem(itemText);

    currentStepNumber++;
    updateCurrentStepLabel();
    ui->stepDescriptionEdit->clear();
}

void AddRecipeDialog::removeStep(QListWidgetItem *item)
{
    int row = ui->stepsListWidget->row(item);
    delete ui->stepsListWidget->takeItem(row);

    // Перенумеровываем оставшиеся шаги
    for (int i = row; i < ui->stepsListWidget->count(); ++i) {
        QString text = ui->stepsListWidget->item(i)->text();
        text = text.section(". ", 1);
        ui->stepsListWidget->item(i)->setText(QString("%1. %2").arg(i + 1).arg(text));
    }
    currentStepNumber = ui->stepsListWidget->count() + 1;
    updateCurrentStepLabel();
}

void AddRecipeDialog::on_saveButton_clicked()
{
    QString name = ui->nameLineEdit->text().trimmed();
    int time = ui->timeSpinBox->value();
    QString categoryName = ui->categoryComboBox->currentText();

    // Валидация обязательных полей
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название блюда");
        ui->nameLineEdit->setFocus();
        return;
    }
    
    if (categoryName.isEmpty() || categoryName == "Выберите из списка..." || ui->categoryComboBox->currentIndex() <= 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите категорию блюда");
        ui->categoryComboBox->setFocus();
        return;
    }
    
    // Получаем ID категории по имени
    QSqlQuery catQuery;
    catQuery.prepare("SELECT id FROM categories WHERE name = ?");
    catQuery.addBindValue(categoryName);
    if (!catQuery.exec() || !catQuery.next()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось найти категорию");
        return;
    }
    int categoryId = catQuery.value(0).toInt();

    // Обрабатываем фото
    QString savedPhotoPath = "";
    if (currentRecipeId > 0) {
        // При редактировании: если фото не изменилось, используем старое
        QSqlQuery oldPhotoQuery;
        oldPhotoQuery.prepare("SELECT photo_path FROM recipes WHERE id = ?");
        oldPhotoQuery.addBindValue(currentRecipeId);
        if (oldPhotoQuery.exec() && oldPhotoQuery.next()) {
            QString oldPhotoPath = oldPhotoQuery.value(0).toString();
            // Проверяем, изменилось ли фото
            if (!photoPath.isEmpty() && photoPath != oldPhotoPath && QFile::exists(photoPath)) {
                // Фото изменилось - копируем новое
                QDir dir;
                if (!dir.exists("photos")) {
                    dir.mkpath("photos");
                }
                QFileInfo fileInfo(photoPath);
                QString newFileName = QString("photos/recipe_%1_%2.%3")
                    .arg(currentUserId)
                    .arg(QDateTime::currentDateTime().toSecsSinceEpoch())
                    .arg(fileInfo.suffix());
                
                if (QFile::copy(photoPath, newFileName)) {
                    savedPhotoPath = newFileName;
                } else {
                    savedPhotoPath = photoPath;
                }
            } else {
                // Фото не изменилось - используем старое
                savedPhotoPath = oldPhotoPath;
            }
        }
    } else {
        // Новый рецепт - копируем фото
        if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
            QDir dir;
            if (!dir.exists("photos")) {
                dir.mkpath("photos");
            }
            QFileInfo fileInfo(photoPath);
            QString newFileName = QString("photos/recipe_%1_%2.%3")
                .arg(currentUserId)
                .arg(QDateTime::currentDateTime().toSecsSinceEpoch())
                .arg(fileInfo.suffix());
            
            if (QFile::copy(photoPath, newFileName)) {
                savedPhotoPath = newFileName;
            } else {
                savedPhotoPath = photoPath;
            }
        }
    }

    // Начинаем транзакцию для целостности данных
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    QSqlQuery query;
    int recipeId = currentRecipeId;
    
    if (currentRecipeId > 0) {
        // Редактирование существующего рецепта
        query.prepare("UPDATE recipes SET name = ?, photo_path = ?, time = ?, category_id = ? WHERE id = ? AND user_id = ?");
        query.addBindValue(name);
        query.addBindValue(savedPhotoPath);
        query.addBindValue(time);
        query.addBindValue(categoryId);
        query.addBindValue(currentRecipeId);
        query.addBindValue(currentUserId);
        
        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "Ошибка", "Не удалось обновить рецепт: " + query.lastError().text());
            return;
        }
        
        // Удаляем старые ингредиенты и шаги
        query.prepare("DELETE FROM ingredients WHERE recipe_id = ?");
        query.addBindValue(currentRecipeId);
        query.exec();
        
        query.prepare("DELETE FROM steps WHERE recipe_id = ?");
        query.addBindValue(currentRecipeId);
        query.exec();
    } else {
        // Добавление нового рецепта
        query.prepare("INSERT INTO recipes (user_id, name, photo_path, time, category_id) VALUES (?, ?, ?, ?, ?)");
        query.addBindValue(currentUserId);
        query.addBindValue(name);
        query.addBindValue(savedPhotoPath);
        query.addBindValue(time);
        query.addBindValue(categoryId);
        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить рецепт: " + query.lastError().text());
            return;
        }
        
        recipeId = query.lastInsertId().toInt();
    }

    // Сохраняем ингредиенты
    for (int i = 0; i < ui->ingredientsListWidget->count(); ++i) {
        QString text = ui->ingredientsListWidget->item(i)->text();
        QString ingName = text.section(" — ", 0, 0);
        QString quantity = text.section(" — ", 1);
        if (quantity.isEmpty()) {
            quantity = "по вкусу";
        }

        query.prepare("INSERT INTO ingredients (recipe_id, name, quantity) VALUES (?, ?, ?)");
        query.addBindValue(recipeId);
        query.addBindValue(ingName);
        query.addBindValue(quantity);
        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить ингредиент: " + query.lastError().text());
            return;
        }
    }

    // Сохраняем шаги
    for (int i = 0; i < ui->stepsListWidget->count(); ++i) {
        QString text = ui->stepsListWidget->item(i)->text();
        QString desc = text.section(". ", 1);

        query.prepare("INSERT INTO steps (recipe_id, step_number, description) VALUES (?, ?, ?)");
        query.addBindValue(recipeId);
        query.addBindValue(i + 1);
        query.addBindValue(desc);
        if (!query.exec()) {
            db.rollback();
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить шаг: " + query.lastError().text());
            return;
        }
    }

    // Коммитим транзакцию
    if (!db.commit()) {
        db.rollback();
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные в базу");
        return;
    }

    accept(); // Успешно закрываем диалог
}
