#include "recipefactory.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>
#include <QDebug>

StandardRecipeFactory RecipeFactoryManager::standardFactory;

StandardRecipeFactory::StandardRecipeFactory() {
}

QString StandardRecipeFactory::copyPhoto(const QString& photoPath, int userId) {
    if (photoPath.isEmpty() || !QFile::exists(photoPath)) {
        return "";
    }
    
    QDir dir;
    if (!dir.exists("photos")) {
        dir.mkpath("photos");
    }
    
    QFileInfo fileInfo(photoPath);
    QString newFileName = QString("photos/recipe_%1_%2.%3")
        .arg(userId)
        .arg(QDateTime::currentDateTime().toSecsSinceEpoch())
        .arg(fileInfo.suffix());
    
    if (QFile::copy(photoPath, newFileName)) {
        return newFileName;
    }
    
    return photoPath;
}

int StandardRecipeFactory::createRecipe(int userId, const RecipeTemplate& template_) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database is not open";
        return -1;
    }
    
    db.transaction();
    
    QString savedPhotoPath = copyPhoto(template_.photoPath, userId);
    
    QSqlQuery query;
    query.prepare("INSERT INTO recipes (user_id, name, photo_path, time, category_id) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(userId);
    query.addBindValue(template_.name);
    query.addBindValue(savedPhotoPath);
    query.addBindValue(template_.time);
    query.addBindValue(template_.categoryId);
    
    if (!query.exec()) {
        db.rollback();
        qDebug() << "Failed to create recipe:" << query.lastError().text();
        return -1;
    }
    
    int recipeId = query.lastInsertId().toInt();
    
    if (!saveIngredients(recipeId, template_.ingredients)) {
        db.rollback();
        return -1;
    }
    
    if (!saveSteps(recipeId, template_.steps)) {
        db.rollback();
        return -1;
    }
    
    if (!db.commit()) {
        db.rollback();
        return -1;
    }
    
    return recipeId;
}

bool StandardRecipeFactory::updateRecipe(int recipeId, int userId, const RecipeTemplate& template_) {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return false;
    }
    
    db.transaction();
    
    // Проверяем, принадлежит ли рецепт пользователю
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT photo_path FROM recipes WHERE id = ? AND user_id = ?");
    checkQuery.addBindValue(recipeId);
    checkQuery.addBindValue(userId);
    
    QString oldPhotoPath;
    if (!checkQuery.exec() || !checkQuery.next()) {
        db.rollback();
        return false;
    }
    oldPhotoPath = checkQuery.value(0).toString();
    
    // Обрабатываем фото
    QString savedPhotoPath = oldPhotoPath;
    if (!template_.photoPath.isEmpty() && template_.photoPath != oldPhotoPath && QFile::exists(template_.photoPath)) {
        savedPhotoPath = copyPhoto(template_.photoPath, userId);
    }
    
    // Обновляем рецепт
    QSqlQuery query;
    query.prepare("UPDATE recipes SET name = ?, photo_path = ?, time = ?, category_id = ? WHERE id = ? AND user_id = ?");
    query.addBindValue(template_.name);
    query.addBindValue(savedPhotoPath);
    query.addBindValue(template_.time);
    query.addBindValue(template_.categoryId);
    query.addBindValue(recipeId);
    query.addBindValue(userId);
    
    if (!query.exec()) {
        db.rollback();
        return false;
    }
    
    // Удаляем старые ингредиенты и шаги
    query.prepare("DELETE FROM ingredients WHERE recipe_id = ?");
    query.addBindValue(recipeId);
    query.exec();
    
    query.prepare("DELETE FROM steps WHERE recipe_id = ?");
    query.addBindValue(recipeId);
    query.exec();
    
    if (!saveIngredients(recipeId, template_.ingredients)) {
        db.rollback();
        return false;
    }
    
    if (!saveSteps(recipeId, template_.steps)) {
        db.rollback();
        return false;
    }
    
    if (!db.commit()) {
        db.rollback();
        return false;
    }
    
    return true;
}

bool StandardRecipeFactory::saveIngredients(int recipeId, const QList<IngredientData>& ingredients) {
    QSqlQuery query;
    for (const IngredientData& ing : ingredients) {
        query.prepare("INSERT INTO ingredients (recipe_id, name, quantity) VALUES (?, ?, ?)");
        query.addBindValue(recipeId);
        query.addBindValue(ing.name);
        query.addBindValue(ing.quantity.isEmpty() ? "по вкусу" : ing.quantity);
        
        if (!query.exec()) {
            qDebug() << "Failed to save ingredient:" << query.lastError().text();
            return false;
        }
    }
    return true;
}

bool StandardRecipeFactory::saveSteps(int recipeId, const QList<StepData>& steps) {
    QSqlQuery query;
    for (const StepData& step : steps) {
        query.prepare("INSERT INTO steps (recipe_id, step_number, description) VALUES (?, ?, ?)");
        query.addBindValue(recipeId);
        query.addBindValue(step.stepNumber);
        query.addBindValue(step.description);
        
        if (!query.exec()) {
            qDebug() << "Failed to save step:" << query.lastError().text();
            return false;
        }
    }
    return true;
}

RecipeFactory* RecipeFactoryManager::getFactory(const QString& type) {
    if (type == "standard" || type.isEmpty()) {
        return &standardFactory;
    }
    return &standardFactory; // По умолчанию стандартная фабрика
}


