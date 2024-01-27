
#ifndef CHATGPT_H
#define CHATGPT_H

#include <Arduino.h>

class ChatGpt
{

public:
    const char *GetRecipe(String ingredients[]);
};

extern ChatGpt chatGpt;

#endif