#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QEvent>
#include <QTimer>
#include <QSet>
#include<QLabel>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    enum SearchMode {
        SearchAllRecipes,
        SearchFavorites
    };

    explicit SearchDialog(int userId, SearchMode mode = SearchAllRecipes, QWidget *parent = nullptr);
    ~SearchDialog();
    
    void closeEvent(QCloseEvent *event) override;

    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_backButton_clicked();
    void on_clearSearchButton_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_categoriesComboBox_currentIndexChanged(int index);
    void on_ingredientsComboBox_editTextChanged(const QString &text);
    void on_ingredientsComboBox_activated(int index);
    void handleIngredientReturnPressed();
    void handleIngredientEditingFinished();
    void on_timeFilterButton_clicked();
    void on_resetFiltersButton_clicked();
    void on_timeMinSlider_valueChanged(int value);
    void on_timeMaxSlider_valueChanged(int value);
    void on_timeMinSpinBox_valueChanged(int value);
    void on_timeMaxSpinBox_valueChanged(int value);
    void on_recipeItemDoubleClicked(QListWidgetItem *item);
    void performSearch();

private:
    Ui::SearchDialog *ui;
    int currentUserId;
    SearchMode searchMode;
    QTimer *searchTimer;
    
    // Фильтры
    QString searchText;
    QSet<int> selectedCategoryIds;
    QSet<QString> selectedIngredients;
    int minTime;
    int maxTime;
    
    void loadCategories();
    void loadIngredients();
    void loadResults();
    void showRecipeCard(int recipeId, const QString &name, int time, const QString &photoPath, bool isFavourite);
    void toggleFavourite(QLabel *heartLabel, int recipeId);
    void addFilterChip(const QString &label, const QString &value, const QString &type);
    void removeFilterChip(const QString &type);
    void updateSelectedFilters();
    void updateTimeLabels();
    void updateFilterButtons();
    QList<int> getRelevantRecipeIds();
};

#endif // SEARCHDIALOG_H

