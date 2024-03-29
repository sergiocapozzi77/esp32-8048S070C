#include "recipes_screen.hpp"
#include "recipe_screen.hpp"
#include "chatgpt.hpp"
#include "../ingredients.hpp"
#include <Arduino.h>
#include "models/recipe.hpp"
#include "stepbystep_screen.hpp"

RecipesScreen recipesScreen;

void RecipeSelectClicked(lv_event_t *e)
{
    stepByStepScreen.SetSelectedRecipe((Recipe *)lv_obj_get_user_data(e->target));
    stepByStepScreen.VisualizeIngredients();
    _ui_screen_change(&ui_StepByStep, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_StepByStep_screen_init);
}

void loadRecipes()
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

    String course;
    if (lv_obj_has_state(ui_MainBtn, LV_STATE_CHECKED))
    {
        course = "main";
    }
    else if (lv_obj_has_state(ui_AppetizerBtn, LV_STATE_CHECKED))
    {
        course = "appetizer";
    }
    else if (lv_obj_has_state(ui_SoupBtn, LV_STATE_CHECKED))
    {
        course = "soup";
    }
    else if (lv_obj_has_state(ui_DessertBtn, LV_STATE_CHECKED))
    {
        course = "dessert";
    }

    Recipe *recipes = chatGpt.GetRecipes(recipeScreen.GetAvailableIngredients(), cuisine, course);
    lv_obj_add_flag(ui_SpinnerRecipes, LV_OBJ_FLAG_HIDDEN);

    if (recipes == NULL)
    {
        return;
    }

    Serial.println("Setting recipes");

    Serial.println("Setting recipes 1");
    recipesScreen.SetRecipe(&recipes[0], ui_PanelRecipe1);
    Serial.println("Setting recipes 2");
    recipesScreen.SetRecipe(&recipes[1], ui_PanelRecipe2);

    Serial.println("Setting recipes 3");
    recipesScreen.SetRecipe(&recipes[2], ui_PanelRecipe3);
}

void RecipesScreenLoaded(lv_event_t *e)
{
    // lv_async_call(loadRecipes, NULL);
    app.onDelay(0, []()
                { loadRecipes(); });
}

void RecipesScreen::SetRecipe(Recipe *recipe, lv_obj_t *recipePanel)
{
    lv_label_set_text(ui_comp_get_child(recipePanel, UI_COMP_PANELRECIPE_RECIPETITLE0), recipe->title.c_str());

    String allIngredients = recipe->GetIngredients();

    // allIngredients += "\n\nMethod:\n\n";

    // for (int i = 0; i < recipe->method.size(); i++)
    // {
    //     allIngredients = allIngredients + recipe->method[i] + String("\n");
    // }

    // Serial.println("------ all ingredients ----");
    // Serial.println(allIngredients);

    lv_label_set_text(ui_comp_get_child(recipePanel, UI_COMP_PANELRECIPE_PANELINGREDIENTS_RECIPEINGREDIENTS0), allIngredients.c_str());
    lv_obj_set_user_data(ui_comp_get_child(recipePanel, UI_COMP_PANELRECIPE_PANELINGREDIENTSBUTTON_RECIPESELECTBTN), recipe);
}