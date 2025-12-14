#ifndef RECIPEVIEWDIALOG_H
#define RECIPEVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class RecipeViewDialog;
}

class RecipeViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeViewDialog(int recipeId, int userId, QWidget *parent = nullptr);
    ~RecipeViewDialog();

private slots:
    void on_backButton_clicked();
    void on_deleteButton_clicked();
    void on_editButton_clicked();

private:
    Ui::RecipeViewDialog *ui;
    int currentRecipeId;
    int currentUserId;
    
    void loadRecipeData();
    void loadIngredients();
    void loadSteps();
};

#endif // RECIPEVIEWDIALOG_H


