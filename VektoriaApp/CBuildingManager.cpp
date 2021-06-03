#include "CBuildingManager.h"

CBuildingManager::CBuildingManager()
{
	for (int i = 0; i < TYP_LENGTH; i++)
	{
		m_NrsOfBuildings[i] = 0;
	}
}

CBuildingManager::~CBuildingManager()
{

}

void CBuildingManager::Init(CScene* scene)
{
	m_zs = scene;

	// Initialisere die Beispiel GameObjects
	for (int i = 0; i < size(Apartments); i++) {
		Apartments[i].setGameObject(new Apartment);
		Apartments[i].Init(typeid(Apartment).name());
		Apartments[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Apartments[i]);
	}
	for (int i = 0; i < size(ControlCenters); i++) {
		ControlCenters[i].setGameObject(new ControlCenter);
		ControlCenters[i].Init(typeid(ControlCenter).name());
		ControlCenters[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&ControlCenters[i]);
	}
	for (int i = 0; i < size(FoodFarms); i++) {
		FoodFarms[i].setGameObject(new FoodFarm);
		FoodFarms[i].Init(typeid(FoodFarm).name());
		FoodFarms[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&FoodFarms[i]);
	}
	for (int i = 0; i < size(Foundrys); i++) {
		Foundrys[i].setGameObject(new Foundry);
		Foundrys[i].Init(typeid(Foundry).name());
		Foundrys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Foundrys[i]);
	}
	for (int i = 0; i < size(GravelPlants); i++) {
		GravelPlants[i].setGameObject(new GravelPlant);
		GravelPlants[i].Init(typeid(GravelPlant).name());
		GravelPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&GravelPlants[i]);
	}
	for (int i = 0; i < size(Hospitals); i++) {
		Hospitals[i].setGameObject(new Hospital);
		Hospitals[i].Init(typeid(Hospital).name());
		Hospitals[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Hospitals[i]);
	}
	for (int i = 0; i < size(Laboratorys); i++) {
		Laboratorys[i].setGameObject(new Laboratory);
		Laboratorys[i].Init(typeid(Laboratory).name());
		Laboratorys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Laboratorys[i]);
	}
	for (int i = 0; i < size(Launchpads); i++) {
		Launchpads[i].setGameObject(new Launchpad);
		Launchpads[i].Init(typeid(Launchpad).name());
		Launchpads[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Launchpads[i]);
	}
	for (int i = 0; i < size(Mines); i++) {
		Mines[i].setGameObject(new Mine);
		Mines[i].Init(typeid(Mine).name());
		Mines[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Mines[i]);
	}
	for (int i = 0; i < size(NuclearPowerPlants); i++) {
		NuclearPowerPlants[i].setGameObject(new NuclearPowerPlant);
		NuclearPowerPlants[i].Init(typeid(NuclearPowerPlant).name());
		NuclearPowerPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&NuclearPowerPlants[i]);
	}
	for (int i = 0; i < size(RobotFactorys); i++) {
		RobotFactorys[i].setGameObject(new RobotFactory);
		RobotFactorys[i].Init(typeid(RobotFactory).name());
		RobotFactorys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&RobotFactorys[i]);
	}
	for (int i = 0; i < size(SolarPowerPlants); i++) {
		SolarPowerPlants[i].setGameObject(new SolarPowerPlant);
		SolarPowerPlants[i].Init(typeid(SolarPowerPlant).name());
		SolarPowerPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&SolarPowerPlants[i]);
	}
	for (int i = 0; i < size(TreeFarms); i++) {
		TreeFarms[i].setGameObject(new TreeFarm);
		TreeFarms[i].Init(typeid(TreeFarm).name());
		TreeFarms[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&TreeFarms[i]);
	}
	for (int i = 0; i < size(Wells); i++) {
		Wells[i].setGameObject(new Well);
		Wells[i].Init(typeid(Well).name());
		Wells[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Wells[i]);
	}
}

