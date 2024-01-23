#include "recipe_screen.h"
#include "ui/ui.h"
#include "gui.h"
#include <Arduino.h>

void IngredientsTextReady(lv_event_t *e)
{
    lv_obj_t *ta = lv_event_get_target(e);
    if (e->code == LV_EVENT_READY)
    {
        lv_indev_reset(NULL, ta);
    }
}

void IngredientsTextValueChanged(lv_event_t *e)
{
    Serial.println("IngredientsTextValueChanged");
    lv_obj_t *ta = lv_event_get_target(e);
    Serial.println("IngredientsTextValueChanged 1");
    const char *text = lv_textarea_get_text(ta);
    Serial.println("IngredientsTextValueChanged 2");
    if (strlen(text) > 1)
    {
        createButtonWithText(ui_IngredientsSuggestionPanel, "Banana");
    }
}

class RecipeScreen
{
    const char *ingredients[20] = {"Chicken", "Salmon", "Beef", "Pork", "Avocado", "Apple Cider Vinegar", "Asparagus", "Aubergine", "Baby Plum Tomatoes", "Bacon", "Baking Powder", "Balsamic Vinegar", "Basil", "Basil Leaves", "Basmati Rice"};
};
