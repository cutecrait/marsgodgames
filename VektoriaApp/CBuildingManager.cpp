#include "CBuildingManager.h"

CBuildingManager::CBuildingManager()
{
	 m_NrOfApartment = 0;
	 m_NrOfNuclearPerPlants = 0;
	 m_NrOfSolarPowerPlants = 0;
	 m_NrOfRoboFabrik = 0;
	 m_NrOfFoodFarms = 0;
	 m_NrOfFoundrys = 0;
	 m_NrOfGravelPlants = 0;
	 m_NrOfHospitals = 0;
	 m_NrOfMines = 0;
	 m_NrOfLaboratorys = 0;
	 m_NrOfTreeFarms = 0;
	 m_NrOfWells = 0;

}

CBuildingManager::~CBuildingManager()
{

}

void CBuildingManager::Init(CScene* scene)
{
	m_zs = scene;

	for (int i = 0; i < 20; i++) 
	{
		Apartments[i].setGameObject(new Apartment);
		Apartments[i].Init(typeid(Apartment).name());
		Apartments[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Apartments[i]);
	}

	for (int i = 0; i < 5; i++) 
	{
		RoboFabrik[i].setGameObject(new RobotFactory);
		RoboFabrik[i].Init(typeid(RobotFactory).name());
		RoboFabrik[i].getGameObject()->TransformGeo();
		
		m_zs->AddPlacement(&RoboFabrik[i]);
	}

	/*for (int i = 0; i < 20; i++)
	{
		NuclearPowerPlants[i].setGameObject(new NuclearPowerPlant);
		NuclearPowerPlants[i].Init(typeid(NuclearPowerPlant).name());
		NuclearPowerPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&NuclearPowerPlants[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		SolarPowerPlants[i].setGameObject(new SolarPowerPlant);
		SolarPowerPlants[i].Init(typeid(SolarPowerPlant).name());
		SolarPowerPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&SolarPowerPlants[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		FoodFarms[i].setGameObject(new FoodFarm);
		FoodFarms[i].Init(typeid(FoodFarm).name());
		FoodFarms[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&FoodFarms[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		Foundrys[i].setGameObject(new Foundry);
		Foundrys[i].Init(typeid(Foundry).name());
		Foundrys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Foundrys[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		GravelPlants[i].setGameObject(new GravelPlant);
		GravelPlants[i].Init(typeid(GravelPlant).name());
		GravelPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&GravelPlants[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		Hospitals[i].setGameObject(new Hospital);
		Hospitals[i].Init(typeid(Hospital).name());
		Hospitals[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Hospitals[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		Mines[i].setGameObject(new Mine);
		Mines[i].Init(typeid(Mine).name());
		Mines[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Mines[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		Laboratorys[i].setGameObject(new Laboratory);
		Laboratorys[i].Init(typeid(Laboratory).name());
		Laboratorys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Laboratorys[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		TreeFarms[i].setGameObject(new TreeFarm);
		TreeFarms[i].Init(typeid(TreeFarm).name());
		TreeFarms[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&TreeFarms[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		Wells[i].setGameObject(new Well);
		Wells[i].Init(typeid(Well).name());
		Wells[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Wells[i]);
	}

	ControlCenter_.setGameObject(new ControlCenter);
	ControlCenter_.Init(typeid(ControlCenter).name());
	ControlCenter_.getGameObject()->TransformGeo();
	m_zs->AddPlacement(&ControlCenter_);

	LaunchPad.setGameObject(new Launchpad);
	LaunchPad.Init(typeid(Launchpad).name());
	LaunchPad.getGameObject()->TransformGeo();
	m_zs->AddPlacement(&LaunchPad);*/
}

