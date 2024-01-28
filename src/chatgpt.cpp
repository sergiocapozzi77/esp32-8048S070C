#include "chatgpt.hpp"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "secret.h"
#include <vector>

ChatGpt chatGpt;

// const char *ChatGpt::GetRecipe(String ingredients[])
Recipe *ChatGpt::GetRecipes(std::vector<String> ingredients)
{
  Serial.println("Getting recipe");
  HTTPClient http;
  http.begin("https://api.openai.com/v1/chat/completions");
  http.addHeader("content-type", "application/json");
  char bearer[512];
  snprintf(bearer, sizeof(bearer), "Bearer %s", chatgpt_key);
  http.addHeader("authorization", bearer);
  http.setTimeout(60000);

  DynamicJsonDocument doc(10024);
  doc["model"] = "gpt-3.5-turbo-1106";
  JsonObject response_format = doc["response_format"]["type"] = "json_object";

  JsonArray messages = doc["messages"].to<JsonArray>();
  JsonObject message = messages.createNestedObject();
  message["role"] = "user";

  String availableIngredients = "";
  if (ingredients.size() == 0)
  {
    availableIngredients = "pancetta,passata,pasta";
  }
  else
  {
    for (int i = 0; i < ingredients.size(); i++)
    {
      availableIngredients = availableIngredients + ingredients[i] + String(",");
    }
  }

  Serial.print("Available ingredents: ");
  Serial.println(availableIngredients);

  message["content"] = String("Can you suggest 3 recipes if I only have ") + availableIngredients + String(" and return the response as an array of recipes in json? Split each recipe by title as a string, ingredients as an array and method as an array.");
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
        return NULL;
      }

      JsonArray choices = doc["choices"].as<JsonArray>();
      for (int i = choices.size() - 1; i >= 0; i--)
      {
        String role = choices[i]["message"]["role"];
        if (role == "assistant")
        {
          String recipesJsonString = choices[i]["message"]["content"];
          doc.clear();
          DynamicJsonDocument recipesDoc(12288);
          DeserializationError error = deserializeJson(recipesDoc, recipesJsonString.c_str());

          // Test if parsing succeeds
          if (error)
          {
            Serial.print(F("deserializeJson() recipesJson failed: "));
            Serial.println(error.f_str());
            return NULL;
          }

          Recipe *ret = new Recipe[3];
          JsonArray recipes = recipesDoc["recipes"].as<JsonArray>();
          for (int r = 0; recipes.size(); r++)
          {
            Serial.println("Loop");
            if (r == 3)
            {
              break;
            }

            ret[r].title = recipes[r]["title"].as<String>();
            JsonArray ingredients = recipes[r]["ingredients"].as<JsonArray>();
            for (int n = 0; n < ingredients.size(); n++)
            {
              ret[r].ingredients.push_back(ingredients[n].as<String>());
            }

            JsonArray method = recipes[r]["method"].as<JsonArray>();
            for (int n = 0; n < method.size(); n++)
            {
              ret[r].method.push_back(method[n].as<String>());
            }

            Serial.print("Recipe ");
            Serial.println(r);

            Serial.print("Title: ");
            Serial.println(ret[r].title);
          }

          return ret;
        }
      }
    }
    else
    {
      String payload = http.getString();
      Serial.println(payload);
    }
  }

  return NULL;
}