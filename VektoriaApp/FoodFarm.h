#pragma once
#include "Building.h"
class FoodFarm :
    public Building
{
public:
    FoodFarm() {
        PowerUse = 5;
        WaterUse = 5;
        NutrientUse = 1;

        Category = BuildingCategory::Farming;

        setModel("models\\monkey.obj");
        // set material
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 30;
        cost.Concrete = 40;
        cost.Wood = 10;
        return cost;
    }
};
