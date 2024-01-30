
#ifndef RECIPESSCREEN_H
#define RECIPESSCREEN_H

#include "gui/gui.h"
#include "ui/ui.h"
#include <vector>
#include <Arduino.h>
#include "models/recipe.hpp"

class RecipesScreen
{
public:
    void SetRecipe(Recipe *recipe, lv_obj_t *recipePanel);
};

extern RecipesScreen recipesScreen;

#endif