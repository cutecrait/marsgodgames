#include "CBuildingManager.h"

CBuildingManager::CBuildingManager()
{
	m_NrOfVersorgung = 0;
	m_NrOfApartment = 0;
	m_NrOfTestObjects = 0;
	m_NrOfNuclearPerPlants = 0;
	m_NrOfSolarPowerPlants = 0;
	m_NrOfDomes = 0;
	m_NrOfWaterTanks = 0;
	m_NrOfRoboFabrik = 0;

}

CBuildingManager::~CBuildingManager()
{

}

void CBuildingManager::Init(CScene* scene)
{
	m_zs = scene;

	// Initialisere die Beispiel GameObjects
	for (int i = 0; i < 20; i++)
	{
		BeispielGameObjects[i].setGameObject(new BeispielForGameObject);
		BeispielGameObjects[i].Init(typeid(BeispielForGameObject).name());
		BeispielGameObjects[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&BeispielGameObjects[i]);
	}
	for (int i = 0; i < 20; i++) {
		Apartments[i].setGameObject(new Apartment);
		Apartments[i].Init(typeid(Apartment).name());
		Apartments[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Apartments[i]);
	}
	for (int i = 0; i < 5; i++) {
		RoboFabrik[i].setGameObject(new RobotFactory);
		RoboFabrik[i].Init(typeid(RobotFactory).name());
		RoboFabrik[i].getGameObject()->TransformGeo();
		
		m_zs->AddPlacement(&RoboFabrik[i]);
	}

	// Initialsierungsmethoden der Gebäude noch einfügen!
	// ...
}

void CBuildingManager::UpdateBuildings(float deltaTime)
{
	int y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (BeispielGameObjects[i].getBuildStatus() == true)
		{
			BeispielGameObjects[i].Update(deltaTime);
			y++;
			if (y == m_NrOfTestObjects)
				break;
		}
	
	}
	y = 0;
	for (int i = 0; i < 20; i++)
	{
		if (Apartments[i].getBuildStatus() == true)
		{
			Apartments[i].Update(deltaTime);
			y++;
			if (y == m_NrOfApartment)
				break;
		}
		
	}
	y = 0;

	for (int i = 0; i < 5; i++) {
		if (RoboFabrik[i].getBuildStatus() == true) {
			RoboFabrik[i].Update(deltaTime);
			y++;
			if (y == m_NrOfRoboFabrik)
				break;
		}
	}
	y = 0;
	

	// Update-Methoden der anderen Gebäude hier noch einfügen!
	// ...
}

void CBuildingManager::IncreaseNrOfBuildings(Typ& typ)
{
	switch (typ)
	{
	case Typ::Test:
		m_NrOfTestObjects++;

		break;

	case Typ::Dome:
	case Typ::Hotel:
	case Typ::Apartment:
		m_NrOfApartment++;

		break;

	case Typ::NuclearPowerPlant:
	case Typ::SolarPowerPlant:
	case Typ::Villa:
	case Typ::WaterTank:
	case Typ::RobotFactory:
		m_NrOfRoboFabrik++;
		break;
	default: break;

	}
	
}

void CBuildingManager::DecreaseNrOfBuildings(Typ& typ)
{
	switch (typ)
	{
	case Typ::Test:
		m_NrOfTestObjects--;

		break;

	case Typ::Dome:
	case Typ::Hotel:
	case Typ::Apartment:
		m_NrOfApartment--;

		break;

	case Typ::NuclearPowerPlant:
	case Typ::SolarPowerPlant:
	case Typ::Villa:
	case Typ::WaterTank:
	case Typ::RobotFactory:
		m_NrOfRoboFabrik--;
		break;
	default: break;

	}
	
}

