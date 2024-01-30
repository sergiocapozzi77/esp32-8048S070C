#include "recipes_screen.hpp"
#include "recipe_screen.hpp"
#include "chatgpt.hpp"
#include "../ingredients.hpp"
#include <Arduino.h>
#include "models/recipe.hpp"

RecipesScreen recipesScreen;

void RecipesScreenLoaded(lv_event_t *e)
{

    String cuisine;
    if (lv_obj_has_state(ui_ItalianBtn, LV_STATE_CHECKED))
    {
        cuisine = "italian";
    }
    else if (lv_obj_has_state(ui_ThaiBtn, LV_STATE_CHECKED))
    {
        cuisine = "thai";
    }
    else if (lv_obj_has_state(ui_MexBtn, LV_STATE_CHECKED))
    {
        cuisine = "mexican";
    }
    else if (lv_obj_has_state(ui_IndianBtn, LV_STATE_CHECKED))
    {
        cuisine = "indian";
    }
    else if (lv_obj_has_state(ui_ChineseBtn, LV_STATE_CHECKED))
    {
        cuisine = "chinese";
    }

    Recipe *recipes = chatGpt.GetRecipes(recipeScreen.GetAvailableIngredients(), cuisine);
    lv_obj_add_flag(ui_SpinnerRecipes, LV_OBJ_FLAG_HIDDEN);

    if (recipes == NULL)
    {
        return;
    }
}