void CBuildingManager::UpdateBuildings(float deltaTime)
{
	int y = 0;
	for (int i = 0; i < size(Apartments); i++)
	{
		if (Apartments[i].getBuildStatus() == true)
		{
			Apartments[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::Apartment)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(ControlCenters); i++)
	{
		if (ControlCenters[i].getBuildStatus() == true)
		{
			ControlCenters[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::ControlCenter)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(FoodFarms); i++)
	{
		if (FoodFarms[i].getBuildStatus() == true)
		{
			FoodFarms[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::FoodFarm)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(Foundrys); i++)
	{
		if (Foundrys[i].getBuildStatus() == true)
		{
			Foundrys[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::Foundry)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(GravelPlants); i++)
	{
		if (GravelPlants[i].getBuildStatus() == true)
		{
			GravelPlants[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::GravelPlant)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(Hospitals); i++)
	{
		if (Hospitals[i].getBuildStatus() == true)
		{
			Hospitals[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::Hospital)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(Laboratorys); i++)
	{
		if (Laboratorys[i].getBuildStatus() == true)
		{
			Laboratorys[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::Laboratory)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(Launchpads); i++)
	{
		if (Launchpads[i].getBuildStatus() == true)
		{
			Launchpads[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::Launchpad)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(Mines); i++)
	{
		if (Mines[i].getBuildStatus() == true)
		{
			Mines[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::Mine)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(NuclearPowerPlants); i++)
	{
		if (NuclearPowerPlants[i].getBuildStatus() == true)
		{
			NuclearPowerPlants[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::NuclearPowerPlant)])
				break;
		}

	}
	y = 0;

	for (int i = 0; i < size(RobotFactorys); i++)
	{
		if (RobotFactorys[i].getBuildStatus() == true)
		{
			RobotFactorys[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::RobotFactory)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(SolarPowerPlants); i++)
	{
		if (SolarPowerPlants[i].getBuildStatus() == true)
		{
			SolarPowerPlants[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::SolarPowerPlant)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(TreeFarms); i++)
	{
		if (TreeFarms[i].getBuildStatus() == true)
		{
			TreeFarms[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::TreeFarm)])
				break;
		}
	}
	y = 0;

	for (int i = 0; i < size(Wells); i++)
	{
		if (Wells[i].getBuildStatus() == true)
		{
			Wells[i].Update(deltaTime);
			y++;
			if (y == m_NrsOfBuildings[static_cast<int>(Typ::Well)])
				break;
		}
	}
	y = 0;
}

void CBuildingManager::IncreaseNrOfBuildings(Typ& typ)
{
	m_NrsOfBuildings[static_cast<int>(typ)]++;
}

void CBuildingManager::DecreaseNrOfBuildings(Typ& typ)
{
	m_NrsOfBuildings[static_cast<int>(typ)]--;
}

void CBuildingManager::AddNewBuilding(Typ t, MapTile* targetTile)
{
	if (!targetTile)
		return;

	CAudioManager::Instance().Ambient_Building_Sound.Start();

	auto gop = lookForGameObject(t);
	if (!gop)
		return;

	Building* newBuilding = (Building*)gop->getGameObject();

	Player* p = &Player::Instance();
	auto cost = newBuilding->getBuildCost();

	p->gainConcrete(-cost.Concrete);
	p->gainSteel(-cost.Steel);
	p->gainWood(-cost.Wood);
	p->useFood(newBuilding->NutrientUse);
	p->usePower(newBuilding->PowerUse);
	p->useWater(newBuilding->WaterUse);


	gop->Translate(targetTile->GetPos());
	targetTile->Free = false;

	gop->SwitchOn();

	IncreaseNrOfBuildings(t);
	gop->setBuildStatus(true);

	Save save;
	save.fillPosAr(gop->getGameObject(), gop->GetPos().GetX(), gop->GetPos().GetZ());
}

CGameObjectPlacement* CBuildingManager::lookForGameObject(Typ& typ)
{
	// �berpr�ft, welcher Typ �bergeben wurde und sucht entspechendes Geb�ude

	switch (typ)
	{
	case CBuildingManager::Typ::None:
		break;
	case CBuildingManager::Typ::Apartment:
		for (int i = 0; i < size(Apartments); i++)
		{
			if (Apartments[i].getBuildStatus() == false)
			{
				return &Apartments[i];
			}
		}
		break;
	case CBuildingManager::Typ::ControlCenter:
		for (int i = 0; i < size(ControlCenters); i++)
		{
			if (ControlCenters[i].getBuildStatus() == false)
			{
				return &ControlCenters[i];
			}
		}
		break;
	case CBuildingManager::Typ::FoodFarm:
		for (int i = 0; i < size(FoodFarms); i++)
		{
			if (FoodFarms[i].getBuildStatus() == false)
			{
				return &FoodFarms[i];
			}
		}
		break;
	case CBuildingManager::Typ::Foundry:
		for (int i = 0; i < size(Foundrys); i++)
		{
			if (Foundrys[i].getBuildStatus() == false)
			{
				return &Foundrys[i];
			}
		}
		break;
	case CBuildingManager::Typ::GravelPlant:
		for (int i = 0; i < size(GravelPlants); i++)
		{
			if (GravelPlants[i].getBuildStatus() == false)
			{
				return &GravelPlants[i];
			}
		}
		break;
	case CBuildingManager::Typ::Hospital:
		for (int i = 0; i < size(Hospitals); i++)
		{
			if (Hospitals[i].getBuildStatus() == false)
			{
				return &Hospitals[i];
			}
		}
		break;
	case CBuildingManager::Typ::Laboratory:
		for (int i = 0; i < size(Laboratorys); i++)
		{
			if (Laboratorys[i].getBuildStatus() == false)
			{
				return &Laboratorys[i];
			}
		}
		break;
	case CBuildingManager::Typ::Launchpad:
		for (int i = 0; i < size(Launchpads); i++)
		{
			if (Launchpads[i].getBuildStatus() == false)
			{
				return &Launchpads[i];
			}
		}
		break;
	case CBuildingManager::Typ::Mine:
		for (int i = 0; i < size(Mines); i++)
		{
			if (Mines[i].getBuildStatus() == false)
			{
				return &Mines[i];
			}
		}
		break;
	case CBuildingManager::Typ::NuclearPowerPlant:
		for (int i = 0; i < size(NuclearPowerPlants); i++)
		{
			if (NuclearPowerPlants[i].getBuildStatus() == false)
			{
				return &NuclearPowerPlants[i];
			}
		}
		break;
	case CBuildingManager::Typ::RobotFactory:
		for (int i = 0; i < size(RobotFactorys); i++)
		{
			if (RobotFactorys[i].getBuildStatus() == false)
			{
				return &RobotFactorys[i];
			}
		}
		break;
	case CBuildingManager::Typ::SolarPowerPlant:
		for (int i = 0; i < size(SolarPowerPlants); i++)
		{
			if (SolarPowerPlants[i].getBuildStatus() == false)
			{
				return &SolarPowerPlants[i];
			}
		}
		break;
	case CBuildingManager::Typ::TreeFarm:
		for (int i = 0; i < size(TreeFarms); i++)
		{
			if (TreeFarms[i].getBuildStatus() == false)
			{
				return &TreeFarms[i];
			}
		}
		break;
	case CBuildingManager::Typ::Well:
		for (int i = 0; i < size(Wells); i++)
		{
			if (Wells[i].getBuildStatus() == false)
			{
				return &Wells[i];
			}
		}
		break;

	default:
		break;
	}

	// Maximale Anzahl an Geb�ude-Typ verbaut
	return nullptr;
}