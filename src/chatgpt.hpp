
#ifndef CHATGPT_H
#define CHATGPT_H

#include <Arduino.h>
#include "models/recipe.hpp"

class ChatGpt
{

public:
    // const char *GetRecipe(String ingredients[]);
    Recipe *GetRecipes(std::vector<String> ingredients, String cuisine);
};

extern ChatGpt chatGpt;

#endif