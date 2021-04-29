#pragma once
#include "Vektoria\root.h"
#include "UI.h"
#include "GuiButton.h"
#include "GuiSelect.h"
#include "BeispielForGameObject.h"
using namespace Vektoria;
class clickmanager
{
public:
	clickmanager();
	~clickmanager();
	
	void Click(float);
	void Init(UI* menu , CScene* zs) { m_menu = menu;
	MONKY.getPlacement()->SwitchOff();
	zs->AddPlacement(MONKY.getPlacement());
	}
	void makeBuilding(CPlacement*, CDeviceCursor*);

private:
	
	
	
	//std::vector <CMaterial*> m_MATbuildingKind;
	int whatKind;
	int WhatSpecific=1;
	int unterschied=-1;
	bool clicked = false;
	
	UI* m_menu;
	BeispielForGameObject MONKY;

};

