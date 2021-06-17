#include "FoundryController.h"

void FoundryController::Init()
{
	list = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::Foundry);
	ready = true;
}

void FoundryController::Update(float delta)
{
	if (!ready) return;

	timeSinceTick += delta;
	if (timeSinceTick > tickInterval)
	{
		timeSinceTick -= tickInterval;
		for (vector<CGameObjectPlacement*>::iterator foundry = list.begin(); foundry != list.end(); ++foundry)
		{
			Foundry* gp = dynamic_cast<Foundry*>((*foundry)->getGameObject());

			if (!gp->linkedGOP || !gp->linkedGOP->getBuildStatus())
			{
				// this call could be moved to a BG thread.
				findMine(*foundry);
			}
		}
	}
}

void FoundryController::findMine(CGameObjectPlacement* foundryGOP)
{
	float myX = foundryGOP->GetPos().GetX();
	float myZ = foundryGOP->GetPos().GetZ();

	vector<CGameObjectPlacement*> mines = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::Mine);
	CGameObjectPlacement* closest = nullptr;
	float closestDistance = 10000.f;

	for (std::vector<CGameObjectPlacement*>::iterator mine = mines.begin(); mine != mines.end(); ++mine)
	{
		if ((*mine)->getBuildStatus() && dynamic_cast<Mine*>((*mine)->getGameObject())->linkedFoundry != nullptr)
		{
			if ((*mine)->getGameObject())
			{
				float tX = (*mine)->GetPos().GetX();
				float tZ = (*mine)->GetPos().GetZ();
				float dist = pow(myX - tX, 2) + pow(myZ - tZ, 2);
				if (dist > closestDistance)
				{
					closest = *mine;
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
		f->efficiency = 1.0f; // TODO set according to distance
	}
}