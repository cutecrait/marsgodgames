#pragma once
#include "Building.h"
class Mine :
    public Building
{
public:
    Mine() {
        PowerUse = 30;
        WaterUse = 2;
        NutrientUse = 0;

        Category = BuildingCategory::Industry;

        setModel("models\\monkey.obj");
        // set material
        setAudio(&CAudioManager::Instance().Local_Mine);
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 20;
        cost.Concrete = 80;
        cost.Wood = 60;
        return cost;
    }
};
