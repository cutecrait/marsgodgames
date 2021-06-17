#pragma once
#include "CGameObjectPlacement.h"
#include "CBuildingManager.h"
#include "Foundry.h"

class FoundryController
{
public:
	void Init();
	void Update(float);

private:
	void findMine(CGameObjectPlacement*);
	bool ready = false;
	vector<CGameObjectPlacement*> list;
	int count;
	float timeSinceTick = 0.f;
	float tickInterval = 10.f;
};
