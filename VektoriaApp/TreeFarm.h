#pragma once
#include "Building.h"

class TreeFarm :
    public Building
{
public:
    TreeFarm() {
        PowerUse = 5;
        WaterUse = 3;
        NutrientUse = 1;

        Category = BuildingCategory::Farming;

        setModel(AssetManager::Models::TreeFarm);


        char* base = "textures\\TreefarmTex\\TreefarmTex_Base_Color.png";
        char* glow = "textures\\TreefarmTex\\TreefarmTex_Emissive.png";
        char* spec = "textures\\TreefarmTex\\TreefarmTex_Metallic.png";
        char* height = "textures\\TreefarmTex\\TreefarmTex_Height.png";
        char* bump = "textures\\TreefarmTex\\TreefarmTex_Roughness.png";


        this->setMaterial(bump, base, glow, spec, height);
        this->getModel()->SetMaterial(this->getMaterial());
        // set material
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 20;
        cost.Concrete = 20;
        cost.Wood = 0;
        return cost;
    }
};