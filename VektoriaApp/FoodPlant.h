#pragma once
#include "Building.h"
#include "FoodFarm.h"
#include "Player.h"
#include "CGameObjectPlacement.h"

class FoodPlant :
	public Building
{
public:
	FoodFarm* linkedFarm = nullptr;
	CGameObjectPlacement* linkedGOP = nullptr;

	float efficiency = 0.f;

	FoodPlant() {
		PowerUse = 5;
		WaterUse = 5;
		NutrientUse = 0;

		Category = BuildingCategory::Industry;

		setModel(AssetManager::Models::FoodPlant);

		this->setMaterial("textures\\FactoryTex.png");
		this->getModel()->SetMaterial(this->getMaterial());

		//setAudio(&CAudioManager::Instance().NO AUDIO);
	};

	void Update(float time)
	{
		timeSinceTick += time;
		if (timeSinceTick > tickTime)
		{
			timeSinceTick -= tickTime;

			int value = static_cast<int>(std::round(10 * efficiency));
		}
	};

	Resources getBuildCost() {
		Resources cost;
		cost.Steel = 10;
		cost.Concrete = 20;
		cost.Wood = 20;
		return cost;
	};

private:
	float timeSinceTick = 0.f;
	float tickTime = 10.0f;
};