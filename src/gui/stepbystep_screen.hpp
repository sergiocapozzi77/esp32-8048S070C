
#ifndef STEPBYSTEP_H
#define STEPBYSTEP_H

#include "gui/gui.h"
#include "ui/ui.h"
#include <Arduino.h>
#include "models/recipe.hpp"

class StepByStepScreen
{
    Recipe *selectedRecipe;
    int currentStep;

public:
    void SetSelectedRecipe(Recipe *selectedRecipe)
    {
        this->selectedRecipe = selectedRecipe;
        currentStep = -1;
    }

    void VisualizeIngredients()
    {
        lv_label_set_text(ui_RecipeTitleLbl, "Ingredients: ");
        lv_label_set_text(ui_RecipeStepLbl, this->selectedRecipe->GetIngredients().c_str());
    }

    void VisualizeNextStep()
    {
        currentStep++;
        VisualizeStep();
    }

    void VisualizeStep()
    {
        lv_label_set_text(ui_RecipeTitleLbl, (String("Step:") + String(currentStep) + ":").c_str());
        lv_label_set_text(ui_RecipeStepLbl, this->selectedRecipe->method[currentStep].c_str());
    }

    void VisualizePrevStep()
    {
        currentStep--;

        VisualizeStep();
    }
};

extern StepByStepScreen stepByStepScreen;

#endif