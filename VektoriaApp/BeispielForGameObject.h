#pragma once
#include "GameObject.h"

class BeispielForGameObject :
    public GameObject
{
public:

    BeispielForGameObject();
    ~BeispielForGameObject();

    void Init();
    CMaterial mat;
   
};

