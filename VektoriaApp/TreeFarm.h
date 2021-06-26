#pragma once
#include "Building.h"

class TreeFarm :
    public Building
{
public:
    float efficiency = 1.f;

    TreeFarm() {

        PowerUse = 5;
        WaterUse = 3;
        NutrientUse = 1;

        Category = BuildingCategory::Farming;

        setModel(AssetManager::Models::TreeFarm);


        char* base = "textures\\TreefarmTex\\TreefarmTex_Base_Color.png";
        char* glow = "textures\\TreefarmTex\\TreefarmTex_Emissive2.png";
        char* spec = "textures\\TreefarmTex\\TreefarmTex_Metallic.png";
        char* height = "textures\\TreefarmTex\\TreefarmTex_Height.png";
        char* bump = "textures\\TreefarmTex\\TreefarmTex_Roughness.png";
        char* sprite = "textures\\TreefarmTex\\TreefarmTex_Sprite.png";


        this->setMaterial(bump, base, glow, spec, height);
        //this->getMaterial()->MakeTextureThickness(sprite, CColor(1.0, 1.0, 1.0, 1.0));
        
        
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