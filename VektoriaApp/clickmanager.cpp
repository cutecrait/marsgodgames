#include "clickmanager.h"

clickmanager::clickmanager()
{
}

clickmanager::~clickmanager()
{
}


void clickmanager::InitMenu(CDeviceCursor* cursor, CWritingFont* font, std::vector <CMaterial*> greatMatVek)
{

	vectorInArray(greatMatVek,5,3,4,4,5,6);
	//button der menu aufruft. 
	//jede option hier ruft wiederrum ein neuen button auf.
	whatKind = -1;
	WhatSpecific = -1;
	m_start.Init(cursor, font, CFloatRect(0.f, 0.9, 0.15, 0.1));
	m_start.SetLabel("Hi");

	m_BuildingKind.makeInactiveMats(m_matsForSelectMain);
	//im CFloatRect wird bestimmt wie groß und an welcher stelle gezeigt wird.
	//ersten 2 werte zeigen an wo die start-Koordinaten sind (in % vom bildschirm) letzten 2 werte wie groß es werden soll
	//also 0.2x,0.9y startwert. und es erstreckt sich von 0.9 breite und 0.1 höhe.
	m_BuildingKind.Init(cursor, font, 5, CFloatRect(0.0f, 0.0f, 0.15, 0.9)); 
	
	m_BuildingKind.AddOption("Roboter");
	m_BuildingKind.AddOption("Wohnen");
	m_BuildingKind.AddOption("Verpflegung");
	m_BuildingKind.AddOption("Was anderes");
	m_BuildingKind.AddOption("noch was anderes");
	
	std::vector <std::string> moin;
	
	
	moin.push_back("Bauroboter"); moin.push_back("Minenroboter"); moin.push_back("Landwirtroboter");
	m_specificBuilding[0].makeInactiveMats(m_matsForSelect1);
	m_specificBuilding[0].Init(cursor, font, 3, CFloatRect(0.15, 0.f, 0.15, 0.9));

	dummyMaker(0,3, moin);
	
	moin.clear();
	moin.push_back("hotel"); moin.push_back("Einfamilienhaus"); moin.push_back("Mehrfamilienhaus"); moin.push_back("villa");
	m_specificBuilding[1].makeInactiveMats(m_matsForSelect2);
	m_specificBuilding[1].Init(cursor, font, 4, CFloatRect(0.15, 0.f, 0.15, 0.9)); dummyMaker(1, 4, moin);

	moin.clear();
	moin.push_back("Gemüsegarten"); moin.push_back("Insektenzucht"); moin.push_back("Abwasserreinigung"); moin.push_back("Strom");
	m_specificBuilding[2].makeInactiveMats(m_matsForSelect3);
	m_specificBuilding[2].Init(cursor, font, 4, CFloatRect(0.15, 0.f, 0.15, 0.9)); dummyMaker(2,4, moin);

	moin.clear();
	moin.push_back("anderes1"); moin.push_back("anderes2"); moin.push_back("anderes3"); moin.push_back("anderes4"); moin.push_back("anderes5");
	m_specificBuilding[3].makeInactiveMats(m_matsForSelect4);
	m_specificBuilding[3].Init(cursor, font, 5, CFloatRect(0.15, 0.f, 0.15, 0.9)); dummyMaker( 3,5, moin);

	moin.clear();
	moin.push_back("anderes1"); moin.push_back("anderes2"); moin.push_back("anderes3"); moin.push_back("anderes4"); moin.push_back("anderes5"); moin.push_back("anderes6");
	m_specificBuilding[4].makeInactiveMats(m_matsForSelect5);
	m_specificBuilding[4].Init(cursor, font, 6, CFloatRect(0.15, 0.f, 0.15, 0.9)); dummyMaker(4, 6, moin);

	m_BuildingKind.SwitchOff();
	m_specificBuilding[0].SwitchOff(); m_specificBuilding[1].SwitchOff(); m_specificBuilding[2].SwitchOff(); m_specificBuilding[3].SwitchOff(); m_specificBuilding[4].SwitchOff();

	// mache noch eine setMaterial hover option^^

}

