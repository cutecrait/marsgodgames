#pragma once
#include "Building.h"
class SolarPowerPlant :
    public Building
{
public:
    SolarPowerPlant() {
        PowerUse = -80;
        WaterUse = 0;
        NutrientUse = 0;

        Category = BuildingCategory::Industry;

        setModel("models\\kraftwerk.obj");
        this->getModel()->m_pmaterial->LoadPreset("Concrete");
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 50;
        cost.Concrete = 10;
        cost.Wood = 0;
        return cost;
    }
};