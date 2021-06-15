#pragma once
#include "CGameObjectPlacement.h"
#include "CBuildingManager.h"
#include "Foundry.h"

class GravelPlantController
{
public:
	void Init(CGameObjectPlacement*, int);
	void Update(float);

private:
	void findMine(CGameObjectPlacement*);
	bool ready = false;
	CGameObjectPlacement* list;
	int count;
	float timeSinceTick = 0.f;
	float tickInterval = 10.f;
};
