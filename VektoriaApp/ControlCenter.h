#pragma once
#include "Building.h"
class ControlCenter :
    public Building
{
public:
    ControlCenter() {
        PowerUse = 0;
        WaterUse = 0;
        NutrientUse = 0;

        Category = BuildingCategory::None;

        setModel("models\\monkey.obj");
        // set material
        
        setAudio(&CAudioManager::Instance().Local_ControlCenter);

    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 0;
        cost.Concrete = 0;
        cost.Wood = 0;
        return cost;
    }
};