void CBuildingManager::AddNewBuilding(Typ t, MapTile* targetTile)
{
	if (!targetTile)
		return;

	CAudioManager::Instance().Ambient_Building_Sound.Start();

	auto gop = lookForGameObject(t);
	Building* newBuilding;

	switch (t)
	{
	case CBuildingManager::Typ::None:
		break;
	case CBuildingManager::Typ::Apartment:
		newBuilding = new Apartment;
		break;
	case CBuildingManager::Typ::ControlCenter:
		newBuilding = new ControlCenter;
		break;
	case CBuildingManager::Typ::FoodFarm:
		newBuilding = new FoodFarm;
		break;
	case CBuildingManager::Typ::Foundry:
		newBuilding = new Foundry;
		break;
	case CBuildingManager::Typ::GravelPlant:
		newBuilding = new GravelPlant;
		break;
	case CBuildingManager::Typ::Hospital:
		newBuilding = new Hospital;
		break;
	case CBuildingManager::Typ::Laboratory:
		newBuilding = new Laboratory;
		break;
	case CBuildingManager::Typ::Launchpad:
		newBuilding = new Launchpad;
		break;
	case CBuildingManager::Typ::Mine:
		newBuilding = new Mine;
		break;
	case CBuildingManager::Typ::NuclearPowerPlant:
		newBuilding = new NuclearPowerPlant;
		break;
	case CBuildingManager::Typ::RobotFactory:
		newBuilding = new RobotFactory;
		break;
	case CBuildingManager::Typ::SolarPowerPlant:
		newBuilding = new SolarPowerPlant;
		break;
	case CBuildingManager::Typ::TreeFarm:
		newBuilding = new TreeFarm;
		break;
	case CBuildingManager::Typ::Well:
		newBuilding = new Well;
		break;
	case CBuildingManager::Typ::Hotel:
		break;
	case CBuildingManager::Typ::Villa:
		break;
	case CBuildingManager::Typ::WaterTank:
		break;
	case CBuildingManager::Typ::Dome:
		break;
	case CBuildingManager::Typ::Test:
		break;
	default:
		break;
	}

	gop->setGameObject(newBuilding);

	Player* p = &Player::Instance();
	auto cost = newBuilding->getBuildCost();

	p->gainConcrete(-cost.Concrete);
	p->gainSteel(-cost.Steel);
	p->gainWood(-cost.Wood);
	p->useFood(newBuilding->NutrientUse);
	p->usePower(newBuilding->PowerUse);
	p->useWater(newBuilding->WaterUse);

	if (targetTile)
	{
		gop->Translate(targetTile->GetPos());
		targetTile->Free = false;
	}
	gop->SwitchOn();

	IncreaseNrOfBuildings(t);
	gop->setBuildStatus(true);

	Save save;
	save.fillPosAr(gop->getGameObject(), gop->GetPos().GetX(), gop->GetPos().GetZ());
}

CGameObjectPlacement* CBuildingManager::lookForGameObject(Typ& typ)
{
	// Überprüft, welcher Typ übergeben wurde und sucht entspechendes Gebäude
	// funktioniert bis jetzt nur bei Typen Test, Apartment, RoboFabrik
	switch (typ)
	{
		case Typ::Test:
			for (int i = 0; i < 20; i++)
			{
				if (BeispielGameObjects[i].getBuildStatus() == false)
				{
					return &BeispielGameObjects[i];
				}
			}

			break;
		case Typ::Dome:
		case Typ::Hotel:
		case Typ::Apartment:
			for (int i = 0; i < 20; i++)
			{
				if (Apartments[i].getBuildStatus() == false)
				{
					return &Apartments[i];
				}
			}

			break;

		case Typ::NuclearPowerPlant:
		case Typ::SolarPowerPlant:
		case Typ::Villa:
		case Typ::WaterTank:
		case Typ::RobotFactory:
			for (int i = 0; i < 5; i++) {
				if (RoboFabrik[i].getBuildStatus() == false) {
					return &RoboFabrik[i];
				}
			}
			break;
		default: break;

	}

	// Maximale Anzahl an Gebäude-Typ verbaut
	return nullptr;
}