void CBuildingManager::UpdateBuildings(float deltaTime)
{
	int y = 0;

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

	for (int i = 0; i < 20; i++)
	{
		if (NuclearPowerPlants[i].getBuildStatus() == true)
		{
			NuclearPowerPlants[i].Update(deltaTime);
			y++;
			if (y == m_NrOfNuclearPerPlants)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (SolarPowerPlants[i].getBuildStatus() == true)
		{
			SolarPowerPlants[i].Update(deltaTime);
			y++;
			if (y == m_NrOfSolarPowerPlants)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (FoodFarms[i].getBuildStatus() == true)
		{
			FoodFarms[i].Update(deltaTime);
			y++;
			if (y == m_NrOfFoodFarms)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (Foundrys[i].getBuildStatus() == true)
		{
			Foundrys[i].Update(deltaTime);
			y++;
			if (y == m_NrOfFoundrys)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (GravelPlants[i].getBuildStatus() == true)
		{
			GravelPlants[i].Update(deltaTime);
			y++;
			if (y == m_NrOfGravelPlants)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (Hospitals[i].getBuildStatus() == true)
		{
			Hospitals[i].Update(deltaTime);
			y++;
			if (y == m_NrOfHospitals)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (Mines[i].getBuildStatus() == true)
		{
			Mines[i].Update(deltaTime);
			y++;
			if (y == m_NrOfMines)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (Laboratorys[i].getBuildStatus() == true)
		{
			Laboratorys[i].Update(deltaTime);
			y++;
			if (y == m_NrOfLaboratorys)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (TreeFarms[i].getBuildStatus() == true)
		{
			TreeFarms[i].Update(deltaTime);
			y++;
			if (y == m_NrOfTreeFarms)
				break;
		}

	}
	y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (Wells[i].getBuildStatus() == true)
		{
			Wells[i].Update(deltaTime);
			y++;
			if (y == m_NrOfWells)
				break;
		}

	}
	
	ControlCenter_.Update(deltaTime);

	LaunchPad.Update(deltaTime);

	// Update-Methoden der anderen Gebäude hier noch einfügen!
	// ...
}

void CBuildingManager::IncreaseNrOfBuildings(Typ& typ)
{
	switch (typ)
	{

	case CBuildingManager::Typ::None:
		break;
	case CBuildingManager::Typ::Apartment:
		m_NrOfApartment++;
		break;
	case CBuildingManager::Typ::ControlCenter:
		//---------------------------

		break;
	case CBuildingManager::Typ::FoodFarm:
		m_NrOfFoodFarms++;

		break;
	case CBuildingManager::Typ::Foundry:
		m_NrOfFoundrys++;

		break;
	case CBuildingManager::Typ::GravelPlant:
		m_NrOfGravelPlants++;

		break;
	case CBuildingManager::Typ::Hospital:
		m_NrOfHospitals++;

		break;
	case CBuildingManager::Typ::Laboratory:
		m_NrOfHospitals++;

		break;
	case CBuildingManager::Typ::Launchpad:
		//--------------------------
		

		break;
	case CBuildingManager::Typ::Mine:
		m_NrOfMines++;

		break;
	case CBuildingManager::Typ::NuclearPowerPlant:
		m_NrOfNuclearPerPlants++;
		break;
	case CBuildingManager::Typ::RobotFactory:
		m_NrOfRoboFabrik++;
		break;
	case CBuildingManager::Typ::SolarPowerPlant:
		m_NrOfSolarPowerPlants++;
		break;
	case CBuildingManager::Typ::TreeFarm:
		m_NrOfTreeFarms++;

		break;
	case CBuildingManager::Typ::Well:
		m_NrOfWells++;

		break;
	default: break;

	}
	
}

void CBuildingManager::DecreaseNrOfBuildings(Typ& typ)
{
	switch (typ)
	{
	case CBuildingManager::Typ::None:
		break;
	case CBuildingManager::Typ::Apartment:
		m_NrOfApartment--;
		break;
	case CBuildingManager::Typ::ControlCenter:

		break;
	case CBuildingManager::Typ::FoodFarm:
		m_NrOfFoodFarms--;

		break;
	case CBuildingManager::Typ::Foundry:
		m_NrOfFoundrys--;

		break;
	case CBuildingManager::Typ::GravelPlant:
		m_NrOfGravelPlants--;

		break;
	case CBuildingManager::Typ::Hospital:
		m_NrOfHospitals--;

		break;
	case CBuildingManager::Typ::Laboratory:
		m_NrOfHospitals--;

		break;
	case CBuildingManager::Typ::Launchpad:


		break;
	case CBuildingManager::Typ::Mine:
		m_NrOfMines--;

		break;
	case CBuildingManager::Typ::NuclearPowerPlant:
		m_NrOfNuclearPerPlants--;
		break;
	case CBuildingManager::Typ::RobotFactory:
		m_NrOfRoboFabrik--;
		break;
	case CBuildingManager::Typ::SolarPowerPlant:
		m_NrOfSolarPowerPlants--;
		break;
	case CBuildingManager::Typ::TreeFarm:
		m_NrOfTreeFarms--;

		break;
	case CBuildingManager::Typ::Well:
		m_NrOfWells--;

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
	default:
		break;
	}

	//gop->setGameObject(newBuilding);

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

	if (newBuilding)
		delete newBuilding;
}

CGameObjectPlacement* CBuildingManager::lookForGameObject(Typ& typ)
{
	// Überprüft, welcher Typ übergeben wurde und sucht entspechendes Gebäude
	// funktioniert bis jetzt nur bei Typen Test, Apartment, RoboFabrik
	switch (typ)
	{

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
			for (int i = 0; i < 20; i++)
			{
				if (NuclearPowerPlants[i].getBuildStatus() == false)
				{
					return &NuclearPowerPlants[i];
				}
			}

			break;
		case Typ::SolarPowerPlant:
			for (int i = 0; i < 20; i++)
			{
				if (SolarPowerPlants[i].getBuildStatus() == false)
				{
					return &SolarPowerPlants[i];
				}
			}
			break;

		case Typ::RobotFactory:
			for (int i = 0; i < 5; i++) {
				if (RoboFabrik[i].getBuildStatus() == false) {
					return &RoboFabrik[i];
				}
			}
			break;

		case Typ::ControlCenter:
			return &ControlCenter_;

		case Typ::Launchpad:
			return &LaunchPad;

		case Typ::FoodFarm:
			for (int i = 0; i < 20; i++) {
				if (FoodFarms[i].getBuildStatus() == false) {
					return &FoodFarms[i];
				}
			}
			break;

		case Typ::Foundry:
			for (int i = 0; i < 20; i++) {
				if (Foundrys[i].getBuildStatus() == false) {
					return &Foundrys[i];
				}
			}
			break;

		case Typ::GravelPlant:
			for (int i = 0; i < 20; i++) {
				if (GravelPlants[i].getBuildStatus() == false) {
					return &GravelPlants[i];
				}
			}
			break;

		case Typ::Hospital:
			for (int i = 0; i < 20; i++) {
				if (Hospitals[i].getBuildStatus() == false) {
					return &Hospitals[i];
				}
			}
			break;

		case Typ::Laboratory:
			for (int i = 0; i < 20; i++) {
				if (Laboratorys[i].getBuildStatus() == false) {
					return &Laboratorys[i];
				}
			}
			break;

		case Typ::Mine:
			for (int i = 0; i < 20; i++) {
				if (Mines[i].getBuildStatus() == false) {
					return &Mines[i];
				}
			}
			break;

		case Typ::TreeFarm:
			for (int i = 0; i < 20; i++) {
				if (TreeFarms[i].getBuildStatus() == false) {
					return &TreeFarms[i];
				}
			}
			break;

		case Typ::Well:

			for (int i = 0; i < 20; i++) {
				if (Wells[i].getBuildStatus() == false) {
					return &Wells[i];
				}
			}
			break;



		default: break;

	}

	// Maximale Anzahl an Gebäude-Typ verbaut
	return nullptr;
}