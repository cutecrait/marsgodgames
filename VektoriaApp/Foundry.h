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

        setModel("models\\Foundry.obj");
        this->setMaterial("textures\\FoundryTex.png");
        this->getModel()->SetMaterial(this->getMaterial());

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