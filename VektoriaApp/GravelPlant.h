#pragma once
#include "Building.h"
#include "Mine.h"
#include "Player.h"
#include "CGameObjectPlacement.h"

class GravelPlant :
    public Building
{
public:
    Mine* linkedMine = nullptr;
    CGameObjectPlacement* linkedGOP = nullptr;

    float efficiency = 0.f;

    GravelPlant() {
        PowerUse = 10;
        WaterUse = 10;
        NutrientUse = 0;
        howMuch = 10;
        Category = BuildingCategory::Industry;

        setModel(AssetManager::Models::GravelPlant);
       // setModel("models\\foerderband+stein.obj");

        char* base = "textures\\GravelTex\\GravelTex_Base_Color.png";
        char* glow = "textures\\GravelTex\\GravelTex_Emissive.png";
        char* spec = "textures\\GravelTex\\GravelTex_Metallic.png";
        char* height = "textures\\GravelTex\\GravelTex_Height.png";
        char* bump = "textures\\GravelTex\\GravelTex_Roughness.png";


        this->setMaterial(bump, base, glow, spec, height);
        this->getModel()->SetMaterial(this->getMaterial());

        setAudio(&CAudioManager::Instance().Local_GravelPlant);
    }
    //diese funktion ist für das kleine popup was auftaucht wenn man über die ressoucen hovered.
    //ausgeführt wird die in buildingmanager addnewbuilding
    void updatePlayer() override {
        Player::Instance().setConcretePM(howMuch);
    };
    void Update(float time)
    {

    };

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 10;
        cost.Concrete = 20;
        cost.Wood = 20;
        return cost;
    };

private:
    float timeSinceTick = 0.f;
    float tickTime = 10.0f;
};