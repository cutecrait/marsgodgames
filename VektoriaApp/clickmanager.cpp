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
			pickedTile = (MapTile*)targetPos;
			pickedTile->Select();
		}

		else  mapsquares->DeselectMapTile(NULL);
	}

	else  mapsquares->DeselectMapTile(NULL);

	if (m_menu->getMainSelect()->GetActivePosition() == 4 && saveable) {
		save.saveItAll();
		save.deleteTxt();
		save.writeCurrToTxt("Ressources.txt",Player::Instance().getConcrete(), Player::Instance().getSteel(), Player::Instance().getWood());
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
			notInMenu = true;
		}
		else {
			m_menu->getMainSelect()->SwitchOn();
			WhatSpecific = 2;
			notInMenu = false;
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
	
	//if (cursor->PickGeo() == BuildingManager->lookForGameObject(dumyTyp)->getGameObject()->getModel()) {

	
	if (notInMenu) {
		
		blaa = cursor->PickGeo();
		if (blaa) {
			std::string ss = blaa->GetParent()->GetName();
			if (ss == "GameObject") {
				CGameObjectPlacement* test;
				test = (CGameObjectPlacement*)blaa->GetParent();
				
				buildtest = (Building*)test->getGameObject();
				if (cursor->ButtonDownLeft()) {
					if (!cursor->ButtonUpLeft()) {
						if (test->getType() == typeid(RobotFactory).name()) {
							if (!roboPopUpopen) {
								buildtest->setPopup(&m_menu->m_roboPopUP);

								buildtest->OnClick();
								roboPopUpopen = true;
							}
						}
					}

				}
				
				
			}
		}
		if (roboPopUpopen) {
			roboPopUpopen =	buildtest->decision();
			
		}
		m_menu->updatePlayer();
		
		
	}



	switch (m_menu->getMainSelect()->GetActivePosition())
	{
	case 0://fabriken
		switch (m_menu->getSpecificSelect(0)->GetActivePosition())
		{
		case 0:
			uiDecision(CBuildingManager::Typ::RobotFactory, "Robofabrik", cursor);
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


	//wenn confirm geklickt wird, wird ein addnewBuilding ausgegeführt.
	if (m_menu->m_confirm.IsClicked()) {
		// hallo hendrik
		

		if (enoughRes(toBeBuiltBuilding)) { //Gameobject
			// save game object in temporary array
			
			save.fillPosAr(toBeBuildObject->getGameObject(), toBeBuildObject->GetPos().GetX(), toBeBuildObject->GetPos().GetZ());
			saveable = true;
			//die UI-Decision updated "dumyTyp" - heißt wo man gerade ui draufklickt ändert den typ
			BuildingManager->AddNewBuilding(dumyTyp, pickedTile);

			if(BuildingManager)
			currentLevel->UpdateMissions(toBeBuildObject->getType(), 1, m_menu); //gameobjectplacement
			confirmClicked();
			makeBuilding(toBeBuildObject);
			targetPos = NULL;
			pickedTile = NULL;
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

	if (targetPos)
	{
		buildingObject->Translate(targetPos->GetPos());
	}
	buildingObject->SwitchOn();

	// Exemplarisch, die Methode bekommt am Besten auch einfach den Gebäude-Typ übergeben

	/*CBuildingManager::Typ typ = CBuildingManager::Typ::Test;
	BuildingManager->IncreaseNrOfBuildings(typ);
	buildingObject->setBuildStatus(true);
	buildingObject = NULL;*/

	
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




bool clickmanager::enoughRes(Building* hi) {

	// Prüfe, ob genug Ressourcen vorhanden sind
	auto cost = hi->getBuildCost();
	if (cost.Concrete <= Player::Instance().getConcrete() &&
		cost.Steel <= Player::Instance().getSteel()	   &&
		cost.Wood <= Player::Instance().getWood())
	{
		return true;
	}
	
}

void clickmanager::confirmClicked() {

	menuOFF();
	m_menu->m_cancel.SwitchOff();
	m_menu->m_confirm.SwitchOff();

	notInMenu = true;
	auto cost = toBeBuiltBuilding->getBuildCost();

	Player::Instance().gainConcrete(-cost.Concrete);
	Player::Instance().gainSteel(-cost.Steel);
	Player::Instance().gainWood(-cost.Wood);
	Player::Instance().useFood(toBeBuiltBuilding->NutrientUse);
	Player::Instance().usePower(toBeBuiltBuilding->PowerUse);
	Player::Instance().useWater(toBeBuiltBuilding->WaterUse);
	
	// Tooltip kann jetzt wieder angezeigt werden
	toolTipCreate = true;

	m_menu->updatePlayer(); // ui für player wird geupdated
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

void clickmanager::uiDecision(CBuildingManager::Typ typ, std::string tooltipname, CDeviceCursor* cursor) {
	
	toBeBuildObject = BuildingManager->lookForGameObject(typ);
	toBeBuiltBuilding = dynamic_cast<Building*>(toBeBuildObject->getGameObject());
	dumyTyp = typ;
	auto buildCost = toBeBuiltBuilding->getBuildCost();

	/*if (createToolTip(m_menu->getSpecificSelect(1)->GetActivePosition())) {
		//tooltip wird so nur einmal gebaut (aber kann überschrieben werden)
		activePosition = m_menu->getSpecificSelect(1)->GetActivePosition();
		m_menu->tooltip(
			tooltipname,
			buildCost.Concrete, buildCost.Steel, buildCost.Wood, 
			10,
			" Anzahl gebaut");
	}*/

	if (targetPos) {
		if (!isclicked)
		{
			toBeBuildObject->SwitchOn();
			m_menu->m_confirm.SwitchOn();
			m_menu->m_cancel.SwitchOn();
			m_menu->switchOnBuy(buildCost.Concrete, buildCost.Steel, buildCost.Wood);

			isclicked = true;
		}
		if (cursor->ButtonPressedLeft()) {
			toBeBuildObject->Translate(targetPos->GetPos());
		}
	}
}