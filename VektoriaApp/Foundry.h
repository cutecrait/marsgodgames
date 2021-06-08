#pragma once
#include "Building.h"
#include "Mine.h"
#include "Player.h"
#include "CGameObjectPlacement.h"

class Foundry :
    public Building
{
public:
    CGameObjectPlacement* linkedMine = nullptr;

    Foundry() {
        PowerUse = 70;
        WaterUse = 0;
        NutrientUse = 0;

        Category = BuildingCategory::Industry;

        setModel("models\\monkey.obj");
        // set material

        setAudio(&CAudioManager::Instance().Local_Foundry);
    };


    void Update(float time)
    {
        timeSinceTick += time;
        if (timeSinceTick > checkTime)
        {
            timeSinceTick -= checkTime;
            if (!linkedMine)
            {
                //CBuildingManager::GetBuildingVector(CBuildingManager::Typ::Mine);

            }

            return;
        }

        if(timeSinceTick > tickTime)
        {
            timeSinceTick -= tickTime;
            // per default, gain 10 steel per 10 seconds.
            Player::Instance().gainSteel(10);
        }
    };

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 10;
        cost.Concrete = 60;
        cost.Wood = 0;
        return cost;
    };

private:
    float timeSinceTick = 0.f;
    float tickTime = 10.0f;
    float checkTime = 1.0f;
};