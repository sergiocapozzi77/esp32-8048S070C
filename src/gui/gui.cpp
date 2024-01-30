#include <Arduino.h>
#include <Wire.h>
#include <lv_conf.h>
#include <lvgl.h>
#include "gui.h"

#include "../ui/ui.h"
#include "../gfx/LGFX_ESP32S3_RGB_MakerfabsParallelTFTwithTouch70.h"

#include <ReactESP.h>

using namespace reactesp;

ReactESP app;

static const char *TAG = "gui";

static const uint16_t screenWidth = 800;
static const uint16_t screenHeight = 480;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][screenWidth * 10];

LGFX gfx;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  if (gfx.getStartCount() == 0)
  { // Processing if not yet started
    gfx.startWrite();
  }
  gfx.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::rgb565_t *)&color_p->full);
  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;

  data->state = LV_INDEV_STATE_REL;

  if (gfx.getTouch(&touchX, &touchY))
  {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

/**
 * @brief
 *
 */
void gui_start()
{

  // ----------- GFX -------------
  gfx.begin();
  //  gfx.setColorDepth(16);
  gfx.setBrightness(127);

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf[0], buf[1], screenWidth * 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();
}

void InitialActionsGui(lv_event_t *e)
{
  lv_obj_set_user_data(ui_BreakfastBtn, (char *)"breakfast");
  lv_obj_set_user_data(ui_LunchBtn, (char *)"lunch");
  lv_obj_set_user_data(ui_SoupBtn, (char *)"soup");
  lv_obj_set_user_data(ui_DinnerBtn, (char *)"dinner");

  lv_obj_add_event_cb(ui_BreakfastBtn, MealChecked, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_LunchBtn, MealChecked, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_SoupBtn, MealChecked, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_DinnerBtn, MealChecked, LV_EVENT_CLICKED, NULL);

  lv_obj_set_user_data(ui_ItalianBtn, (char *)"italian");
  lv_obj_set_user_data(ui_ThaiBtn, (char *)"thai");
  lv_obj_set_user_data(ui_MexBtn, (char *)"mexican");
  lv_obj_set_user_data(ui_IndianBtn, (char *)"indian");
  lv_obj_set_user_data(ui_ChineseBtn, (char *)"chinese");

  lv_obj_add_event_cb(ui_ItalianBtn, CuisineChecked, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_ThaiBtn, CuisineChecked, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_MexBtn, CuisineChecked, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_IndianBtn, CuisineChecked, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_ChineseBtn, CuisineChecked, LV_EVENT_CLICKED, NULL);
}

lv_obj_t *createRecipeItem(lv_img_dsc_t *img)
{
  lv_obj_t *recipeItem = lv_obj_create(ui_RecipePanel);
  lv_obj_remove_style_all(recipeItem);
  lv_obj_set_width(recipeItem, 358);
  lv_obj_set_height(recipeItem, 70);
  lv_obj_set_x(recipeItem, 188);
  lv_obj_set_y(recipeItem, 6);
  lv_obj_set_align(recipeItem, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(recipeItem, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(recipeItem, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(recipeItem, LV_OBJ_FLAG_SCROLLABLE); /// Flags

  lv_obj_t *recipeImage = lv_img_create(recipeItem);
  lv_obj_set_width(recipeImage, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(recipeImage, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(recipeImage, LV_ALIGN_CENTER);
  lv_obj_add_flag(recipeImage, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
  lv_obj_clear_flag(recipeImage, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_img_set_src(recipeImage, img);

  lv_obj_t *recipeLabel = lv_label_create(recipeItem);
  lv_obj_set_width(recipeLabel, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(recipeLabel, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(recipeLabel, LV_ALIGN_CENTER);
  lv_label_set_text(recipeLabel, "Recipe");
  return recipeItem;
}

lv_obj_t *createButtonWithText(lv_obj_t *parent, const char *text, void (*ui_event_click)(lv_event_t *e))
{
  lv_obj_t *ui_SuggestionButton = lv_btn_create(parent);
  lv_obj_set_width(ui_SuggestionButton, 168);
  lv_obj_set_height(ui_SuggestionButton, 30);
  lv_obj_set_x(ui_SuggestionButton, -177);
  lv_obj_set_y(ui_SuggestionButton, 64);
  lv_obj_set_align(ui_SuggestionButton, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_SuggestionButton, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_SuggestionButton, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_add_flag(ui_SuggestionButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
  lv_obj_clear_flag(ui_SuggestionButton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
  lv_obj_set_style_bg_color(ui_SuggestionButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_SuggestionButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_width(ui_SuggestionButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_spread(ui_SuggestionButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_SuggestionText = lv_label_create(ui_SuggestionButton);
  lv_obj_set_width(ui_SuggestionText, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(ui_SuggestionText, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_SuggestionText, LV_ALIGN_CENTER);
  lv_label_set_text(ui_SuggestionText, text);
  lv_obj_set_style_text_color(ui_SuggestionText, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_SuggestionText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_event_cb(ui_SuggestionButton, ui_event_click, LV_EVENT_CLICKED, NULL);
  return ui_SuggestionButton;
}

lv_obj_t *createChip(lv_obj_t *parent, const char *text)
{
  lv_obj_t *chip = lv_obj_create(parent);
  lv_obj_set_width(chip, LV_SIZE_CONTENT); /// 100
  lv_obj_set_height(chip, 35);
  lv_obj_set_align(chip, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(chip, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(chip, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(chip, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_radius(chip, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(chip, lv_color_hex(0xEEEEEE), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(chip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(chip, lv_color_hex(0x848484), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(chip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(chip, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *close = lv_label_create(chip);
  lv_obj_set_width(close, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(close, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(close, LV_ALIGN_CENTER);
  lv_label_set_text(close, "x");

  lv_obj_t *chiptext = lv_label_create(chip);
  lv_obj_set_width(chiptext, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(chiptext, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(chiptext, LV_ALIGN_CENTER);
  lv_label_set_text(chiptext, text);

  return chip;
}