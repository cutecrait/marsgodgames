#pragma once
#include "Vektoria\root.h"
#include "UI.h"
#include "GuiButton.h"
#include "GuiSelect.h"
#include "BeispielForGameObject.h"
#include "MapTile.h"
#include "CAudioManager.h"
#include "CBuildingManager.h"
#include "Save.h"

using namespace Vektoria;
class clickmanager
{
public:
	clickmanager();
	~clickmanager();

	void menuOFF();
	void Click(float,  CDeviceCursor*);
	void Init(UI* menu, CScene* zs, CAudioManager* am, Player* player, CBuildingManager* bm, MapSquare* squares) {
		
		//Übergebe die UI
		m_menu = menu;

		// Übergebe den Bau-Sounds
		Building_Sound = &(am->Ambient_Building_Sound);

		// Übergebe die Spielerstatistik
		m_playerStats = player;

		// Übergebe den BuildingManager (Zugriff auf die Gebäude im Spiel)
		BuildingManager = bm;

		mapsquares = squares;
	}

	void makeBuilding(CGameObjectPlacement*);
	bool enoughRes(GameObject*);

	void confirmClicked();

	void cancelClicked(CGameObjectPlacement* );
	bool createToolTip(int);
private:



	//std::vector <CMaterial*> m_MATbuildingKind;
	int whatKind;
	int activePosition = -1;
	int WhatSpecific = 1;
	int unterschied = -1;
	bool toolTipCreate = true;
	bool clicked = false;
	bool isclicked = false;
	CAudio* Building_Sound;

	// Objekt, das gebaut werden soll (bzw. im Moment platziert werden kann)
	CGameObjectPlacement* toBeBuildObject;
	CBuildingManager* BuildingManager;
	MapSquare* mapsquares;
	CPlacement* targetPos;
	Player* m_playerStats;
	UI* m_menu;

	/*BeispielForGameObject MONKY;
	BeispielForGameObject* Wohnung[20];*/

	// Karo: Save um Checkpoint zu setzen
	Save save;
	bool saveable = true;

};

