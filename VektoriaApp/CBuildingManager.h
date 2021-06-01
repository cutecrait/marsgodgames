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

class CBuildingManager
{
public:

	CBuildingManager();
	~CBuildingManager();

	// enum Typ - Beinhaltet alle Gebäude-Typen
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

	// Update-Methode der Gebäude pro Tick
	void UpdateBuildings(float deltaTime);

	void IncreaseNrOfBuildings(Typ&);
	void DecreaseNrOfBuildings(Typ&);

	void AddNewBuilding(Typ, MapTile*);
	

private:

	CScene* m_zs;

	// Für jeden Gebäudetyp bzw. für jede Kategorie feste Anzahl an Gebäuden
	// Muss noch erweitert werden!
	CGameObjectPlacement Apartments[20];
	CGameObjectPlacement RoboFabrik[5];
	CGameObjectPlacement NuclearPowerPlants[20];
	CGameObjectPlacement SolarPowerPlants[20];
	CGameObjectPlacement FoodFarms[20];
	CGameObjectPlacement Foundrys[20];
	CGameObjectPlacement GravelPlants[20];
	CGameObjectPlacement Hospitals[20];
	CGameObjectPlacement Mines[20];
	CGameObjectPlacement Laboratorys[20];
	CGameObjectPlacement TreeFarms[20];
	CGameObjectPlacement Wells[20];

	CGameObjectPlacement ControlCenter_;
	CGameObjectPlacement LaunchPad;
		


	// Die Anzahl an Gebäuden, die schon gebaut wurde
	int m_NrOfApartment;
	int m_NrOfNuclearPerPlants;
	int m_NrOfSolarPowerPlants;
	int m_NrOfRoboFabrik;
	int m_NrOfFoodFarms;
	int m_NrOfFoundrys;
	int m_NrOfGravelPlants;
	int m_NrOfHospitals;
	int m_NrOfMines;
	int m_NrOfLaboratorys;
	int m_NrOfTreeFarms;
	int m_NrOfWells;
};

