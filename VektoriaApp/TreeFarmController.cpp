#include "TreeFarmController.h"

void TreeFarmController::Init()
{
	list = CBuildingManager::Instance().GetBuildingVector(CBuildingManager::Typ::TreeFarm);
	ready = true;
}

void TreeFarmController::Update(float delta)
{
	if (!ready) return;

	timeSinceTick += delta;
	if (timeSinceTick > tickInterval)
	{
		timeSinceTick -= tickInterval;
		for (vector<CGameObjectPlacement*>::iterator treefarm = list.begin(); treefarm != list.end(); ++treefarm)
		{
			if ((*treefarm)->getBuildStatus())
			{
				TreeFarm* tf = dynamic_cast<TreeFarm*>((*treefarm)->getGameObject());

				int value = static_cast<int>(std::round(10 * tf->efficiency) +
					(Player::Instance().GetWoodRobotEfficiency() * Player::Instance().GetWoodRobot()));
				Player::Instance().gainWood(value);
			}
		}
	}
}
