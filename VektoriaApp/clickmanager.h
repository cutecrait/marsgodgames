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
	
	void Click(float);
	void Init(UI* menu , CScene* zs, CAudioManager* am) { m_menu = menu;
	MONKY.getPlacement()->SwitchOff();
	zs->AddPlacement(MONKY.getPlacement());

	Building_Sound = &(am->Ambient_Building_Sound);
	}
	void makeBuilding(CPlacement*, CDeviceCursor*);

private:
	
	
	
	//std::vector <CMaterial*> m_MATbuildingKind;
	int whatKind;
	int WhatSpecific=1;
	int unterschied=-1;
	bool clicked = false;
	CAudio* Building_Sound;
	
	UI* m_menu;
	BeispielForGameObject MONKY;

};

