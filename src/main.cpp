#include <Arduino.h>
#include <lv_conf.h>
#include <lvgl.h>

#include "gui/gui.h"
#include "ui/ui.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

bool scanWifi = false;

const char *ssid = "TP-Link_8724";
const char *password = "40950211";
// const char *ssid;
// const char *password;

void Button_Clicked_1(lv_event_t *e)
{
  Serial.println("Clicked");

  HTTPClient http;
  http.begin("https://cloud.seatable.io/api/v2.1/dtable/app-access-token/");
  http.addHeader("accept", "application/json");
  http.addHeader("authorization", "Bearer ea6fa8dd468f479db3e2528d55423b9d27c51622");
  int httpCode = http.GET();

  // httpCode will be negative on error
  if (httpCode > 0)
  {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK)
    {
      // Allocate the JSON document
      DynamicJsonDocument doc(1024);

      String payload = http.getString();
      Serial.println(payload);
      DeserializationError error = deserializeJson(doc, payload.c_str());

      // Test if parsing succeeds
      if (error)
      {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }

      const char *access_token = doc["access_token"];
      Serial.println(access_token);
    }
  }
  else
  {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

void WiFiConnect_Clicked(lv_event_t *e)
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  password = lv_textarea_get_text(ui_WiFiPassword);

  Serial.print("WiFi connect: ");
  Serial.print(ssid);
  Serial.print(" ");
  Serial.print(password);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
}

void ui_event_WifiLabel(lv_event_t *e)
{
  Serial.println("ui_event_WifiLabel");
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);

  ssid = lv_label_get_text(lv_obj_get_child(target, 0));
  if (event_code == LV_EVENT_CLICKED)
  {
    Serial.println("ui_event_WifiLabel 2");
    lv_obj_t *panel = lv_obj_get_parent(target);
    for (int i = 0; i < lv_obj_get_child_cnt(panel); i++)
    {
      lv_obj_t *child = lv_obj_get_child(panel, i);
      if (child != target)
      {
        lv_obj_clear_state(child, LV_STATE_CHECKED);
      }
    }
  }

  lv_obj_clear_flag(ui_WiFiConnectionPnl, LV_OBJ_FLAG_HIDDEN); /// Flags
}

void ScanWifi_Clicked(lv_event_t *e)
{
  lv_obj_add_flag(ui_WiFiConnectionPnl, LV_OBJ_FLAG_HIDDEN); /// Flags
  scanWifi = true;
  Serial.println("scan ning");
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
  {
    Serial.println("no networks found");
  }
  else
  {
    Serial.print(n);
    Serial.println(" networks found");

    lv_obj_clean(ui_WiFiList);

    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");

      lv_obj_t *button = lv_btn_create(ui_WiFiList);
      lv_obj_set_height(button, 30);
      lv_obj_set_width(button, lv_pct(100));
      lv_obj_set_align(button, LV_ALIGN_CENTER);
      lv_obj_add_flag(button, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
      lv_obj_clear_flag(button, LV_OBJ_FLAG_SCROLLABLE);                            /// Flags
      lv_obj_set_style_bg_color(button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_width(button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_spread(button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

      lv_obj_t *label = lv_label_create(button);
      lv_obj_set_width(label, LV_SIZE_CONTENT);  /// 1
      lv_obj_set_height(label, LV_SIZE_CONTENT); /// 1
      lv_obj_set_align(label, LV_ALIGN_CENTER);
      lv_label_set_text(label, WiFi.SSID(i).c_str());
      lv_obj_set_style_text_color(label, lv_color_black(), LV_PART_MAIN);
      lv_obj_add_event_cb(button, ui_event_WifiLabel, LV_EVENT_CLICKED, NULL);
    }
  }
}

void setup()
{

  Serial.begin(115200);
  Serial.println();

  Serial.println(F("Tft starting"));

  gui_start();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println(F("Wifi connected"));

  // WiFi.begin(ssid, password);

  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(500);
  //   Serial.print(".");
  // }

  // Serial.println("");
  // Serial.println("WiFi connected");
}

void loop()
{
  lv_timer_handler();

  delay(5);
}
