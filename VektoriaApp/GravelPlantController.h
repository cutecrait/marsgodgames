#pragma once
#include "CGameObjectPlacement.h"
#include "CBuildingManager.h"
#include "GravelPlant.h"

class GravelPlantController
{
public:
	void Init();
	void Update(float);

private:
	void findMine(CGameObjectPlacement*);
	bool ready = false;
	vector<CGameObjectPlacement*> list;
	float timeSinceTick = 0.f;
	float tickInterval = 10.f;
};
