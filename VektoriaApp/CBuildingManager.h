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
	

private:
	CScene* m_zs;

	CGameObjectPlacement Apartments[50];
	CGameObjectPlacement ControlCenters[50];
	CGameObjectPlacement FoodFarms[50];
	CGameObjectPlacement Foundrys[50];
	CGameObjectPlacement GravelPlants[50];
	CGameObjectPlacement Hospitals[50];
	CGameObjectPlacement Laboratorys[50];
	CGameObjectPlacement Launchpads[50];
	CGameObjectPlacement Mines[50];
	CGameObjectPlacement NuclearPowerPlants[50];
	CGameObjectPlacement RobotFactorys[50];
	CGameObjectPlacement SolarPowerPlants[50];
	CGameObjectPlacement TreeFarms[50];
	CGameObjectPlacement Wells[50];

	// Die Anzahl an Buildings, die schon gebaut wurde
	int m_NrsOfBuildings[TYP_LENGTH];
};

