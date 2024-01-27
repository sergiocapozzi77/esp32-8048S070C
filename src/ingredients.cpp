#include "ingredients.hpp"

Ingredients ingredients;

Ingredients::Ingredients()
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        ingredients->toLowerCase();
    }
}

std::vector<String> Ingredients::GetIngredientsStartingWith(const char *text)
{
    std::vector<String> names;

    for (int i = 0; i < ARRAYSIZE; i++)
    {
        if (ingredients[i].startsWith(text))
        {
            names.push_back(ingredients[i]);
        }
    }

    return names;
}