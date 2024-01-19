#include <Arduino.h>
#include <Wire.h>
#include <lv_conf.h>
#include <lvgl.h>
#include "gui.h"

#include "../ui/ui.h"
#include "../gfx/LGFX_ESP32S3_RGB_MakerfabsParallelTFTwithTouch70.h"

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
