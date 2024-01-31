#include "recipes_screen.hpp"
#include "stepbystep_screen.hpp"
#include "../ingredients.hpp"
#include <Arduino.h>
#include "models/recipe.hpp"

StepByStepScreen stepByStepScreen;

void NextBtnClick(lv_event_t *e)
{
    stepByStepScreen.VisualizeNextStep();
}

void PrevBtnClick(lv_event_t *e)
{
    stepByStepScreen.VisualizePrevStep();
}