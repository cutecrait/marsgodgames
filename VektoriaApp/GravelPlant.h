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

        Category = BuildingCategory::Industry;

        setModel("models\\monkey.obj");
        // set material

        setAudio(&CAudioManager::Instance().Local_GravelPlant);
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