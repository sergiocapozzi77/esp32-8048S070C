
#ifndef RECIPE_H
#define RECIPE_H

#include <Arduino.h>
#include <vector>

class Recipe
{
public:
    String title;
    std::vector<String> ingredients;
    std::vector<String> method;

    String GetIngredients()
    {
        String allIngredients = "Ingredients:\n\n";
        for (int i = 0; i < ingredients.size(); i++)
        {
            allIngredients = allIngredients + ingredients[i] + String("\n");
        }

        return allIngredients;
    }
};

#endif