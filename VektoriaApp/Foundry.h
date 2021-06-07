#pragma once
#include "Building.h"
class Foundry :
    public Building
{
public:
    Foundry() {
        PowerUse = 70;
        WaterUse = 0;
        NutrientUse = 0;

        Category = BuildingCategory::Industry;

        setModel("models\\monkey.obj");
        // set material

        setAudio(&CAudioManager::Instance().Local_Foundry);
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 10;
        cost.Concrete = 60;
        cost.Wood = 0;
        return cost;
    }
};