void clickmanager::dummyMaker(int anOptionStelle, int anzahlOption, std::vector<std::string> bla)

{

	for (int i = 0; i < anzahlOption; i++) {
		m_specificBuilding[anOptionStelle].AddOption(bla.at(i));
	}

	
	
}

CGuiSelect* clickmanager::getBuildingKind()
{
	return& m_BuildingKind;
}

CGuiButton* clickmanager::getStart()
{
	return& m_start;
}

CGuiSelect* clickmanager::getSpecfic(int i)
{
	return& m_specificBuilding[i];
}

void clickmanager::Click(float ftimedelta)
{
	//überprüft welche overlays angezeigt werden.
	if (m_start.IsClicked() ) { // wenn clicked false ist führe aus
		
		if (WhatSpecific == 2) {
			m_BuildingKind.SetActivePosition(-1);
			for (int i = 0; i < 5; i++) {
				m_specificBuilding[i].SwitchOff();
				m_specificBuilding[i].SetActivePosition(-1);
			}
			m_BuildingKind.SwitchOff();
			WhatSpecific = 1;
		}
		else {
			m_BuildingKind.SwitchOn();
			WhatSpecific = 2;
		}
		
		
		
	}
	
	
	if (m_BuildingKind.GetActivePosition()>=0) {

		m_specificBuilding[0].SwitchOff();
		
		m_specificBuilding[1].SwitchOff();
		
		m_specificBuilding[2].SwitchOff();
		
		m_specificBuilding[3].SwitchOff();
		
		m_specificBuilding[4].SwitchOff();
		

		m_specificBuilding[m_BuildingKind.GetActivePosition()].SwitchOn();
	}
	if (m_BuildingKind.GetActivePosition() == -1) {
		// wenn keine position aktive ist wird 2tes menü off
		m_specificBuilding[0].SwitchOff();
		m_specificBuilding[0].SetActivePosition(-1);
		m_specificBuilding[1].SwitchOff();
		m_specificBuilding[1].SetActivePosition(-1);
		m_specificBuilding[2].SwitchOff();
		m_specificBuilding[2].SetActivePosition(-1);
		m_specificBuilding[3].SwitchOff();
		m_specificBuilding[3].SetActivePosition(-1);
		m_specificBuilding[4].SwitchOff();
		m_specificBuilding[4].SetActivePosition(-1);
	}
	


}

void clickmanager::vectorInArray(std::vector<CMaterial*> greatMatVek, int sizeSel1, int sizeSel2, int sizeSel3, int sizeSel4, int sizeSel5, int sizeSel6) {
	//hier teile ich den mat vektor in mat array auf so das jeder select ein neues MAT array bekommt.
	

	int WhereIsArray = 0;
	int x = 0;
	for (int i = WhereIsArray; i < sizeSel1; i++) {
		m_matsForSelectMain[i] = greatMatVek.at(i);
	}
	WhereIsArray += sizeSel1;
	for (int i = WhereIsArray; i < (WhereIsArray + sizeSel2); i++) {
		m_matsForSelect1[x] = greatMatVek.at(i);
		x++;
	}
	WhereIsArray += sizeSel2;
	x = 0;
	for (int i = WhereIsArray; i < (WhereIsArray + sizeSel3); i++) {
		m_matsForSelect2[x] = greatMatVek.at(i);
		x++;
	}
	WhereIsArray += sizeSel3;
	x = 0;
	for (int i = WhereIsArray; i < (WhereIsArray + sizeSel4); i++) {
		m_matsForSelect3[x] = greatMatVek.at(i);
		x++;
	}
	WhereIsArray += sizeSel4;
	x = 0;
	for (int i = WhereIsArray; i < (WhereIsArray + sizeSel5); i++) {
		m_matsForSelect4[x] = greatMatVek.at(i);
		x++;
	}
	WhereIsArray += sizeSel5;
	x = 0;
	for (int i = WhereIsArray; i < (WhereIsArray + sizeSel6); i++) {
		m_matsForSelect5[x] = greatMatVek.at(i);
		x++;
	}
	
}


