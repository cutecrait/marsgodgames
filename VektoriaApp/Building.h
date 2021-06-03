#pragma once
#include "GameObject.h"
#include "popup.h"
enum class BuildingCategory {
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
    virtual void OnClick() {}
    virtual bool decision() { return true; }
    virtual void setPopup(popup*){}
    int PowerUse;
    int WaterUse;
    int NutrientUse;
    BuildingCategory Category = BuildingCategory::None;
};

