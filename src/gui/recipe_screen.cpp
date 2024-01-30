#include "recipe_screen.hpp"
#include "chatgpt.hpp"
#include "../ingredients.hpp"
#include <Arduino.h>
#include "models/recipe.hpp"

RecipeScreen recipeScreen;

void IngredientsTextReady(lv_event_t *e)
{
    lv_obj_t *ta = lv_event_get_target(e);
    if (e->code == LV_EVENT_READY)
    {
        lv_indev_reset(NULL, ta);
    }
}

void MealChecked(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_current_target(e);

    if (target != ui_BreakfastBtn)
    {
        _ui_state_modify(ui_BreakfastBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_LunchBtn)
    {
        _ui_state_modify(ui_LunchBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}

void GetRecipeButtonClicked(lv_event_t *e)
{
    Serial.println("Getting recipe button click");

    Recipe *recipes = chatGpt.GetRecipes(recipeScreen.GetAvailableIngredients());
    if (recipes == NULL)
    {
        return;
    }

    // recipeScreen.SetRecipe(&recipes[0], ui_PanelRecipe);
    // recipeScreen.SetRecipe(&recipes[1], ui_PanelRecipe1);
}

void IngredientsTextValueChanged(lv_event_t *e)
{
    recipeScreen.IngredientsTextValueChanged(e);
}

void suggestedIngredientClicked(lv_event_t *e)
{
    recipeScreen.SuggestedIngredientClicked(e);
}

void RecipeScreen::SuggestedIngredientClicked(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    const char *ingredient = lv_label_get_text(lv_obj_get_child(target, 0));
    createChip(ui_AvailableIngredientsPanel, ingredient);
    lv_obj_add_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
    lv_textarea_set_text(ui_IngredientText, "");

    this->availableIngredients.push_back(String(ingredient));
}

void RecipeScreen::SetRecipe(Recipe *recipe, lv_obj_t *recipePanel)
{
    lv_label_set_text(ui_comp_get_child(recipePanel, UI_COMP_PANELRECIPE_RECIPETITLE0), recipe->title.c_str());

    String allIngredients = "Ingredients:\n\n";
    for (int i = 0; i < recipe->ingredients.size(); i++)
    {
        allIngredients = allIngredients + recipe->ingredients[i] + String("\n");
    }

    allIngredients += "\n\nMethod:\n\n";

    for (int i = 0; i < recipe->method.size(); i++)
    {
        allIngredients = allIngredients + recipe->method[i] + String("\n");
    }

    Serial.println("------ all ingredients ----");
    Serial.println(allIngredients);

    lv_label_set_text(ui_comp_get_child(recipePanel, UI_COMP_PANELRECIPE_PANELINGREDIENTS_RECIPEINGREDIENTS0), allIngredients.c_str());
}

void RecipeScreen::IngredientsTextValueChanged(lv_event_t *e)
{
    Serial.println("IngredientsTextValueChanged");
    lv_obj_t *ta = lv_event_get_target(e);
    const char *text = lv_textarea_get_text(ta);
    if (strlen(text) > 1)
    {
        std::vector<String> list = ingredients.GetIngredientsStartingWith(text);
        if (list.size() > 0)
        {
            lv_obj_clean(ui_IngredientsSuggestionPanel);
            for (int i = 0; i < list.size(); i++)
            {
                createButtonWithText(ui_IngredientsSuggestionPanel, list[i].c_str(), suggestedIngredientClicked);
            }
            lv_obj_clear_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
        }
        else
        {
            lv_obj_add_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
        }
    }
    else
    {
        lv_obj_add_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
    }
}
