#pragma once
#include "Vektoria/root.h"
#include "GameObject.h"
#include "BeispielForGameObject.h"
#include "CGameObjectPlacement.h"

using namespace Vektoria;

class CBuildingManager
{
public:

	CBuildingManager();
	~CBuildingManager();
	
	// Initialisierung des BuildingManagers
	void Init(CScene*);

	// Sucht nach einem bestimmten GameObjectPlacement
	CGameObjectPlacement* lookForGameObject();

	// Update-Methode der Gebäude pro Tick
	void UpdateBuildings(float deltaTime);

	void IncreaseNrOfBuildings();
	void DecreaseNrOfBuildings();

	

private:

	CScene* m_zs;

	

	// Zum Test hier die Beispiel GameObject-Klasse
	CGameObjectPlacement BeispielGameObjects[20];

	// Für jeden Gebäudetyp bzw. für jede Kategorie feste Anzahl an Gebäuden
	// Muss noch erweitert werden!
	CGameObjectPlacement Wonhungen[50];
	CGameObjectPlacement Versorgung[50];

	// Die Anzahl an Gebäuden, die schon gebaut wurde
	// Für Statistik 
	int m_NrOfTestObjects;
	int m_NrOfWohungen;
	int m_NrOfVersorgung;

};

