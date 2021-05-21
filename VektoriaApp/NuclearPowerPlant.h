#pragma once
#include "PowerPlant.h"
class NuclearPowerPlant :
    public PowerPlant
{
public:
    NuclearPowerPlant();
    Resources getBuildCost();
};

