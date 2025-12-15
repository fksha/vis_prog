#include "filterstrategy.h"
#include <algorithm>

// NameFilterStrategy implementation
NameFilterStrategy::NameFilterStrategy(const QString& searchText) 
    : searchText(searchText.trimmed()) {
}

bool NameFilterStrategy::filter(const RecipeFilterData& recipe, int& score) {
    if (searchText.isEmpty()) {
        return true;
    }
    
    QString name = recipe.name;
    if (name.contains(searchText, Qt::CaseInsensitive)) {
        // Точное совпадение - максимальный приоритет
        if (name.compare(searchText, Qt::CaseInsensitive) == 0) {
            score += 1000;
        } else if (name.startsWith(searchText, Qt::CaseInsensitive)) {
            score += 500;
        } else {
            score += 100;
        }
        return true;
    }
    
    return false;
}

// CategoryFilterStrategy implementation
CategoryFilterStrategy::CategoryFilterStrategy(const QSet<int>& categoryIds) 
    : categoryIds(categoryIds) {
}

bool CategoryFilterStrategy::filter(const RecipeFilterData& recipe, int& score) {
    if (categoryIds.isEmpty()) {
        return true;
    }
    
    if (categoryIds.contains(recipe.categoryId)) {
        score += 50;
        return true;
    }
    
    return false;
}

// TimeFilterStrategy implementation
TimeFilterStrategy::TimeFilterStrategy(int minTime, int maxTime) 
    : minTime(minTime), maxTime(maxTime) {
}

bool TimeFilterStrategy::filter(const RecipeFilterData& recipe, int& score) {
    if (recipe.time >= minTime && recipe.time <= maxTime) {
        return true;
    }
    
    return false;
}

// IngredientFilterStrategy implementation
IngredientFilterStrategy::IngredientFilterStrategy(const QSet<QString>& ingredients) 
    : requiredIngredients(ingredients) {
}

bool IngredientFilterStrategy::filter(const RecipeFilterData& recipe, int& score) {
    if (requiredIngredients.isEmpty()) {
        return true;
    }
    
    int matchingIngredients = 0;
    for (const QString& reqIng : requiredIngredients) {
        bool found = false;
        for (const QString& recipeIng : recipe.ingredients) {
            if (recipeIng.contains(reqIng, Qt::CaseInsensitive) || 
                reqIng.contains(recipeIng, Qt::CaseInsensitive)) {
                found = true;
                break;
            }
        }
        if (found) {
            matchingIngredients++;
        }
    }
    
    if (matchingIngredients > 0) {
        // Сортируем по релевантности: больше совпадений = выше приоритет
        score += matchingIngredients * 200;
        return true;
    }
    
    return false;
}

// FilterContext implementation
FilterContext::FilterContext() {
}

FilterContext::~FilterContext() {
    clearStrategies();
}

void FilterContext::addStrategy(FilterStrategy* strategy) {
    if (strategy != nullptr) {
        strategies.append(strategy);
    }
}

void FilterContext::clearStrategies() {
    for (FilterStrategy* strategy : strategies) {
        delete strategy;
    }
    strategies.clear();
}

QList<int> FilterContext::filterRecipes(const QList<RecipeFilterData>& recipes) {
    QList<int> filteredIds;
    QMap<int, int> relevance; // recipeId -> score
    
    for (const RecipeFilterData& recipe : recipes) {
        int score = 0;
        bool matches = true;
        
        // Применяем все стратегии
        for (FilterStrategy* strategy : strategies) {
            if (!strategy->filter(recipe, score)) {
                matches = false;
                break;
            }
        }
        
        if (matches) {
            filteredIds.append(recipe.recipeId);
            relevance[recipe.recipeId] = score;
        }
    }
    
    // Сортируем по релевантности (убывание)
    std::sort(filteredIds.begin(), filteredIds.end(), [&relevance](int a, int b) {
        return relevance[a] > relevance[b];
    });
    
    return filteredIds;
}


