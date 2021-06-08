#pragma once
#include "Vektoria/root.h"
#include "CGameObjectPlacement.h"
#include "CAudioManager.h"
#include "Player.h"
#include "Save.h"

#include "Apartment.h"
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

const int TYP_LENGTH = 20;

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
		Apartment,
		ControlCenter,
		FoodFarm,
		Foundry,
		GravelPlant,
		Hospital,
		Laboratory,
		Launchpad,
		Mine,
		NuclearPowerPlant,
		RobotFactory,
		SolarPowerPlant,
		TreeFarm,
		Well};
	
	// Initialisierung des BuildingManagers
	void Init(CScene*);

	// Sucht nach einem bestimmten GameObjectPlacement
	CGameObjectPlacement* lookForGameObject(Typ&);

	// Update-Methode der Geb�ude pro Tick
	void UpdateBuildings(float deltaTime);

	void IncreaseNrOfBuildings(Typ&);
	void DecreaseNrOfBuildings(Typ&);

	void AddNewBuilding(Typ, MapTile*);

	vector<CGameObjectPlacement> GetBuildingVector(Typ);

private:
	CScene* m_zs;

	CGameObjectPlacement Apartments[50];
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

