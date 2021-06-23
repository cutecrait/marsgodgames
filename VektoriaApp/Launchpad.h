#pragma once
#include "Building.h"
class Launchpad :
    public Building
{
public:
    Launchpad() {
        PowerUse = 0;
        WaterUse = 0;
        NutrientUse = 0;

        Category = BuildingCategory::None;

        setModel(AssetManager::Models::Launchpad);
        // set material
        //setModel("models\\launchpad.obj");
        this->setMaterial("textures\\launchpad\\base_color.png");
        this->getModel()->SetMaterial(this->getMaterial());
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 0;
        cost.Concrete = 0;
        cost.Wood = 0;
        return cost;
    }
};