
#include "../ui/ui.h"
#include <ReactESP.h>

#ifndef GUI_H
#define GUI_H

void gui_start();
lv_obj_t *createRecipeItem(lv_img_dsc_t *img);
lv_obj_t *createChip(lv_obj_t *parent, const char *text);
lv_obj_t *createButtonWithText(lv_obj_t *parent, const char *text, void (*ui_event_click)(lv_event_t *e));

void MealChecked(lv_event_t *e);
void CuisineChecked(lv_event_t *e);

using namespace reactesp;
extern ReactESP app;
#endif