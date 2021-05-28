#pragma once
#include "Vektoria/root.h"
#include "GameObject.h"
#include "BeispielForGameObject.h"
#include "CGameObjectPlacement.h"
#include "Apartment.h"
#include "Building.h"


using namespace Vektoria;

class CBuildingManager
{
public:

	CBuildingManager();
	~CBuildingManager();

	// enum Typ - Beinhaltet alle Gebäude-Typen
	// NOCH ZU ERWEITERN!!!
	enum class Typ {NuclearPowerPlant = 0,
		SolarPowerPlant,
		Hotel,
		Apartment,
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

	

private:

	CScene* m_zs;

	// Zum Test hier die Beispiel GameObject-Klasse
	CGameObjectPlacement BeispielGameObjects[20];

	// Für jeden Gebäudetyp bzw. für jede Kategorie feste Anzahl an Gebäuden
	// Muss noch erweitert werden!
	CGameObjectPlacement Apartments[50];
	CGameObjectPlacement Versorgung[50];
	/*CGameObjectPlacement NuclearPowerPlant[20];
	CGameObjectPlacement SolarPowerPlant[20];
	CGameObjectPlacement Dome[20];
	CGameObjectPlacement WaterTank[20];*/


	// Die Anzahl an Gebäuden, die schon gebaut wurde
	int m_NrOfTestObjects;
	int m_NrOfWohungen;
	int m_NrOfVersorgung;
	int m_NrOfNuclearPerPlants;
	int m_NrOfSolarPowerPlants;
	int m_NrOfDomes;
	int m_NrOfWaterTanks;

};

