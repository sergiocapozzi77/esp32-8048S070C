
#ifndef RECIPESCREEN_H
#define RECIPESCREEN_H

#include "gui/gui.h"
#include "ui/ui.h"
#include <vector>
#include <Arduino.h>
#include "models/recipe.hpp"

class RecipeScreen
{
    void ui_event_click(lv_event_t *e);
    std::vector<String> availableIngredients;

public:
    std::vector<String> GetAvailableIngredients() { return availableIngredients; }
    void SuggestedIngredientClicked(lv_event_t *e);
    void IngredientsTextValueChanged(lv_event_t *e);
    void SetRecipe(Recipe *recipe, lv_obj_t *title, lv_obj_t *ingredients);
};

extern RecipeScreen recipeScreen;

#endif