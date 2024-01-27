
#ifndef RECIPESCREEN_H
#define RECIPESCREEN_H

#include "gui/gui.h"
#include "ui/ui.h"

class RecipeScreen
{
    void ui_event_click(lv_event_t *e);

public:
    void SuggestedIngredientClicked(lv_event_t *e);
    void IngredientsTextValueChanged(lv_event_t *e);
};

extern RecipeScreen recipeScreen;

#endif