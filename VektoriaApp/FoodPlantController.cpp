#include "FoodPlantController.h"

void FoodPlantController::Init()
{
	list = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::FoodPlant);
	ready = true;
}

void FoodPlantController::Update(float delta)
{
	if (!ready) return;

	timeSinceTick += delta;
	if (timeSinceTick > tickInterval)
	{
		timeSinceTick -= tickInterval;
		for (vector<CGameObjectPlacement*>::iterator foodplant = list.begin(); foodplant != list.end(); ++foodplant)
		{
			if ((*foodplant)->getBuildStatus())
			{
				FoodPlant* f = dynamic_cast<FoodPlant*>((*foodplant)->getGameObject());

				if (!f->linkedGOP || !f->linkedGOP->getBuildStatus())
				{
					// this call could be moved to a BG thread.
					findFarm(*foodplant);
				}
				else
				{
					int value = static_cast<int>(std::round(30 * f->efficiency));
					Player::Instance().useFood(-value);
				}
			}
		}
	}
}

void FoodPlantController::findFarm(CGameObjectPlacement* plantGOP)
{
	float myX = plantGOP->GetPos().GetX();
	float myZ = plantGOP->GetPos().GetZ();

	vector<CGameObjectPlacement*> farms = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::FoodFarm);
	CGameObjectPlacement* closest = nullptr;
	float closestDistance = 10000.f;

	for (std::vector<CGameObjectPlacement*>::iterator farm = farms.begin(); farm != farms.end(); ++farm)
	{
		if ((*farm)->getBuildStatus() && dynamic_cast<FoodFarm*>((*farm)->getGameObject())->linkedPlant == nullptr)
		{
			if ((*farm)->getGameObject())
			{
				float tX = (*farm)->GetPos().GetX();
				float tZ = (*farm)->GetPos().GetZ();
				float dist = pow(myX - tX, 2) + pow(myZ - tZ, 2);
				if (dist < closestDistance)
				{
					closest = *farm;
					closestDistance = dist;
				}
			}
		}
	}
	if (closest)
	{
		FoodPlant* f = dynamic_cast<FoodPlant*>(plantGOP->getGameObject());
		f->linkedGOP = closest;
		f->linkedFarm = (FoodFarm*)closest->getGameObject();
		f->linkedFarm->linkedPlant = f;
		f->efficiency = 1.0f; // TODO set according to distance
	}
}