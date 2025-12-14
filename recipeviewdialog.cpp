#include "recipeviewdialog.h"
#include "ui_recipeviewdialog.h"
#include "addrecipedialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFile>
#include <QPixmap>
#include <QFileInfo>
#include <QVBoxLayout>
#include <QLabel>

RecipeViewDialog::RecipeViewDialog(int recipeId, int userId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RecipeViewDialog)
    , currentRecipeId(recipeId)
    , currentUserId(userId)
{
    ui->setupUi(this);
    loadRecipeData();
    loadIngredients();
    loadSteps();
}

RecipeViewDialog::~RecipeViewDialog()
{
    delete ui;
}

void RecipeViewDialog::loadRecipeData()
{
    QSqlQuery query;
    query.prepare("SELECT name, time, photo_path, category_id FROM recipes WHERE id = ? AND user_id = ?");
    query.addBindValue(currentRecipeId);
    query.addBindValue(currentUserId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Ошибка", "Рецепт не найден");
        reject();
        return;
    }
    
    QString name = query.value(0).toString();
    int time = query.value(1).toInt();
    QString photoPath = query.value(2).toString();
    int categoryId = query.value(3).toInt();
    
    // Загружаем название категории
    QSqlQuery catQuery;
    catQuery.prepare("SELECT name FROM categories WHERE id = ?");
    catQuery.addBindValue(categoryId);
    if (catQuery.exec() && catQuery.next()) {
        QString categoryName = catQuery.value(0).toString();
        ui->categoryLabel->setText("Категория: " + categoryName);
    }
    
    ui->nameLabel->setText(name);
    ui->timeLabel->setText("Время приготовления: " + QString::number(time) + " минут");
    
    // Загружаем фото
    if (!photoPath.isEmpty() && QFile::exists(photoPath)) {
        QPixmap pix(photoPath);
        ui->photoLabel->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        ui->photoLabel->setText("📷");
        ui->photoLabel->setStyleSheet("border: 2px dashed #ced4da; border-radius: 20px; background-color: #f8f9fa; font-size: 60px;");
    }
}

void RecipeViewDialog::loadIngredients()
{
    ui->ingredientsListWidget->clear();
    
    QSqlQuery query;
    query.prepare("SELECT name, quantity FROM ingredients WHERE recipe_id = ? ORDER BY id");
    query.addBindValue(currentRecipeId);
    query.exec();
    
    while (query.next()) {
        QString name = query.value(0).toString();
        QString quantity = query.value(1).toString();
        
        QString itemText = name;
        if (!quantity.isEmpty()) {
            itemText += " - " + quantity;
        }
        
        ui->ingredientsListWidget->addItem(itemText);
    }
}

void RecipeViewDialog::loadSteps()
{
    ui->stepsListWidget->clear();
    
    QSqlQuery query;
    query.prepare("SELECT step_number, description FROM steps WHERE recipe_id = ? ORDER BY step_number");
    query.addBindValue(currentRecipeId);
    query.exec();
    
    while (query.next()) {
        int stepNumber = query.value(0).toInt();
        QString description = query.value(1).toString();
        
        // Создаем кастомный виджет для шага
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(0, 100));
        
        QWidget *stepWidget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(stepWidget);
        layout->setContentsMargins(12, 12, 12, 12);
        layout->setSpacing(8);
        
        // Заголовок шага (красный)
        QLabel *stepHeader = new QLabel(QString("ШАГ %1:").arg(stepNumber));
        stepHeader->setStyleSheet("font-weight: bold; font-size: 16px; color: #ff3333;");
        layout->addWidget(stepHeader);
        
        // Описание шага
        QLabel *stepDescription = new QLabel(description);
        stepDescription->setStyleSheet("font-size: 14px; color: #212529;");
        stepDescription->setWordWrap(true);
        layout->addWidget(stepDescription);
        
        stepWidget->setLayout(layout);
        ui->stepsListWidget->addItem(item);
        ui->stepsListWidget->setItemWidget(item, stepWidget);
    }
}

void RecipeViewDialog::on_backButton_clicked()
{
    reject();
}

void RecipeViewDialog::on_deleteButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение", 
        "Вы уверены, что хотите удалить этот рецепт?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM recipes WHERE id = ? AND user_id = ?");
        query.addBindValue(currentRecipeId);
        query.addBindValue(currentUserId);
        
        if (query.exec()) {
            QMessageBox::information(this, "Успех", "Рецепт удален");
            accept(); // Закрываем диалог с результатом Accepted
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить рецепт: " + query.lastError().text());
        }
    }
}

void RecipeViewDialog::on_editButton_clicked()
{
    AddRecipeDialog dialog(currentUserId, currentRecipeId, this);
    if (dialog.exec() == QDialog::Accepted) {
        // Обновляем данные после редактирования
        loadRecipeData();
        loadIngredients();
        loadSteps();
    }
}

