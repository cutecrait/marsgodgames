#include "clickmanager.h"
#include "Player.h"

clickmanager::clickmanager()
{
	
}

clickmanager::~clickmanager()
{
	delete m_menu;
}







void clickmanager::Click(float ftimedelta,  CDeviceCursor* cursor, LevelSystem::Level* currentLevel)
{
	//ich muss ne if abfrage machen, dass nicht selected == true sein muss.
	if (cursor->PickOverlay() == NULL)
	{
		targetPos = cursor->PickPlacementPreselected(*mapsquares);
		if (targetPos)
		{
			MapTile* tile = (MapTile*)targetPos;
			tile->Select();
		}

		else  mapsquares->DeselectMapTile(NULL);
	}

	else  mapsquares->DeselectMapTile(NULL);

	if (m_menu->getMainSelect()->GetActivePosition() == 4 && saveable) {
		save.saveItAll();
		save.deleteTxt();
		save.writeCurrToTxt("Ressources.txt",Player::Instance().getRessource1(), Player::Instance().getRessource2(), Player::Instance().getRessource3());
		ULDebug("Saving...");
		saveable = false;
	}

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


	//HAUS 
	// ----------------------------
	// @Hendrik: Du kannst die if-Klammern, die die ActivePosition() abfragen, auch als switch-Anweisung implementieren ;)
	// 	   Denn der folgende Rest ist ja auch prinzipiell immer der gleiche
	// 
	// 	   Die Tooltips am Besten auch vorgefertigt machen, sodass du nur Anhand der switch-Anweisung entscheiden musst,
	// 	   welcher nen SwitchOn()-Befehl erhält
	//------------------------------
	switch (m_menu->getMainSelect()->GetActivePosition())
	{
	case 0:
		switch (m_menu->getSpecificSelect(0)->GetActivePosition())
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		default:break;
		}
	case 1:
		switch (m_menu->getSpecificSelect(1)->GetActivePosition()) 
		{
		case 0: //das  "Apartment" ist für die überschrift im tooltip
			uiDecision(CBuildingManager::Typ::Apartment,"Apartment",cursor); 
		
			break;
		case 1:
			
			break;
		case 2:
			break;
		case 3:
			break;
		}
	case 2:
		switch (m_menu->getSpecificSelect(2)->GetActivePosition())
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:break;
		}

	case 3:
		switch (m_menu->getSpecificSelect(1)->GetActivePosition())
		{
		case 0:
			break;
		case 1:
			break;
			
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:break;
		}
	case 4:
		break;

	default: break;
	}


	if (m_menu->m_confirm.IsClicked()) {

		if (enoughRes(toBeBuildObject->getGameObject())) {
			// save game object in temporary array
			save.fillPosAr(toBeBuildObject->getGameObject(), toBeBuildObject->GetPos().GetX(), toBeBuildObject->GetPos().GetZ());
			saveable = true;
			//
			currentLevel->UpdateMissions(typeid(Apartment).name(), 1, m_menu);
			confirmClicked();
			makeBuilding(toBeBuildObject);
			targetPos = NULL;
		}
	}
	/*if (m_menu->getSpecificSelect(1)->GetActivePosition() == 0) {

		// Suche nach freiem Gebäude
		CBuildingManager::Typ typ = CBuildingManager::Typ::Apartment;
		toBeBuildObject = BuildingManager->lookForGameObject(typ);

		//tooltip anschalten 
		if (createToolTip(m_menu->getSpecificSelect(1)->GetActivePosition())) {
			//tooltip wird so nur einmal gebaut (aber kann überschrieben werden)
			activePosition = m_menu->getSpecificSelect(1)->GetActivePosition();
			m_menu->tooltip(
				"Apartment",
				
				toBeBuildObject->getGameObject()->getRessources().Sauerstoff_per_Build,								// Ehemals Res1
				toBeBuildObject->getGameObject()->getRessources().Stein_per_Build,				// Ehemals Res2
				toBeBuildObject->getGameObject()->getRessources().Strom_per_Build,				// Ehemals Res3
				10,
				"Anzahl gebaut");
		}

		if (m_menu->m_confirm.IsClicked()) {

			if (enoughRes(toBeBuildObject->getGameObject())) {
				// save game object in temporary array
				save.fillPosAr(toBeBuildObject->getGameObject(), toBeBuildObject->GetPos().GetX(), toBeBuildObject->GetPos().GetZ());
				saveable = true;
				//
				currentLevel->UpdateMissions(typeid(Apartment).name(),1,m_menu);
				confirmClicked();
				makeBuilding(toBeBuildObject);
				targetPos = NULL;
				Player::Instance().setWohnung(0);
				std::string einS;
				einS = "Wohnungen: " + std::to_string(Player::Instance().getWohnung());
				m_menu->getWohnung()->PrintString(&einS[0]);
			}
		}

		if (targetPos) {
			if (!isclicked)
			{
				toBeBuildObject->SwitchOn();
				m_menu->m_confirm.SwitchOn();
				m_menu->m_cancel.SwitchOn();
				m_menu->switchOnBuy(toBeBuildObject->getGameObject()->getRessources().Sauerstoff_per_Build,
					toBeBuildObject->getGameObject()->getRessources().Stein_per_Build,
					toBeBuildObject->getGameObject()->getRessources().Strom_per_Build);

				isclicked = true;
			}
			if (cursor->ButtonPressedLeft()) {
				toBeBuildObject->Translate(targetPos->GetPos());
			}

		}

	}

	//Haus2
	*/
	if (m_menu->m_cancel.IsClicked()) {

		cancelClicked(toBeBuildObject);
	}
	if (m_menu->m_missionen.IsHovered()) {
		m_menu->m_missionenBack.SwitchOn();
	}
	else
		m_menu->m_missionenBack.SwitchOff();

}




