// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: SQTest

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Recipe
void ui_Recipe_screen_init(void);
void ui_event_Recipe(lv_event_t * e);
lv_obj_t * ui_Recipe;
void ui_event_IngredientsSuggestionPanel(lv_event_t * e);
lv_obj_t * ui_IngredientsSuggestionPanel;
void ui_event_GetRecipeButton(lv_event_t * e);
lv_obj_t * ui_GetRecipeButton;
lv_obj_t * ui_GetRecipesLbl;
lv_obj_t * ui_TopPanel;
lv_obj_t * ui_Image3;
lv_obj_t * ui_AvailableIngredientsPanel;
void ui_event_IngredientText(lv_event_t * e);
lv_obj_t * ui_IngredientText;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Container1;
lv_obj_t * ui_BreakfastBtn;
lv_obj_t * ui_MealButtonText;
lv_obj_t * ui_LunchBtn;
lv_obj_t * ui_Label4;
lv_obj_t * ui_SnackBtn;
lv_obj_t * ui_Label6;
lv_obj_t * ui_DinnerBtn;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label7;
lv_obj_t * ui_Container2;
lv_obj_t * ui_Button7;
lv_obj_t * ui_Label8;
lv_obj_t * ui_Button8;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Button9;
lv_obj_t * ui_Label10;
lv_obj_t * ui_Button10;
lv_obj_t * ui_Label11;
lv_obj_t * ui_Button11;
lv_obj_t * ui_Label12;
lv_obj_t * ui_IngredientsKeyboard;


// SCREEN: ui_Main
void ui_Main_screen_init(void);
lv_obj_t * ui_Main;
lv_obj_t * ui_RecipePanel;
lv_obj_t * ui_Label1;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Image2;


// SCREEN: ui_Options
void ui_Options_screen_init(void);
void ui_event_Options(lv_event_t * e);
lv_obj_t * ui_Options;
void ui_event_WiFiScan(lv_event_t * e);
lv_obj_t * ui_WiFiScan;
lv_obj_t * ui_WiFiScanlbl;
lv_obj_t * ui_WiFiList;
lv_obj_t * ui_WiFiConnectionPnl;
lv_obj_t * ui_WiFiPwdKeyboard;
void ui_event_WiFiConnect(lv_event_t * e);
lv_obj_t * ui_WiFiConnect;
lv_obj_t * ui_WiFiConnectLbl;
void ui_event_WiFiPassword(lv_event_t * e);
lv_obj_t * ui_WiFiPassword;


// SCREEN: ui_Components
void ui_Components_screen_init(void);
lv_obj_t * ui_Components;
lv_obj_t * ui_RecipeItem;
lv_obj_t * ui_RecipeImage;
lv_obj_t * ui_RecipeLabel;
lv_obj_t * ui_ChipPanel;
lv_obj_t * ui_CloseLabel;
lv_obj_t * ui_ChipText;
lv_obj_t * ui_SuggestionButton;
lv_obj_t * ui_SuggestionText;
lv_obj_t * ui_PanelRecipe2;
void ui_event____initial_actions0(lv_event_t * e);
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Recipe(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_IngredientsSuggestionPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_GetRecipeButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        GetRecipeButtonClicked(e);
    }
}
void ui_event_IngredientText(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_IngredientsKeyboard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(ui_IngredientsKeyboard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    if(event_code == LV_EVENT_READY) {
        _ui_flag_modify(ui_IngredientsKeyboard, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        IngredientsTextReady(e);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        IngredientsTextValueChanged(e);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        Button_Clicked_1(e);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_label_set_property(ui_Label1, _UI_LABEL_PROPERTY_TEXT, "Monika smells");
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Options, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Options_screen_init);
    }
}
void ui_event_Options(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_flag_modify(ui_WiFiConnectionPnl, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_WiFiScan(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ScanWifi_Clicked(e);
    }
}
void ui_event_WiFiConnect(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        WiFiConnect_Clicked(e);
    }
}
void ui_event_WiFiPassword(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_basic_set_property(ui_WiFiPwdKeyboard, _UI_BASIC_PROPERTY_POSITION_X,  -1);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_basic_set_property(ui_WiFiPwdKeyboard, _UI_BASIC_PROPERTY_POSITION_X,  1000);
    }
}
void ui_event____initial_actions0(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        _ui_basic_set_property(ui_WiFiPwdKeyboard, _UI_BASIC_PROPERTY_POSITION_X,  1000);
    }
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        InitialActionsGui(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Recipe_screen_init();
    ui_Main_screen_init();
    ui_Options_screen_init();
    ui_Components_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_obj_add_event_cb(ui____initial_actions0, ui_event____initial_actions0, LV_EVENT_ALL, NULL);

    lv_disp_load_scr(ui____initial_actions0);
    lv_disp_load_scr(ui_Recipe);
}
