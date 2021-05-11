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
	if (m_menu->m_confirm.IsClicked() ) {
		menuOFF();
		m_menu->m_confirm.SwitchOff();
		m_menu->m_cancel.SwitchOff();
		Wohnung[WohnungNr]->getPlacement()->Translate(MONKY.getPlacement()->GetPos()); // richtiges model
		Wohnung[WohnungNr]->getPlacement()->SwitchOn();
		WohnungNr++;
		MONKY.getPlacement()->SwitchOff();
		Building_Sound->Start();
		isclicked = false;
		clicked = false;
		m_playerStats->setWohnung(1);
		m_menu->getWohnung()->SetLabel("Wohnungen: " + std::to_string(m_playerStats->getWohnung()));
	}
	if (m_menu->getStart()->IsClicked()) {
		if (WhatSpecific == 2) {
			//wenn ich nochmal start drücke nachdem ich schon mal start gedrückt habe dann mach alles wieder aus.
			for (int i = 0; i < 5; i++) {
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
		m_menu->getSpecificSelect(4)->SwitchOff();

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
		m_menu->getSpecificSelect(4)->SwitchOff();
		m_menu->getSpecificSelect(4)->SetActivePosition(-1);
	}
	
	if (m_menu->getPlayer()->IsClicked()) {
		m_menu->getStatistic()->SwitchOn();
	}
	
	if (m_menu->getSpecificSelect(1)->GetActivePosition() == 0 && selected /*&& clicked*/) {
		MONKY.getPlacement()->SwitchOn(); // pseudo model
		clicked = true;
		
		if (cursor->ButtonPressedLeft()) {
			MONKY.getPlacement()->Translate(selected->GetPos());
		}
		if (clicked) {
			m_menu->m_confirm.SwitchOn(); // confirm
			m_menu->m_cancel.SwitchOn(); // cancel
			clicked = false;
		}
		
	}
	if (m_menu->m_cancel.IsClicked()) {
		menuOFF();
		m_menu->m_cancel.SwitchOff();
		m_menu->m_confirm.SwitchOff();
	}

}



void clickmanager::makeBuilding(CPlacement* selected,CDeviceCursor* cursor)
{

	if (cursor->ButtonDownLeft()) {
		clicked = true;
		
		if (m_menu->getSpecificSelect(1)->GetActivePosition() == 0 && selected /*&& clicked*/) {
			m_menu->m_confirm.SwitchOn(); // confirm
			m_menu->m_confirm.SwitchOn(); // cancel

			
			MONKY.getPlacement()->Translate(selected->GetPos());
			//MONKY.getPlacement()->Translate(selected->GetPos());
			MONKY.getPlacement()->SwitchOn();
			Building_Sound->Start();

			if (m_menu->m_confirm.IsClicked()) {
				
				MONKY.getPlacement()->SwitchOff();

				
				WohnungNr++;

				m_menu->getSpecificSelect(1)->SetActivePosition(-1);
			}
			if (cursor->ButtonDownLeft()) {
				clicked = false;
			}
			m_playerStats->setWohnung(1);
			m_menu->getWohnung()->SetLabel("Wohnungen: " + std::to_string(m_playerStats->getWohnung()));
			
		}

	}

	


		
	
	
	
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
	m_menu->getSpecificSelect(4)->SwitchOff();
	m_menu->getSpecificSelect(4)->SetActivePosition(-1);

	m_menu->getMainSelect()->SwitchOff();
	m_menu->getMainSelect()->SetActivePosition(-1);
}




