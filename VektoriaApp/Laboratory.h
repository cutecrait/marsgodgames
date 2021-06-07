#pragma once
#include "Building.h"
class Laboratory :
    public Building
{
public:
    Laboratory() {
        PowerUse = 20;
        WaterUse = 2;
        NutrientUse = 0;

        Category = BuildingCategory::Living;

        setModel("models\\monkey.obj");
        // set material

        setAudio(&CAudioManager::Instance().Local_Laboratory);
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 40;
        cost.Concrete = 20;
        cost.Wood = 20;
        return cost;
    }
};