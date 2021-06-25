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
        char* base = "textures\\launchpad\\base_color.png";
        char* glow = "textures\\launchpad\\emissive.png";
        char* spec = "textures\\launchpad\\metallic.png";
        char* height = "textures\\launchpad\\height.png";
        char* bump = "textures\\launchpad\\roughness.png";

        this->setMaterial(bump, base, glow, spec, height);
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