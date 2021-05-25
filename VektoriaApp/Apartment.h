#pragma once
#include "GameObject.h"

class Apartment :
    public GameObject
{
public:
    Apartment();
    virtual Resources getBuildCost() = 0;
};

