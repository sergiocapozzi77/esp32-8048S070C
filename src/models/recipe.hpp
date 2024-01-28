
#ifndef RECIPE_H
#define RECIPE_H

#include <Arduino.h>
#include <vector>

class Recipe
{
public:
    String title;
    std::vector<String> ingredients;
    String method;
};

#endif