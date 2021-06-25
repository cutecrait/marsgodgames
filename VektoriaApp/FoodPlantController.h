#pragma once
#include "CGameObjectPlacement.h"
#include "CBuildingManager.h"
#include "FoodPlant.h"

class FoodPlantController
{
public:
	void Init();
	void Update(float);

private:
	void findFarm(CGameObjectPlacement*);
	bool ready = false;
	vector<CGameObjectPlacement*> list;
	int count;
	float timeSinceTick = 0.f;
	float tickInterval = 10.f;
};
