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
    lv_obj_t *target = lv_event_get_target(e);
    if (target != ui_AppetizerBtn)
    {
        _ui_state_modify(ui_AppetizerBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_MainBtn)
    {
        _ui_state_modify(ui_MainBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_SoupBtn)
    {
        _ui_state_modify(ui_SoupBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_DessertBtn)
    {
        _ui_state_modify(ui_DessertBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}

void CuisineChecked(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    if (target != ui_ItalianBtn)
    {
        _ui_state_modify(ui_ItalianBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_ThaiBtn)
    {
        _ui_state_modify(ui_ThaiBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_MexBtn)
    {
        _ui_state_modify(ui_MexBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_IndianBtn)
    {
        _ui_state_modify(ui_IndianBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
    if (target != ui_ChineseBtn)
    {
        _ui_state_modify(ui_ChineseBtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
    }
}

void GetRecipeButtonClicked(lv_event_t *e)
{
    Serial.println("Getting recipe button click");
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
