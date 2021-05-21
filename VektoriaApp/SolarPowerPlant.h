#pragma once
#include "PowerPlant.h"
class SolarPowerPlant :
    public PowerPlant
{
public:
    SolarPowerPlant();
    Resources getBuildCost();
};
