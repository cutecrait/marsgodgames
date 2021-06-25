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
        howMuch = 5;
        Category = BuildingCategory::Industry;

        setModel(AssetManager::Models::GravelPlant);
       // setModel("models\\foerderband+stein.obj");
        this->setMaterial("textures\\foerderband\\base_color.png");
        this->getModel()->SetMaterial(this->getMaterial());
        // set material

        setAudio(&CAudioManager::Instance().Local_GravelPlant);
    }
    //diese funktion ist f�r das kleine popup was auftaucht wenn man �ber die ressoucen hovered.
    //ausgef�hrt wird die in buildingmanager addnewbuilding
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