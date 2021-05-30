#pragma once
#include "Building.h"

class TreeFarm :
    public Building
{
public:
    TreeFarm() {
        PowerUse = 5;
        WaterUse = 3;
        NutrientUse = 1;

        Category = BuildingCategory::Farming;

        // set model
        // set material
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 20;
        cost.Concrete = 20;
        cost.Wood = 0;
        return cost;
    }
};