void clickmanager::makeBuilding(CGameObjectPlacement* buildingObject)
{
	// Confirm- und Cancel-Button werden ausgeschaltet
	m_menu->m_confirm.SwitchOff();
	m_menu->m_cancel.SwitchOff();

	Building_Sound->Start();

	if (targetPos)
	{
		buildingObject->Translate(targetPos->GetPos());
	}
	buildingObject->SwitchOn();

	// Exemplarisch, die Methode bekommt am Besten auch einfach den Gebäude-Typ übergeben

	CBuildingManager::Typ typ = CBuildingManager::Typ::Test;
	BuildingManager->IncreaseNrOfBuildings(typ);
	buildingObject->setBuildStatus(true);
	buildingObject = NULL;

	
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

	// Prüfe, ob genug Ressourcen vorhanden sind
	if (hi->getRessources().Sauerstoff_per_Build <= Player::Instance().getRessource1() &&
		hi->getRessources().Stein_per_Build <= Player::Instance().getRessource2()	   &&
		hi->getRessources().Strom_per_Build <= Player::Instance().getRessource3())
	{
		return true;
	}
	
}

void clickmanager::confirmClicked() {

	menuOFF();
	m_menu->m_cancel.SwitchOff();
	m_menu->m_confirm.SwitchOff();

	Player::Instance().setRessource1(-toBeBuildObject->getGameObject()->getRessources().Sauerstoff_per_Build);
	Player::Instance().setRessource2(-toBeBuildObject->getGameObject()->getRessources().Stein_per_Build);
	Player::Instance().setRessource3(-toBeBuildObject->getGameObject()->getRessources().Strom_per_Build);
	
	// Tooltip kann jetzt wieder angezeigt werden
	toolTipCreate = true;

	m_menu->updatePlayer();
	m_menu->m_toolTipBackGround.SwitchOff();
	isclicked = false;

	saveable = true;
}

void clickmanager::cancelClicked(CGameObjectPlacement* buildObject) {

	menuOFF();
	m_menu->m_cancel.SwitchOff();
	m_menu->m_confirm.SwitchOff();

	m_menu->updatePlayer();

	buildObject->SwitchOff();
	toolTipCreate = true;
	m_menu->m_toolTipBackGround.SwitchOff();
	isclicked = false;
}

bool clickmanager::createToolTip(int i)
{
	if (activePosition != i) {
		toolTipCreate = true;
	}
	else {
		toolTipCreate = false;
	}

	return toolTipCreate;
}

void clickmanager::uiDecision(CBuildingManager::Typ typ,std::string tooltipname,CDeviceCursor* cursor) {
	
	toBeBuildObject = BuildingManager->lookForGameObject(typ);
	if (createToolTip(m_menu->getSpecificSelect(1)->GetActivePosition())) {
		//tooltip wird so nur einmal gebaut (aber kann überschrieben werden)
		activePosition = m_menu->getSpecificSelect(1)->GetActivePosition();
		m_menu->tooltip(
			tooltipname,
			toBeBuildObject->getGameObject()->getRessources().Sauerstoff_per_Build,								// Ehemals Res1
			toBeBuildObject->getGameObject()->getRessources().Stein_per_Build,				// Ehemals Res2
			toBeBuildObject->getGameObject()->getRessources().Strom_per_Build,				// Ehemals Res3
			10,
			" Anzahl gebaut");
	}
	if (targetPos) {
		if (!isclicked)
		{
			toBeBuildObject->SwitchOn();
			m_menu->m_confirm.SwitchOn();
			m_menu->m_cancel.SwitchOn();
			m_menu->switchOnBuy(toBeBuildObject->getGameObject()->getRessources().Sauerstoff_per_Build,
				toBeBuildObject->getGameObject()->getRessources().Stein_per_Build,
				toBeBuildObject->getGameObject()->getRessources().Strom_per_Build);

			isclicked = true;
		}
		if (cursor->ButtonPressedLeft()) {
			toBeBuildObject->Translate(targetPos->GetPos());
		}

	}
}