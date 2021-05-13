#pragma once
#include "Vektoria\root.h"
#include "UI.h"
#include "GuiButton.h"
#include "GuiSelect.h"
#include "BeispielForGameObject.h"
#include "CAudioManager.h"

using namespace Vektoria;
class clickmanager
{
public:
	clickmanager();
	~clickmanager();

	void menuOFF();
	void Click(float, CPlacement*, CDeviceCursor*);
	void Init(UI* menu, CScene* zs, CAudioManager* am, Player* player) {
		m_menu = menu;
		MONKY.Init(100, 100, 100);
		MONKY.getPlacement()->SwitchOff();
		zs->AddPlacement(MONKY.getPlacement());
		for (int i = 0; i < 20; i++) {
			Wohnung[i] = new BeispielForGameObject();
			Wohnung[i]->getPlacement()->SwitchOff();
			zs->AddPlacement(Wohnung[i]->getPlacement());

		}

		Building_Sound = &(am->Ambient_Building_Sound);
		m_playerStats = player;
	}
	void makeBuilding(CPlacement*, CPlacement*);
	bool enoughRes(GameObject*);

	void confirmClicked();

	void cancelClicked(GameObject*);
	
private:



	//std::vector <CMaterial*> m_MATbuildingKind;
	int whatKind;
	int WhatSpecific = 1;
	int unterschied = -1;
	int WohnungNr = 0;
	bool clicked = false;
	bool isclicked = false;
	CAudio* Building_Sound;
	Player* m_playerStats;
	UI* m_menu;
	BeispielForGameObject MONKY;
	BeispielForGameObject* Wohnung[20];

};

