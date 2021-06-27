#pragma once
#include "Building.h"
class OxygenTank :
    public Building
{
public:
    OxygenTank() {
        PowerUse = 10;
        WaterUse = 0; 
        NutrientUse = 0;
        howMuch = 60;
        //Category = BuildingCategory::Farming;

        setModel(AssetManager::Models::OxygenTank);

        char* base = "textures\\OxygenTex\\Base_ani.png";
        char* glow = "textures\\OxygenTex\\Emissive_ani.png";
        char* spec = "textures\\OxygenTex\\Metallic_ani.png";
        char* bump = "textures\\OxygenTex\\Roughness_ani.png";


        this->setMaterial(base, bump, glow, spec, 3, 5, 6);
        this->getModel()->SetMaterial(this->getMaterial());


        
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 50;
        cost.Concrete = 10;
        cost.Wood = 0;
        return cost;
    }
    
};
