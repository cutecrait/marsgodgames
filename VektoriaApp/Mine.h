#pragma once
#include "Building.h"
#include "CGameObjectPlacement.h"

class Mine :
    public Building
{
public:
    GameObject* linkedFoundry = nullptr;
    GameObject* linkedGravelPlant = nullptr;

    Mine() {
        PowerUse = 30;
        WaterUse = 2;
        NutrientUse = 0;

        Category = BuildingCategory::Industry;

        setModel(AssetManager::Models::Mine);
        // set material
        setAudio(&CAudioManager::Instance().Local_Mine);
    };

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 20;
        cost.Concrete = 80;
        cost.Wood = 60;
        return cost;
    };
};
