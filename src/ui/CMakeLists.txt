SET(SOURCES components/ui_comp_panelrecipe.c
    components/ui_comp.c
    screens/ui_Recipe.c
    screens/ui_Main.c
    screens/ui_Options.c
    screens/ui_Components.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_9921876_spoon_fork_kitchen_restaurant_utensil_icon_png.c
    images/ui_img_3994418_internet_network_signal_wifi_wireless_icon_png.c
    images/ui_img_pizza_png.c)

add_library(ui ${SOURCES})
