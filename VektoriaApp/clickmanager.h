#pragma once
#include "Vektoria\root.h"
#include "UI.h"
#include "GuiButton.h"
#include "GuiSelect.h"
#include "BeispielForGameObject.h"
#include "MapTile.h"
#include "CAudioManager.h"

#include "Save.h"
#include "LevelManager.h"
#include "Building.h"

using namespace Vektoria;
class clickmanager
{
public:
	clickmanager();
	~clickmanager();

	void menuOFF();
	void Click(float,  CDeviceCursor*,LevelSystem::Level*);
	void Init(UI* menu, CScene* zs, CBuildingManager* bm, MapSquare* squares) {
		
		//Übergebe die UI
		m_menu = menu;

		// Übergebe den BuildingManager (Zugriff auf die Gebäude im Spiel)
		BuildingManager = bm;

		mapsquares = squares;
	}

	void makeBuilding(CGameObjectPlacement*);
	bool enoughRes(Building*);

	void confirmClicked();
	void setBuildingGeos(CGeos*);

	void cancelClicked(CGameObjectPlacement* );
	bool createToolTip(int);
	void uiDecision(CBuildingManager::Typ, std::string,CDeviceCursor*);
	void switchButtonClick(int,LevelSystem::Level*);
	void popUpButtonClick(CDeviceCursor* cursor, LevelSystem::Level* currentLevel);
	bool openPopup(CDeviceCursor*);
	
private:

	CBuildingManager::Typ typforUiDecsion;

	//std::vector <CMaterial*> m_MATbuildingKind;
	int whatKind;
	int activePosition = -1;
	int WhatSpecific = 1;
	int unterschied = -1;
	bool toolTipCreate = true;
	bool clicked = false;
	bool isclicked = false;
	bool roboPopUpopen = false;
	// Objekt, das gebaut werden soll (bzw. im Moment platziert werden kann)
	CGameObjectPlacement* toBeBuildObject;
	Building* toBeBuiltBuilding;
	CBuildingManager* BuildingManager;
	MapSquare* mapsquares;
	CPlacement* targetPos;
	UI* m_menu;
	CBuildingManager::Typ dumyTyp = CBuildingManager::Typ::None;
	/*BeispielForGameObject MONKY;
	BeispielForGameObject* Wohnung[20];*/

	CGeos* BuildingModels;

	// Karo: Save um Checkpoint zu setzen
	Save save;
	bool saveable = true;
	MapTile* pickedTile = nullptr;
	MapTile* TileForAddNewBuilding = nullptr;
	Building* BuildingForEffi;
	CGameObjectPlacement* forEffi;
	bool notInMenu = false;
	CGeo* selectedGeo;
	Building* selectedBuilding;
	bool oneTimeSetPopup = true;
	std::string ss;
	bool erstesMal = true;
	CGameObjectPlacement* selectedPlacement;
	Building::Resources buildCost;
};

