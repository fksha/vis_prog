#ifndef RECIPEFACTORY_H
#define RECIPEFACTORY_H

#include <QString>
#include <QStringList>
#include <QList>

// Структура для хранения данных ингредиента
struct IngredientData {
    QString name;
    QString quantity;
    
    IngredientData(const QString& n = "", const QString& q = "") 
        : name(n), quantity(q) {}
};

// Структура для хранения данных шага приготовления
struct StepData {
    int stepNumber;
    QString description;
    
    StepData(int num = 0, const QString& desc = "") 
        : stepNumber(num), description(desc) {}
};

// Структура для шаблона рецепта
struct RecipeTemplate {
    QString name;
    QString photoPath;
    int time;
    int categoryId;
    QList<IngredientData> ingredients;
    QList<StepData> steps;
};

// Базовый класс фабрики рецептов
class RecipeFactory {
public:
    virtual ~RecipeFactory() = default;
    
    // Создает рецепт в базе данных по шаблону
    // Возвращает ID созданного рецепта или -1 в случае ошибки
    virtual int createRecipe(int userId, const RecipeTemplate& template_) = 0;
    
    // Обновляет существующий рецепт
    virtual bool updateRecipe(int recipeId, int userId, const RecipeTemplate& template_) = 0;
};

// Конкретная реализация фабрики для стандартных рецептов
class StandardRecipeFactory : public RecipeFactory {
public:
    StandardRecipeFactory();
    ~StandardRecipeFactory() override = default;
    
    int createRecipe(int userId, const RecipeTemplate& template_) override;
    bool updateRecipe(int recipeId, int userId, const RecipeTemplate& template_) override;
    
private:
    bool saveIngredients(int recipeId, const QList<IngredientData>& ingredients);
    bool saveSteps(int recipeId, const QList<StepData>& steps);
    QString copyPhoto(const QString& photoPath, int userId);
};

// Фабрика для создания рецептов из шаблона (можно расширить для разных типов)
class RecipeFactoryManager {
public:
    static RecipeFactory* getFactory(const QString& type = "standard");
    
private:
    static StandardRecipeFactory standardFactory;
};

#endif // RECIPEFACTORY_H


