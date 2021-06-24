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
    //diese funktion ist für das kleine popup was auftaucht wenn man über die ressoucen hovered.
    //ausgeführt wird die in buildingmanager addnewbuilding
    void updatePlayer() override {
        Player::Instance().setConcretePM(howMuch);
    };
    void Update(float time)
    {
        timeSinceTick += time;
        if (timeSinceTick > tickTime)
        {
            timeSinceTick -= tickTime;

            int value = static_cast<int>(std::round(10 * efficiency));
            Player::Instance().gainConcrete(value);
        }
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