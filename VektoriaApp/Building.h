#pragma once
#include "GameObject.h"
#include "CAudioManager.h"
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
    virtual void destroy() {}
    virtual void OnClick() {}
    virtual int decision() { return true; }
    virtual void setPopup(popup*){}
    virtual int getResult(int) { return 0; }
    virtual bool hasPopup() { return false; }


    int PowerUse;
    int WaterUse;
    int NutrientUse;
    BuildingCategory Category = BuildingCategory::None;
};

