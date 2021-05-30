#pragma once
#include "Building.h"
class RobotFactory :
    public Building
{
public:
    RobotFactory() {
        PowerUse = 5;
        WaterUse = 0;
        NutrientUse = 0;
        ressources.Sauerstoff_per_Build = 66;
        ressources.Stein_per_Build = 66;
        ressources.Strom_per_Build = 66;
        Category = BuildingCategory::Industry;
        setModel("models\\monkey.obj");
        // set model
        // set material
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 20;
        cost.Concrete = 5;
        cost.Wood = 0;
        return cost;
    }
};