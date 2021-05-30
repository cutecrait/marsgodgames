#pragma once
#include "Building.h"
class Well :
    public Building
{
public:
    Well() {
        PowerUse = 10;
        WaterUse = -60;
        NutrientUse = 0;

        Category = BuildingCategory::Farming;

        // set model
        // set material
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 50;
        cost.Concrete = 10;
        cost.Wood = 0;
        return cost;
    }
};
