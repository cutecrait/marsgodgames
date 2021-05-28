#pragma once
#include "GameObject.h"

enum BuildingCategory {
    None,
    Living,
    Farming,
    Industry,
    Robotics
};


class Building :
    public GameObject
{
public:
    virtual Resources getBuildCost() = 0;
    int PowerUse;
    int WaterUse;
    int NutrientUse;
    BuildingCategory Category = None;
};

