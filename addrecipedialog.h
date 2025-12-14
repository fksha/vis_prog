#ifndef ADDRECIPEDIALOG_H
#define ADDRECIPEDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QEvent>

namespace Ui {
class AddRecipeDialog;
}

class AddRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipeDialog(int userId, QWidget *parent = nullptr);
    explicit AddRecipeDialog(int userId, int recipeId, QWidget *parent = nullptr); // Конструктор для редактирования
    ~AddRecipeDialog();
    
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_backButton_clicked();
    void on_addIngredientButton_clicked();
    void on_addStepButton_clicked();
    void on_saveButton_clicked();
    void on_addPhotoButton_clicked();
    void removeIngredient(QListWidgetItem *item);
    void removeStep(QListWidgetItem *item);

private:
    Ui::AddRecipeDialog *ui;
    int currentUserId;
    int currentRecipeId;  // 0 если добавление, >0 если редактирование
    QString photoPath;
    int currentStepNumber;

    bool photoDialogOpen;

    void loadCategories();
    void loadRecipeData();  // Загрузка данных рецепта для редактирования
    void updateCurrentStepLabel();
    void updatePhotoDisplay();
};

#endif // ADDRECIPEDIALOG_H
