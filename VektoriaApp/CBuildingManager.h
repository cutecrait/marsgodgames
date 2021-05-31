#pragma once
#include "Vektoria/root.h"
#include "GameObject.h"
#include "BeispielForGameObject.h"
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
#include "RobotFactory.h"

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
		Well,

		Hotel,
		Villa,
		WaterTank,
		Dome,
		Test};
	
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

	// Zum Test hier die Beispiel GameObject-Klasse
	CGameObjectPlacement BeispielGameObjects[20];

	// Für jeden Gebäudetyp bzw. für jede Kategorie feste Anzahl an Gebäuden
	// Muss noch erweitert werden!
	CGameObjectPlacement Apartments[50];
	CGameObjectPlacement Versorgung[50];
	CGameObjectPlacement RoboFabrik[5];
	/*CGameObjectPlacement NuclearPowerPlant[20];
	CGameObjectPlacement SolarPowerPlant[20];
	CGameObjectPlacement Dome[20];
	CGameObjectPlacement WaterTank[20];*/


	// Die Anzahl an Gebäuden, die schon gebaut wurde
	int m_NrOfTestObjects;
	int m_NrOfApartment;
	int m_NrOfVersorgung;
	int m_NrOfNuclearPerPlants;
	int m_NrOfSolarPowerPlants;
	int m_NrOfDomes;
	int m_NrOfWaterTanks;
	int m_NrOfRoboFabrik;
};

