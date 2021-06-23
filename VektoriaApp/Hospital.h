#pragma once
#include "Building.h"
class Hospital :
    public Building
{
public:
    Hospital() {
        PowerUse = 10;
        WaterUse = 5;
        NutrientUse = 6;

        Category = BuildingCategory::Living;

        setModel(AssetManager::Models::Hospital);
        // set material

        char* base = "textures\\HospitalTex\\HospitalTex_Base_Color.png";
        char* glow = "textures\\HospitalTex\\cross_Emissive.png";
        char* spec = "textures\\HospitalTex\\HospitalTex_Metallic.png";
        char* height = "textures\\HospitalTex\\HospitalTex_Height.png";
        char* bump = "textures\\HospitalTex\\HospitalTex_Roughness.png";


        this->setMaterial(bump, base, glow, spec, height);
        this->getModel()->SetMaterial(this->getMaterial());
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 50;
        cost.Concrete = 40;
        cost.Wood = 50;
        return cost;
    }
};