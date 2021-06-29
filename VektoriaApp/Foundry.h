#pragma once
#include "Building.h"
#include "Mine.h"
#include "Player.h"
#include "CGameObjectPlacement.h"

class Foundry :
	public Building
{
public:
	Mine* linkedMine = nullptr;
	CGameObjectPlacement* linkedGOP = nullptr;
	
	float efficiency = 0.f;

	Foundry() {
		PowerUse = 70;
		WaterUse = 0;
		NutrientUse = 0;
		howMuch = 10;
		Category = BuildingCategory::Industry;

		setModel(AssetManager::Models::Foundry);

        this->setMaterial("textures\\FoundryTex.png");
        this->getModel()->SetMaterial(this->getMaterial());

		setAudio(&CAudioManager::Instance().Local_Foundry);
	}
	void updatePlayer() override {
		Player::Instance().setSteelPM(howMuch);
	};

	void Update(float time)
	{
		timeSinceTick += time;
		if (timeSinceTick > tickTime)
		{
			timeSinceTick -= tickTime;

			int value = static_cast<int>(std::round(10 * efficiency) +
				(Player::Instance().GetSteelRobotEfficiency() * Player::Instance().GetSteelRobot()));
			Player::Instance().gainSteel(value);
		}
	};

	Resources getBuildCost() {
		Resources cost;
		cost.Steel = 10;
		cost.Concrete = 60;
		cost.Wood = 0;
		return cost;
	};

private:
	float timeSinceTick = 0.f;
	float tickTime = 10.0f;
};