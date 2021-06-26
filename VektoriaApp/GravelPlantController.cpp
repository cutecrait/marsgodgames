#include "GravelPlantController.h"

using namespace std;

void GravelPlantController::Init()
{
	list = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::GravelPlant);
	ready = true;
}

void GravelPlantController::Update(float delta)
{
	if (!ready) return;

	timeSinceTick += delta;
	if (timeSinceTick > tickInterval)
	{
		timeSinceTick -= tickInterval;
		for (vector<CGameObjectPlacement*>::iterator gravelPlant = list.begin(); gravelPlant != list.end(); ++gravelPlant)
		{
			if ((*gravelPlant)->getBuildStatus())
			{
				GravelPlant* gp = dynamic_cast<GravelPlant*>((*gravelPlant)->getGameObject());

				if (!gp->linkedGOP || !gp->linkedGOP->getBuildStatus())
				{
					// this call could be moved to a BG thread.
					findMine(*gravelPlant);
				}
				else
				{
					//+ RobotEffizienz
					int value = static_cast<int>(std::round((10 * gp->efficiency) +
						(Player::Instance().GetConcreteRobotEfficiency() * Player::Instance().GetConcreteRobot())));
					Player::Instance().gainConcrete(value);
				}
			}
		}
	}
}

void GravelPlantController::findMine(CGameObjectPlacement* gpGOP)
{
	float myX = gpGOP->GetPos().GetX();
	float myZ = gpGOP->GetPos().GetZ();

	vector<CGameObjectPlacement*> mines = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::Mine);
	CGameObjectPlacement* closest = nullptr;
	float closestDistance = 10000.f;

	for (vector<CGameObjectPlacement*>::iterator mine = mines.begin(); mine != mines.end(); ++mine)
	{
		if ((*mine)->getBuildStatus() && dynamic_cast<Mine*>((*mine)->getGameObject())->linkedGravelPlant == nullptr)
		{
			if ((*mine)->getGameObject())
			{
				float tX = (*mine)->GetPos().GetX();
				float tZ = (*mine)->GetPos().GetZ();
				float dist = pow(myX - tX, 2) + pow(myZ - tZ, 2);
				if (dist < closestDistance)
				{
					closest = *mine;
					closestDistance = dist;
				}
			}
		}
	}
	if (closest)
	{
		GravelPlant* gp = dynamic_cast<GravelPlant*>(gpGOP->getGameObject());
		gp->linkedGOP = closest;
		gp->linkedMine = (Mine*)closest->getGameObject();
		gp->linkedMine->linkedGravelPlant = gp;
		gp->efficiency = 1.0f; // TODO set according to distance
	}
}