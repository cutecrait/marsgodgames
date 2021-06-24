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
	// Kann so einfach jeden Tick getestet werden, obwohl ungeschickte Platzierung
	if (LevelSystem::LevelManager::Instance().GetCurrentLevel()->IsCompleted()) {
		LevelSystem::LevelManager::Instance().GainXp(1000);
		LevelSystem::LevelManager::Instance().GetCurrentLevel()->initLevel(m_menu);
	}

	if (cursor->PickOverlay() == NULL)
	{
		
		targetPos = cursor->PickPlacementPreselected(*mapsquares);
		if (targetPos)
		{
			pickedTile = (MapTile*)targetPos;
			pickedTile->Select();
			if (cursor->ButtonPressedLeft()) {
				//bugfix for teleporting buildings(targetpos ver�ndert sich wenn man mit maus �ber tile geht. sollte f�r addnewbuilding aber nur mit buttonpressed. )
					TileForAddNewBuilding = pickedTile;
				
			}
		}

		else  mapsquares->DeselectMapTile(NULL);
	}

	else  mapsquares->DeselectMapTile(NULL);

	if (m_menu->getMainSelect()->GetActivePosition() == 4 && saveable) {
		save.saveItAll();
		
		//ULDebug("Saving...");
		saveable = false;
	}

	if (m_menu->getStart()->IsClicked()) {
		
		if (WhatSpecific == 2 && !m_menu->getConfirm()->IsOn()) {
			//wenn ich nochmal start dr�cke nachdem ich schon mal start gedr�ckt habe dann mach alles wieder aus.
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
		// wenn keine position aktive ist wird 2tes men� off
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
	//openPopup gibt true zur�ck wenn ein popup ge�ffnet wurde, popupbuttonclick k�mmert sich um die buttonclicks im popup;

	if (openPopup(cursor)) {
		popUpButtonClick(cursor, currentLevel);
	}

	//beim hinzufuegen, im ui.cpp infunktion "tooltip" auch das geb�ude hinzufuegen.
	//im geb�ude selber muss dann noch howmuch = int zahl hinzugef�gt werden. (wie viele nahrungseinheiten z.b.)
	// und die funktion void updatePlayer() override {Player::Instance().setirgendwas()} wenn das geb�ude irgendwie in den statistiken eine auswirkung hat.
	switch (m_menu->getMainSelect()->GetActivePosition())
	{
	case 0://fabriken
		switch (m_menu->getSpecificSelect(0)->GetActivePosition())
		{
		case 0:
			uiDecision(CBuildingManager::Typ::RobotFactory, "Robofabrik", cursor);
			break;
		case 1:
			uiDecision(CBuildingManager::Typ::Laboratory, "Labor", cursor);
			break;
		case 2:
			break;
		default:break;
		}
	case 1:
		switch (m_menu->getSpecificSelect(1)->GetActivePosition()) 
		{
		case 0: //das  "Apartment" ist f�r die �berschrift im tooltip
			
			uiDecision(CBuildingManager::Typ::Barrack,"Baracke",cursor); 
			break;
		case 1:
			uiDecision(CBuildingManager::Typ::Apartment, "Apartment", cursor);
			break;
		case 2:
			uiDecision(CBuildingManager::Typ::Laboratory, "Labor", cursor);
			break;
		case 3:
			uiDecision(CBuildingManager::Typ::Hospital, "Krankenhaus", cursor);
			break;
		}
	case 2:
		switch (m_menu->getSpecificSelect(2)->GetActivePosition())
		{
		case 0:
			uiDecision(CBuildingManager::Typ::Well, "Brunnen", cursor);
			break;
		case 1:
			uiDecision(CBuildingManager::Typ::FoodFarm, "Foodfarm", cursor);
			break;
		case 2:
			uiDecision(CBuildingManager::Typ::SolarPowerPlant, "Solaranlage", cursor);
			break;
		case 3:
			uiDecision(CBuildingManager::Typ::RobotFactory, "Nuklearzelle", cursor);
			break;
		default:break;
		}

	case 3:
		switch (m_menu->getSpecificSelect(3)->GetActivePosition())
		{
		case 0:
			uiDecision(CBuildingManager::Typ::ControlCenter, "ControlCenter", cursor);
			break;
		case 1:
			uiDecision(CBuildingManager::Typ::Foundry, "Foundy", cursor);
			break;
			
		case 2:
			uiDecision(CBuildingManager::Typ::GravelPlant, "Gravelplant", cursor);
			break;
		case 3:
			uiDecision(CBuildingManager::Typ::Mine, "Mine", cursor);
			break;
		case 4:
			uiDecision(CBuildingManager::Typ::TreeFarm, "Baumzucht", cursor);
			break;
		default:break;
		}
	case 4:
		break;

	default: break;
	}

	

	//wenn confirm geklickt wird, wird ein addnewBuilding ausgegef�hrt.

	
	if (m_menu->m_confirm.IsClicked()) {
		// hallo hendrik
		switchButtonClick(0,currentLevel);

		
	}
	
	if (m_menu->m_cancel.IsClicked()) {

		switchButtonClick(1, currentLevel);
	}
	if (m_menu->m_Ressources.IsHovered()) {
		m_menu->m_RessourcesPM.SwitchOn();
	}
	else {
		m_menu->m_RessourcesPM.SwitchOff();
	}
	if (m_menu->m_missionen.IsHovered()) {
		m_menu->m_missionenBack.SwitchOn();
	}
	else {
		m_menu->m_missionenBack.SwitchOff();
		
	}
}




void clickmanager::makeBuilding(CGameObjectPlacement* buildingObject)
{
	// Confirm- und Cancel-Button werden ausgeschaltet
	/*m_menu->m_confirm.SwitchOff();
	m_menu->m_cancel.SwitchOff();

	if (targetPos)
	{
		buildingObject->Translate(targetPos->GetPos());
	}
	buildingObject->SwitchOn();

	// Exemplarisch, die Methode bekommt am Besten auch einfach den Geb�ude-Typ �bergeben

	CBuildingManager::Typ typ = CBuildingManager::Typ::Test;
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

	// Pr�fe, ob genug Ressourcen vorhanden sind
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
		//guiklasse ist schei�e und man l�uft immer 2mal in confirmclicked rein. 
		//deshalb alles geteilt durch 2 :D
	
		// Tooltip kann jetzt wieder angezeigt werden
		toolTipCreate = true;

		m_menu->updatePlayer(); // ui f�r player wird geupdated
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
		return true;
	}
	else {
		return false;
	}

	
}

void clickmanager::uiDecision(CBuildingManager::Typ typ, std::string tooltipname, CDeviceCursor* cursor) {
	
	
			typforUiDecsion = typ;
		if (dumyTyp == CBuildingManager::Typ::None) {
			dumyTyp = typ;
			toBeBuildObject = BuildingManager->lookForGameObject(typ);

			toBeBuiltBuilding = dynamic_cast<Building*>(toBeBuildObject->getGameObject());

			buildCost = toBeBuiltBuilding->getBuildCost();

			m_menu->tooltip(tooltipname, buildCost.Concrete, buildCost.Steel, buildCost.Wood, typ);
		}
		else if (dumyTyp != typ) {
			dumyTyp = typ;
			if (toBeBuildObject && toBeBuiltBuilding) {
				toBeBuildObject->SwitchOff();
				isclicked = false;
			}
			toBeBuildObject = BuildingManager->lookForGameObject(typ);

			toBeBuiltBuilding = dynamic_cast<Building*>(toBeBuildObject->getGameObject());

			buildCost = toBeBuiltBuilding->getBuildCost();

			m_menu->tooltip(tooltipname, buildCost.Concrete, buildCost.Steel, buildCost.Wood, typ);

		}
	/*if (createToolTip(m_menu->getSpecificSelect(1)->GetActivePosition())) {
		//tooltip wird so nur einmal gebaut (aber kann �berschrieben werden)
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

void clickmanager::switchButtonClick(int i, LevelSystem::Level* currentLevel) {
	//unterschied zwischen men� building confirm button und Popup confirm button
	switch (i) {
	case 0:
		//confirm click.
		if (enoughRes(toBeBuiltBuilding)) { //Gameobject
			
			//die UI-Decision updated "dumyTyp" - hei�t wo man gerade ui draufklickt �ndert den typ
			BuildingManager->AddNewBuilding(dumyTyp, TileForAddNewBuilding);

			if (BuildingManager)
				currentLevel->UpdateMissions(toBeBuildObject->getType(), 1, m_menu); //gameobjectplacement
			confirmClicked();

			// save game object in temporary array
			save.fillPosAr(toBeBuildObject->getGameObject(), toBeBuildObject->GetPos().GetX(), toBeBuildObject->GetPos().GetZ());
			saveable = true;
			//makeBuilding(toBeBuildObject);
			targetPos = NULL;
			pickedTile = NULL;
			dumyTyp = CBuildingManager::Typ::None;
		}
		break;
	case 1:
		//cancel click
		cancelClicked(toBeBuildObject);
		dumyTyp = CBuildingManager::Typ::None;
		break;
	case 2:
		//popup confirm
		currentLevel->UpdateMissions(typeid(testRobo).name(), selectedBuilding->getResult(0), m_menu);
		m_menu->updatePlayer();
		
		break;
	case 3:
		//popup cancel
		break;
	case 4:
		break;
	default: break;
	}
	
	//nur wenn man auf nen confirm button geklickt hat, und kein popup offen ist und nicht im men� ist 
	//�berpr�fe ob level completed, und steige level auf (gainxp) und initialisiere n�chstes level
	// 
	// kann nur ein level upkommen wenn ich mal in nem popupwar:
	
}


void clickmanager::popUpButtonClick(CDeviceCursor * cursor, LevelSystem::Level* currentLevel) {

	switchButtonClick(selectedBuilding->decision(),currentLevel); //l�uft rein auch wenn cancel clicked
			
		
	
	

}
bool clickmanager::openPopup(CDeviceCursor* cursor) {
	if (!m_menu->getMainSelect()->IsOn()) {
		if (cursor->PickOverlay() == NULL) {
			if (cursor->ButtonPressedLeft()) {
				if (!cursor->ButtonUpLeft()) {
					selectedGeo = cursor->PickGeoPreselected(*BuildingModels);
					if (selectedGeo) {
						//selectedGeo->GetParent()->SetName("GameObject");
						ss = selectedGeo->GetParent()->GetName();
						//wenn audio aktiv, pickt kein geo mehr sondern geogrid(tiles)
						//wenn setaudio in einem building ausgef�hrt kllappts nicht mehr
						//caudiomanager auch ein setname gemacht,
						//reihenfolge in GOplacement ge�ndert
						// in Buildingmanager getname klappt noch 
						if (ss == "GameObject") {
							selectedPlacement = (CGameObjectPlacement*)selectedGeo->GetParent();
							selectedBuilding = (Building*)selectedPlacement->getGameObject();
							if (selectedBuilding->hasPopup()) {
								if (!selectedBuilding->isPopupOpen()) {
									selectedBuilding->setPopup(m_menu->getPopup(selectedPlacement->getType())); // funktion im m_menu.PopoUP returned ein popup. und es komm drauf an wie der typ, dann kommt popup.
									selectedBuilding->OnClick();

								}
							}
						}
					}
				}
			}
		}
	}
	if (selectedBuilding) {
		if (selectedBuilding->isPopupOpen()) {
			return true;
		}
	}
	return false;
}

void clickmanager::setBuildingGeos(CGeos* geos)
{
	BuildingModels = geos;
}
