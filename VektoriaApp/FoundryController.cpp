#include "FoundryController.h"

void FoundryController::Init(CGameObjectPlacement* foundryList,  int len)
{
	count = len;
	list = foundryList;
	ready = true;
}

void FoundryController::Update(float delta)
{
	if (!ready) return;

	timeSinceTick += delta;
	if (timeSinceTick > tickInterval)
	{
		timeSinceTick -= tickInterval;
		for (int i = 0; i < count; i++)
		{
			Foundry* f = dynamic_cast<Foundry*>(list[i].getGameObject());

			if (!f->linkedGOP || !f->linkedGOP->getBuildStatus())
			{
				// this call could be moved to a BG thread.
				findMine(&list[i]);
			}
		}
	}
}

void FoundryController::findMine(CGameObjectPlacement* foundryGOP)
{
	float myX = foundryGOP->GetPos().GetX();
	float myZ = foundryGOP->GetPos().GetZ();

	vector<CGameObjectPlacement> mines = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::Mine);
	CGameObjectPlacement* closest = nullptr;
	float closestDistance = 10000.f;

	for (std::vector<CGameObjectPlacement>::iterator mine = mines.begin(); mine != mines.end(); ++mine)
	{
		if (dynamic_cast<Mine*>(mine->getGameObject())->linkedFoundry != nullptr)
		{
			if (mine->getGameObject())
			{
				float tX = mine->GetPos().GetX();
				float tZ = mine->GetPos().GetZ();
				float dist = pow(myX - tX, 2) + pow(myZ - tZ, 2);
				if (dist > closestDistance)
				{
					closest = &*mine;
					closestDistance = dist;
				}
			}
		}
	}
	if (closest)
	{
		Foundry* f = dynamic_cast<Foundry*>(foundryGOP->getGameObject());
		f->linkedGOP = closest;
		f->linkedMine = (Mine*)closest->getGameObject();
		f->linkedMine->linkedFoundry = f;
	}
}