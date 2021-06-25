#pragma once
#include "GameObject.h"

class testRobo : public GameObject
{
public:
	testRobo();
	~testRobo();
	Resources getRessources() override {
		Resources cost;
		cost.Steel = 10;
		cost.Concrete = 15;
		cost.Wood = 3;
		return cost;
	};

	
};

