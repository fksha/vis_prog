#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include "user.h"
#include<QLabel>
#include<QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    void on_addRecipeButton_clicked();
    void on_navFavoritesButton_clicked();
    void on_navRecipesButton_clicked();
    void on_favoritesNavFavoritesButton_clicked();
    void on_favoritesNavRecipesButton_clicked();
    void on_recipeItemDoubleClicked(QListWidgetItem *item);
    void on_searchButton_clicked();
    void on_favoritesSearchButton_clicked();
    void on_navProfileButton_clicked();
    void on_profileNavFavoritesButton_clicked();
    void on_profileNavRecipesButton_clicked();
    void on_profileNavProfileButton_clicked();
    void on_profileEditButton_clicked();
    void on_logoutButton_clicked();
    void on_dataManagementComboBox_currentIndexChanged(int index);


private:
    Ui::MainWindow *ui;
    User currentUser;  // Текущий вошедший пользователь
    bool dialogOpen;   // Флаг для предотвращения повторного открытия диалога
    bool searchDialogOpen;  // Флаг для предотвращения повторного открытия диалога поиска

    void showLoginForm();      // Показать форму входа
    void showMainInterface();
    void showFavoritesInterface();
    void showProfileInterface();
    void loadRecipes();
    void loadFavorites();
    void loadProfile();
    void toggleFavourite(QLabel *heartLabel, int recipeId);
    void exportData();
    void importData();
};

#endif // MAINWINDOW_H
