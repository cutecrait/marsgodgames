#pragma once
#include "Vektoria\root.h"

#include "GuiButton.h"
#include "GuiSelect.h"
using namespace Vektoria;
class clickmanager
{
public:
	clickmanager();
	~clickmanager();
	void InitMenu(CDeviceCursor*,CWritingFont*,std::vector<CMaterial*> moin);
	void dummyMaker(int, int, std::vector<std::string> );
	CGuiSelect* getBuildingKind();
	CGuiButton* getStart();
	CGuiSelect* getSpecfic(int);
	void Click(float);
	void vectorInArray(std::vector<CMaterial*>,int,int,int,int,int,int);
	

private:
	
	CGuiButton m_start; // button um menu zu öffnen
	CGuiSelect m_BuildingKind; // select menu für verschiedene arten
	CGuiSelect m_specificBuilding[5]; // unterschiedliche gebäude
	
	CMaterial* m_matsForSelectMain[5];

	CMaterial* m_matsForSelect1[3];
	CMaterial* m_matsForSelect2[4];
	CMaterial* m_matsForSelect3[4];
	CMaterial* m_matsForSelect4[5];
	CMaterial* m_matsForSelect5[6];
	
	//std::vector <CMaterial*> m_MATbuildingKind;
	int whatKind;
	int WhatSpecific;
	int unterschied=-1;
	bool clicked = false;

	

};

