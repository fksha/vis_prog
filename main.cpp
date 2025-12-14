// main.cpp
#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

bool createDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("recipes.db");  // Файл базы будет создан в папке с проектом

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть базу данных:\n" + db.lastError().text());
        return false;
    }

    QSqlQuery query;
    
    // Включаем поддержку внешних ключей в SQLite
    query.exec("PRAGMA foreign_keys = ON");

    // Таблица пользователей
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE NOT NULL, "
               "password TEXT NOT NULL, "
               "first_name TEXT, "
               "last_name TEXT, "
               "position TEXT, "
               "photo_path TEXT)");
    
    // Добавляем новые колонки, если их еще нет (для существующих баз данных)
    // Игнорируем ошибки, если колонки уже существуют
    QSqlQuery alterQuery;
    alterQuery.exec("ALTER TABLE users ADD COLUMN first_name TEXT");
    alterQuery.exec("ALTER TABLE users ADD COLUMN last_name TEXT");
    alterQuery.exec("ALTER TABLE users ADD COLUMN position TEXT");
    alterQuery.exec("ALTER TABLE users ADD COLUMN photo_path TEXT");

    // Таблица категорий (супы, салаты и т.д.)
    query.exec("CREATE TABLE IF NOT EXISTS categories ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT UNIQUE NOT NULL)");

    // Таблица рецептов
    query.exec("CREATE TABLE IF NOT EXISTS recipes ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "user_id INTEGER NOT NULL, "
               "name TEXT NOT NULL, "
               "photo_path TEXT, "
               "time INTEGER NOT NULL, "       // время приготовления в минутах
               "category_id INTEGER NOT NULL, "
               "FOREIGN KEY(user_id) REFERENCES users(id), "
               "FOREIGN KEY(category_id) REFERENCES categories(id))");

    // Ингредиенты
    query.exec("CREATE TABLE IF NOT EXISTS ingredients ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "recipe_id INTEGER NOT NULL, "
               "name TEXT NOT NULL, "
               "quantity TEXT, "
               "FOREIGN KEY(recipe_id) REFERENCES recipes(id) ON DELETE CASCADE)");

    // Шаги приготовления
    query.exec("CREATE TABLE IF NOT EXISTS steps ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "recipe_id INTEGER NOT NULL, "
               "step_number INTEGER NOT NULL, "
               "description TEXT NOT NULL, "
               "FOREIGN KEY(recipe_id) REFERENCES recipes(id) ON DELETE CASCADE)");

    // Избранное
    query.exec("CREATE TABLE IF NOT EXISTS favourites ("
               "user_id INTEGER NOT NULL, "
               "recipe_id INTEGER NOT NULL, "
               "PRIMARY KEY(user_id, recipe_id), "
               "FOREIGN KEY(user_id) REFERENCES users(id), "
               "FOREIGN KEY(recipe_id) REFERENCES recipes(id) ON DELETE CASCADE)");

    // Добавляем стандартные категории, если их ещё нет
    QStringList defaultCategories = {"Супы", "Салаты", "Вторые блюда", "Десерты", "Завтраки", "Закуски"};
    for (const QString& cat : defaultCategories) {
        query.prepare("INSERT OR IGNORE INTO categories (name) VALUES (?)");
        query.addBindValue(cat);
        query.exec();
    }

    qDebug() << "База данных успешно создана/открыта";
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!createDatabase()) {
        return -1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
