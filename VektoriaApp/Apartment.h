#pragma once
#include "Building.h"
class Apartment :
    public Building
{
public:
    Apartment() {
        PowerUse = 1;
        WaterUse = 1;
        NutrientUse = 4;

        Category = Living;

        setModel("models\\Barrack.obj");
	    this->getModel()->m_pmaterial->LoadPreset("Concrete");
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 10;
        cost.Concrete = 10;
        cost.Wood = 20;
        return cost;
    }
};

