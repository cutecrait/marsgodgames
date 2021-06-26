#pragma once
#include "CGameObjectPlacement.h"
#include "CBuildingManager.h"
#include "TreeFarm.h"

class TreeFarmController
{
public:
	void Init();
	void Update(float);

private:
	bool ready = false;
	vector<CGameObjectPlacement*> list;
	int count;
	float timeSinceTick = 0.f;
	float tickInterval = 10.f;
};
