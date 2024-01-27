#include "chatgpt.hpp"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "secret.h"

const char *ChatGpt::GetRecipe(String ingredients[])
{
  HTTPClient http;
  http.begin("https://api.openai.com/v1/chat/completions");
  http.addHeader("content-type", "application/json");
  char bearer[512];
  snprintf(bearer, sizeof(bearer), "Bearer %s", chatgpt_key);
  http.addHeader("authorization", bearer);
  http.setTimeout(60000);

  DynamicJsonDocument doc(10024);
  doc["model"] = "gpt-3.5-turbo";
  JsonArray messages = doc["messages"].to<JsonArray>();
  JsonObject message = messages.createNestedObject();
  message["role"] = "user";
  message["content"] = "Can you give me a recipe if I have pasta and plum tomato ingredients? And can you format the recipe in ingredients and method?";
  doc["temperature"] = 0.7;
  int jsonSize = measureJson(doc);

  char *json_string = new char[jsonSize + 1];
  serializeJson(doc, json_string, jsonSize + 1);
  Serial.println(json_string);
  // int httpCode = http.POST("{\"model\": \"gpt-3.5-turbo\",\"messages\": [{\"role\": \"user\", \"content\": \"Can you give me a recipe if I have pasta and plum tomato ingredients? And can you format the recipe in ingredients and method?\"}],\"temperature\": 0.7}");
  int httpCode = http.POST(json_string);
  delete json_string;
  // httpCode will be negative on error
  if (httpCode > 0)
  {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] POST... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK)
    {
      // Allocate the JSON document
      DynamicJsonDocument doc(12288);

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
    }
  }
}