#pragma once
#include "Building.h"
class GravelPlant :
    public Building
{
public:
    GravelPlant() {
        PowerUse = 10;
        WaterUse = 10;
        NutrientUse = 0;

        Category = Industry;

        // set model
        // set material
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 10;
        cost.Concrete = 20;
        cost.Wood = 20;
        return cost;
    }
};