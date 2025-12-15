#ifndef FILTERSTRATEGY_H
#define FILTERSTRATEGY_H

#include <QList>
#include <QSet>
#include <QString>
#include <QMap>
#include <Qt>

// Структура для данных рецепта при фильтрации
struct RecipeFilterData {
    int recipeId;
    QString name;
    int time;
    int categoryId;
    QSet<QString> ingredients;
    
    RecipeFilterData(int id = -1, const QString& n = "", int t = 0, int catId = 0) 
        : recipeId(id), name(n), time(t), categoryId(catId) {}
};

// Базовый класс стратегии фильтрации
class FilterStrategy {
public:
    virtual ~FilterStrategy() = default;
    
    // Применяет фильтр к данным рецепта
    // Возвращает true, если рецепт проходит фильтр, иначе false
    // score - релевантность (может быть изменена стратегией)
    virtual bool filter(const RecipeFilterData& recipe, int& score) = 0;
};

// Стратегия фильтрации по названию
class NameFilterStrategy : public FilterStrategy {
public:
    NameFilterStrategy(const QString& searchText);
    bool filter(const RecipeFilterData& recipe, int& score) override;
    
private:
    QString searchText;
};

// Стратегия фильтрации по категории
class CategoryFilterStrategy : public FilterStrategy {
public:
    CategoryFilterStrategy(const QSet<int>& categoryIds);
    bool filter(const RecipeFilterData& recipe, int& score) override;
    
private:
    QSet<int> categoryIds;
};

// Стратегия фильтрации по времени приготовления
class TimeFilterStrategy : public FilterStrategy {
public:
    TimeFilterStrategy(int minTime, int maxTime);
    bool filter(const RecipeFilterData& recipe, int& score) override;
    
private:
    int minTime;
    int maxTime;
};

// Стратегия фильтрации по ингредиентам
class IngredientFilterStrategy : public FilterStrategy {
public:
    IngredientFilterStrategy(const QSet<QString>& ingredients);
    bool filter(const RecipeFilterData& recipe, int& score) override;
    
private:
    QSet<QString> requiredIngredients;
};

// Контекст для использования стратегий фильтрации
class FilterContext {
public:
    FilterContext();
    ~FilterContext();
    
    // Добавляет стратегию фильтрации
    void addStrategy(FilterStrategy* strategy);
    
    // Очищает все стратегии
    void clearStrategies();
    
    // Применяет все стратегии к списку рецептов
    // Возвращает отсортированный список ID рецептов по релевантности
    QList<int> filterRecipes(const QList<RecipeFilterData>& recipes);
    
private:
    QList<FilterStrategy*> strategies;
};

#endif // FILTERSTRATEGY_H

