#include "clickmanager.h"

clickmanager::clickmanager()
{
	
}

clickmanager::~clickmanager()
{
	delete m_menu;
}







void clickmanager::Click(float ftimedelta, CPlacement* selected, CDeviceCursor* cursor)
{
	//ich muss ne if abfrage machen, dass nicht selected == true sein muss.
	
	
	if (m_menu->getStart()->IsClicked()) {
		if (WhatSpecific == 2) {
			//wenn ich nochmal start drücke nachdem ich schon mal start gedrückt habe dann mach alles wieder aus.
			for (int i = 0; i < 4; i++) {
				m_menu->getSpecificSelect(i)->SetActivePosition(-1);
				m_menu->getSpecificSelect(i)->SwitchOff();
			}
			m_menu->getMainSelect()->SetActivePosition(-1);
			m_menu->getMainSelect()->SwitchOff();
			WhatSpecific = 1;
		}
		else {
			m_menu->getMainSelect()->SwitchOn();
			WhatSpecific = 2;
		}
	}
	if (m_menu->getMainSelect()->GetActivePosition() >= 0) { // alles aus machen bis auf die aktive position.
		m_menu->getSpecificSelect(0)->SwitchOff();
		m_menu->getSpecificSelect(1)->SwitchOff();
		m_menu->getSpecificSelect(2)->SwitchOff();
		m_menu->getSpecificSelect(3)->SwitchOff();
		//m_menu->getSpecificSelect(4)->SwitchOff();

		m_menu->getSpecificSelect(m_menu->getMainSelect()->GetActivePosition())->SwitchOn();
	}
	if (m_menu->getMainSelect()->GetActivePosition() == -1) {
		// wenn keine position aktive ist wird 2tes menü off
		m_menu->getSpecificSelect(0)->SwitchOff();
		m_menu->getSpecificSelect(0)->SetActivePosition(-1);
		m_menu->getSpecificSelect(1)->SwitchOff();
		m_menu->getSpecificSelect(1)->SetActivePosition(-1);
		m_menu->getSpecificSelect(2)->SwitchOff();
		m_menu->getSpecificSelect(2)->SetActivePosition(-1);
		m_menu->getSpecificSelect(3)->SwitchOff();
		m_menu->getSpecificSelect(3)->SetActivePosition(-1);
		//m_menu->getSpecificSelect(4)->SwitchOff();
		//m_menu->getSpecificSelect(4)->SetActivePosition(-1);
	}
	
	if (m_menu->getPlayer()->IsClicked() && !clicked) {
		m_menu->getStatistic()->SwitchOn();
		clicked = true;
	}
	else if (m_menu->getPlayer()->IsClicked()) {
		m_menu->getStatistic()->SwitchOff();
		clicked = false;
	}
	

	if (m_menu->getSpecificSelect(1)->GetActivePosition() == 0 ) {
		//tooltip anschalten
		m_menu->tooltip(" Haus",MONKY.getRes1(),MONKY.getRes2(),MONKY.getRes3(),CFloatRect(0.3,0.2,0.2,0.2),cursor);

		if (m_menu->m_confirm.IsClicked()) {
			if (enoughRes(&MONKY)) {
				confirmClicked();
				makeBuilding(MONKY.getPlacement(), Wohnung[WohnungNr]->getPlacement());
				WohnungNr++;
				m_playerStats->setWohnung(1);
				m_menu->getWohnung()->SetLabel("Wohnungen: " + std::to_string(m_playerStats->getWohnung()));
			}
		}

		if (selected) {
			MONKY.getPlacement()->SwitchOn();
			m_menu->m_confirm.SwitchOn(); 
			m_menu->m_cancel.SwitchOn();
			m_menu->switchOnBuy(MONKY.getRes1(),MONKY.getRes2(),MONKY.getRes3());
			
				if (cursor->ButtonPressedLeft()) {
					MONKY.getPlacement()->Translate(selected->GetPos());
				}
		}
		
	}	
	
	if (m_menu->m_cancel.IsClicked()) {
		cancelClicked((&MONKY));
	}

}



void clickmanager::makeBuilding(CPlacement* selected,CPlacement* modelPlace)
{
	
	m_menu->m_confirm.SwitchOff();
	m_menu->m_cancel.SwitchOff();
	selected->SwitchOff();
	Building_Sound->Start();
	modelPlace->Translate(selected->GetPos());
	modelPlace->SwitchOn();

	
}
void clickmanager::menuOFF() {
	m_menu->getSpecificSelect(0)->SwitchOff();
	m_menu->getSpecificSelect(0)->SetActivePosition(-1);
	m_menu->getSpecificSelect(1)->SwitchOff();
	m_menu->getSpecificSelect(1)->SetActivePosition(-1);
	m_menu->getSpecificSelect(2)->SwitchOff();
	m_menu->getSpecificSelect(2)->SetActivePosition(-1);
	m_menu->getSpecificSelect(3)->SwitchOff();
	m_menu->getSpecificSelect(3)->SetActivePosition(-1);
	//m_menu->getSpecificSelect(4)->SwitchOff();
	//m_menu->getSpecificSelect(4)->SetActivePosition(-1);

	m_menu->getMainSelect()->SwitchOff();
	m_menu->getMainSelect()->SetActivePosition(-1);
}




bool clickmanager::enoughRes(GameObject* hi) {

	if (hi->getRes1() <= m_playerStats->getRessource1() && hi->getRes2() <= m_playerStats->getRessource2() && hi->getRes3() <= m_playerStats->getRessource3()) {

		return true;
	}
	
}

void clickmanager::confirmClicked() {
	menuOFF();
	m_menu->m_cancel.SwitchOff();
	m_menu->m_confirm.SwitchOff();

	m_playerStats->setRessource1(-MONKY.getRes1());
	m_playerStats->setRessource2(-MONKY.getRes2());
	m_playerStats->setRessource3(-MONKY.getRes3());
	

	m_menu->updatePlayer();
}

void clickmanager::cancelClicked(GameObject* model) {
	menuOFF();
	m_menu->m_cancel.SwitchOff();
	m_menu->m_confirm.SwitchOff();
	m_menu->updatePlayer();
	model->getPlacement()->SwitchOff();
}

