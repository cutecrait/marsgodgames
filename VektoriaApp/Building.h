#pragma once
#include "GameObject.h"
class Building :
    public GameObject
{
public:
    virtual Resources getBuildCost() = 0;
};

