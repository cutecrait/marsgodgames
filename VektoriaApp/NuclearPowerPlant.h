#pragma once
#include "Building.h"
class NuclearPowerPlant :
    public Building
{
public:
    NuclearPowerPlant() {
        PowerUse = -240;
        WaterUse = 5;
        NutrientUse = 0;

        Category = BuildingCategory::Industry;

        setModel("models\\kraftwerk.obj");
        //this->getModel()->m_pmaterial->LoadPreset("Concrete");
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 120;
        cost.Concrete = 180;
        cost.Wood = 40;
        return cost;
    }
};