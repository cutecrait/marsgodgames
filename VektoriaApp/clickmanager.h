#pragma once
#include "Vektoria\root.h"
#include "UI.h"
#include "GuiButton.h"
#include "GuiSelect.h"

using namespace Vektoria;
class clickmanager
{
public:
	clickmanager();
	~clickmanager();
	
	void Click(float);
	void Init(UI* menu , CScene* zs) { m_menu = menu;
	m_sphere.Init(0.5, nullptr, 10, 10);
	einPlace.AddGeo(&m_sphere);
	zs->AddPlacement(&einPlace);
	}
	void makeBuilding(CPlacement*);

private:
	
	
	
	//std::vector <CMaterial*> m_MATbuildingKind;
	int whatKind;
	int WhatSpecific;
	int unterschied=-1;
	bool clicked = false;
	CGeoSphere m_sphere;
	CPlacement einPlace;
	UI* m_menu;

};

