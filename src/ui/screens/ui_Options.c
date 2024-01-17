// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: SQTest

#include "../ui.h"

void ui_Options_screen_init(void)
{
    ui_Options = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Options, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_WiFiScan = lv_btn_create(ui_Options);
    lv_obj_set_width(ui_WiFiScan, 100);
    lv_obj_set_height(ui_WiFiScan, 50);
    lv_obj_set_x(ui_WiFiScan, -332);
    lv_obj_set_y(ui_WiFiScan, -204);
    lv_obj_set_align(ui_WiFiScan, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_WiFiScan, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_WiFiScan, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_WiFiScan, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_WiFiScan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_WiFiScanlbl = lv_label_create(ui_WiFiScan);
    lv_obj_set_width(ui_WiFiScanlbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WiFiScanlbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_WiFiScanlbl, -325);
    lv_obj_set_y(ui_WiFiScanlbl, -201);
    lv_obj_set_align(ui_WiFiScanlbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WiFiScanlbl, "Scan");

    ui_WiFiList = lv_obj_create(ui_Options);
    lv_obj_set_width(ui_WiFiList, 250);
    lv_obj_set_height(ui_WiFiList, 390);
    lv_obj_set_x(ui_WiFiList, -259);
    lv_obj_set_y(ui_WiFiList, 30);
    lv_obj_set_align(ui_WiFiList, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_WiFiList, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_WiFiList, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    ui_WiFiConnectionPnl = lv_obj_create(ui_Options);
    lv_obj_set_width(ui_WiFiConnectionPnl, 493);
    lv_obj_set_height(ui_WiFiConnectionPnl, 390);
    lv_obj_set_x(ui_WiFiConnectionPnl, 127);
    lv_obj_set_y(ui_WiFiConnectionPnl, 30);
    lv_obj_set_align(ui_WiFiConnectionPnl, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WiFiConnectionPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_WiFiPwdKeyboard = lv_keyboard_create(ui_WiFiConnectionPnl);
    lv_obj_set_width(ui_WiFiPwdKeyboard, 474);
    lv_obj_set_height(ui_WiFiPwdKeyboard, 192);
    lv_obj_set_x(ui_WiFiPwdKeyboard, -1);
    lv_obj_set_y(ui_WiFiPwdKeyboard, 5);
    lv_obj_set_align(ui_WiFiPwdKeyboard, LV_ALIGN_CENTER);

    ui_WiFiConnect = lv_btn_create(ui_WiFiConnectionPnl);
    lv_obj_set_width(ui_WiFiConnect, 100);
    lv_obj_set_height(ui_WiFiConnect, 50);
    lv_obj_set_x(ui_WiFiConnect, 98);
    lv_obj_set_y(ui_WiFiConnect, -145);
    lv_obj_set_align(ui_WiFiConnect, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_WiFiConnect, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_WiFiConnect, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_WiFiConnectLbl = lv_label_create(ui_WiFiConnect);
    lv_obj_set_width(ui_WiFiConnectLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WiFiConnectLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WiFiConnectLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WiFiConnectLbl, "Connect");

    ui_WiFiPassword = lv_textarea_create(ui_WiFiConnectionPnl);
    lv_obj_set_width(ui_WiFiPassword, 255);
    lv_obj_set_height(ui_WiFiPassword, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_WiFiPassword, -104);
    lv_obj_set_y(ui_WiFiPassword, -142);
    lv_obj_set_align(ui_WiFiPassword, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_WiFiPassword, "WiFi password...");
    lv_textarea_set_one_line(ui_WiFiPassword, true);
    lv_textarea_set_password_mode(ui_WiFiPassword, true);



    lv_obj_add_event_cb(ui_WiFiScan, ui_event_WiFiScan, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_WiFiPwdKeyboard, ui_WiFiPassword);
    lv_obj_add_event_cb(ui_WiFiConnect, ui_event_WiFiConnect, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_WiFiPassword, ui_event_WiFiPassword, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Options, ui_event_Options, LV_EVENT_ALL, NULL);

}
