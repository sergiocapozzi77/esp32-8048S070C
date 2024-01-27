#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <Arduino.h>
#include <vector>

class Ingredients
{
#define ARRAYSIZE 20
    String ingredients[ARRAYSIZE] = {"Chicken", "Salmon", "Beef", "Pork", "Avocado", "Apple Cider Vinegar", "Asparagus", "Aubergine", "Baby Plum Tomatoes", "Bacon", "Baking Powder", "Balsamic Vinegar", "Basil", "Basil Leaves", "Basmati Rice"};

public:
    Ingredients();
    std::vector<String> GetIngredientsStartingWith(const char *text);
};

extern Ingredients ingredients;

#endif