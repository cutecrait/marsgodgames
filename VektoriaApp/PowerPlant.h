#pragma once
#include "Building.h"
class PowerPlant :
    public Building
{
public:
    int getPower();
protected:
    int power = 0;
};

