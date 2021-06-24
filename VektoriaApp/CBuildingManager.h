#pragma once
#include <functional>
#include "Vektoria/root.h"
#include "CGameObjectPlacement.h"
#include "CAudioManager.h"
#include "Player.h"
#include "Save.h"

#include "Apartment.h"
#include "Barrack.h"
#include "ControlCenter.h"
#include "FoodFarm.h"
#include "Foundry.h"
#include "GravelPlant.h"
#include "Hospital.h"
#include "Laboratory.h"
#include "Launchpad.h"
#include "Mine.h"
#include "NuclearPowerPlant.h"
#include "RobotFactory.h"
#include "SolarPowerPlant.h"
#include "TreeFarm.h"
#include "Well.h"
#include "MapTile.h"

using namespace Vektoria;

const int TYP_LENGTH = 16;

class CBuildingManager
{
public:

	/// <summary>
	/// Singleton - gibt Instanz zurück
	/// </summary>
	/// <returns>Instanz</returns>
	static CBuildingManager& Instance()
	{
		static CBuildingManager _instance;
		return _instance;
	};

	CBuildingManager();
	~CBuildingManager();

	// enum Typ - Beinhaltet alle Geb�ude-Typen
	// NOCH ZU ERWEITERN!!!
	enum class Typ {
		None = 0,
		Barrack,
		Apartment,
		ControlCenter,
		FoodFarm,
		Foundry = 5,
		GravelPlant,
		Hospital,
		Laboratory,
		Launchpad,
		Mine = 10,
		NuclearPowerPlant,
		RobotFactory,
		SolarPowerPlant,
		TreeFarm,
		Well = 15};
	
	// Initialisierung des BuildingManagers
	void Init(CScene*);

	// Sucht nach einem bestimmten GameObjectPlacement
	CGameObjectPlacement* lookForGameObject(Typ&);

	// Update-Methode der Geb�ude pro Tick
	void UpdateBuildings(float deltaTime);

	void IncreaseNrOfBuildings(Typ&);
	void DecreaseNrOfBuildings(Typ&);

	void AddNewBuilding(Typ, MapTile*);
	void AddNewBuilding(Typ, float x, float z);

	vector<CGameObjectPlacement*> GetBuildingVector(Typ);

	// DEPRECATED but i'll leave it here for now in case we need it later on
	// only works for Foundry, is used to get closest Mine building with no linked Foundry
	// will later work in the same way for FoodPlant / FoodFarm
	CGameObjectPlacement* findClosestUnlinked(Building* me, Typ t_me, Typ target, function<bool(GameObject*)>);

	CGeos* getBuildingGeos();

private:
	CScene* m_zs;

	CGeos BuildingGeos;

	CGameObjectPlacement Apartments[50];
	CGameObjectPlacement Barracks[50];
	CGameObjectPlacement ControlCenters[1];
	CGameObjectPlacement FoodFarms[20];
	CGameObjectPlacement Foundrys[20];
	CGameObjectPlacement GravelPlants[20];
	CGameObjectPlacement Hospitals[5];
	CGameObjectPlacement Laboratorys[5];
	CGameObjectPlacement Launchpads[1];
	CGameObjectPlacement Mines[20];
	CGameObjectPlacement NuclearPowerPlants[10];
	CGameObjectPlacement RobotFactorys[2];
	CGameObjectPlacement SolarPowerPlants[20];
	CGameObjectPlacement TreeFarms[20];
	CGameObjectPlacement Wells[30];

	// Die Anzahl an Buildings, die schon gebaut wurde
	int m_NrsOfBuildings[TYP_LENGTH];
	int m_MaxBuildings[TYP_LENGTH];
	CGameObjectPlacement* getBuildingList(Typ);
};

