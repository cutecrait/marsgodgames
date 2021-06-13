#include "CBuildingManager.h"

CBuildingManager::CBuildingManager()
{
	for (int i = 0; i < TYP_LENGTH; i++)
	{
		m_NrsOfBuildings[i] = 0;
	}

	m_MaxBuildings[(int)Typ::None] = 0;
	m_MaxBuildings[(int)Typ::Apartment] = 50;
	m_MaxBuildings[(int)Typ::ControlCenter] = 1;
	m_MaxBuildings[(int)Typ::FoodFarm] = 20;
	m_MaxBuildings[(int)Typ::Foundry] = 20;
	m_MaxBuildings[(int)Typ::GravelPlant] = 1;
	m_MaxBuildings[(int)Typ::Hospital] = 1;
	m_MaxBuildings[(int)Typ::Laboratory] = 1;
	m_MaxBuildings[(int)Typ::Launchpad] = 1;
	m_MaxBuildings[(int)Typ::Mine] = 1;
	m_MaxBuildings[(int)Typ::NuclearPowerPlant] = 1;
	m_MaxBuildings[(int)Typ::RobotFactory] = 1;
	m_MaxBuildings[(int)Typ::SolarPowerPlant] = 1;
	m_MaxBuildings[(int)Typ::TreeFarm] = 1;
	m_MaxBuildings[(int)Typ::Well] = 1;
}

CBuildingManager::~CBuildingManager()
{

}

void CBuildingManager::Init(CScene* scene)
{
	m_zs = scene;

	// Initialisere die GameObjects
	for (int i = 0; i < size(Apartments); i++) {
		Apartments[i].setGameObject(new Apartment);
		Apartments[i].Init(typeid(Apartment).name());
		Apartments[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Apartments[i]);
		if (i == 0)
		{
			BuildingGeos.Add(Apartments[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(ControlCenters); i++) {
		ControlCenters[i].setGameObject(new ControlCenter);
		ControlCenters[i].Init(typeid(ControlCenter).name());
		ControlCenters[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&ControlCenters[i]);
		if (i == 0)
		{
			BuildingGeos.Add(ControlCenters[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(FoodFarms); i++) {
		FoodFarms[i].setGameObject(new FoodFarm);
		FoodFarms[i].Init(typeid(FoodFarm).name());
		FoodFarms[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&FoodFarms[i]);
		if (i == 0)
		{
			BuildingGeos.Add(FoodFarms[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(Foundrys); i++) {
		Foundrys[i].setGameObject(new Foundry);
		Foundrys[i].Init(typeid(Foundry).name());
		Foundrys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Foundrys[i]);
		if (i == 0)
		{
			BuildingGeos.Add(Foundrys[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(GravelPlants); i++) {
		GravelPlants[i].setGameObject(new GravelPlant);
		GravelPlants[i].Init(typeid(GravelPlant).name());
		GravelPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&GravelPlants[i]);
		if (i == 0)
		{
			BuildingGeos.Add(GravelPlants[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(Hospitals); i++) {
		Hospitals[i].setGameObject(new Hospital);
		Hospitals[i].Init(typeid(Hospital).name());
		Hospitals[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Hospitals[i]);
		if (i == 0)
		{
			BuildingGeos.Add(Hospitals[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(Laboratorys); i++) {
		Laboratorys[i].setGameObject(new Laboratory);
		Laboratorys[i].Init(typeid(Laboratory).name());
		Laboratorys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Laboratorys[i]);
		if (i == 0)
		{
			BuildingGeos.Add(Laboratorys[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(Launchpads); i++) {
		Launchpads[i].setGameObject(new Launchpad);
		Launchpads[i].Init(typeid(Launchpad).name());
		Launchpads[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Launchpads[i]);
		if (i == 0)
		{
			BuildingGeos.Add(Launchpads[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(Mines); i++) {
		Mines[i].setGameObject(new Mine);
		Mines[i].Init(typeid(Mine).name());
		Mines[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Mines[i]);
		if (i == 0)
		{
			BuildingGeos.Add(Mines[i].getGameObject()->getModel());
		}
	}
	int iNuclear = size(NuclearPowerPlants);
	for (int i = 0; i < size(NuclearPowerPlants); i++) {
		NuclearPowerPlants[i].setGameObject(new NuclearPowerPlant);
		NuclearPowerPlants[i].Init(typeid(NuclearPowerPlant).name());
		NuclearPowerPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&NuclearPowerPlants[i]);
		if (i == 0)
		{
			BuildingGeos.Add(NuclearPowerPlants[i].getGameObject()->getModel());
		}
	}
	int iRobots = size(RobotFactorys);
	for (int i = 0; i < iRobots; i++) {
		RobotFactorys[i].setGameObject(new RobotFactory);
		RobotFactorys[i].Init(typeid(RobotFactory).name());
		RobotFactorys[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&RobotFactorys[i]);
		if (i == 0)
		{
			BuildingGeos.Add(RobotFactorys[i].getGameObject()->getModel());
		}
	}
	int iSolar = size(SolarPowerPlants);
	for (int i = 0; i < size(SolarPowerPlants); i++) {
		SolarPowerPlants[i].setGameObject(new SolarPowerPlant);
		SolarPowerPlants[i].Init(typeid(SolarPowerPlant).name());
		SolarPowerPlants[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&SolarPowerPlants[i]);
		if (i == 0)
		{
			BuildingGeos.Add(SolarPowerPlants[i].getGameObject()->getModel());
		}
	}

	for (int i = 0; i < size(TreeFarms); i++) {
		TreeFarms[i].setGameObject(new TreeFarm);
		TreeFarms[i].Init(typeid(TreeFarm).name());
		TreeFarms[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&TreeFarms[i]);
		if (i == 0)
		{
			BuildingGeos.Add(TreeFarms[i].getGameObject()->getModel());
		}
	}
	for (int i = 0; i < size(Wells); i++) {
		Wells[i].setGameObject(new Well);
		Wells[i].Init(typeid(Well).name());
		Wells[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Wells[i]);
		if (i == 0)
		{
			BuildingGeos.Add(Wells[i].getGameObject()->getModel());
		}
	}
}

void CBuildingManager::UpdateBuildings(float deltaTime)
{
	for (int typ = 1; typ < TYP_LENGTH; typ++)
	{
		auto list = getBuildingList((Typ)typ);
		int y = 0;
		for (int i = 0; i < m_MaxBuildings[typ]; i++)
		{
			if (list[i].getBuildStatus() == true)
			{
				list[i].Update(deltaTime);
				y++;
				if (y == m_NrsOfBuildings[typ])
					break;
			}
		}
		y = 0;
	}
}

void CBuildingManager::IncreaseNrOfBuildings(Typ& typ)
{
	m_NrsOfBuildings[static_cast<int>(typ)]++;
}

void CBuildingManager::DecreaseNrOfBuildings(Typ& typ)
{
	m_NrsOfBuildings[static_cast<int>(typ)]--;
}

CGeos* CBuildingManager::getBuildingGeos()
{
	return &BuildingGeos;
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
	newBuilding->updatePlayer();

	gop->Translate(targetTile->GetPos());
	targetTile->Free = false;

	gop->SwitchOn();

	IncreaseNrOfBuildings(t);
	gop->setBuildStatus(true);

	if(gop->getGameObject()->getAudio())
	gop->m_paudios->m_apaudio[0]->Loop();

	Save save;
	save.fillPosAr(gop->getGameObject(), gop->GetPos().GetX(), gop->GetPos().GetZ());
}

CGameObjectPlacement* CBuildingManager::getClosestGameObject(Typ)
{

	return nullptr;
}

CGameObjectPlacement* CBuildingManager::getBuildingList(Typ typ)
{
	switch (typ)
	{
	case CBuildingManager::Typ::None:
		return nullptr;
		break;
	case CBuildingManager::Typ::Apartment:
		return Apartments;
		break;
	case CBuildingManager::Typ::ControlCenter:
		return ControlCenters;
		break;
	case CBuildingManager::Typ::FoodFarm:
		return FoodFarms;
		break;
	case CBuildingManager::Typ::Foundry:
		return Foundrys;
		break;
	case CBuildingManager::Typ::GravelPlant:
		return GravelPlants;
		break;
	case CBuildingManager::Typ::Hospital:
		return Hospitals;
		break;
	case CBuildingManager::Typ::Laboratory:
		return Laboratorys;
		break;
	case CBuildingManager::Typ::Launchpad:
		return Launchpads;
		break;
	case CBuildingManager::Typ::Mine:
		return Mines;
		break;
	case CBuildingManager::Typ::NuclearPowerPlant:
		return NuclearPowerPlants;
		break;
	case CBuildingManager::Typ::RobotFactory:
		return RobotFactorys;
		break;
	case CBuildingManager::Typ::SolarPowerPlant:
		return SolarPowerPlants;
		break;
	case CBuildingManager::Typ::TreeFarm:
		return TreeFarms;
		break;
	case CBuildingManager::Typ::Well:
		return Wells;
		break;
	default:
		break;
	}
}

CGameObjectPlacement* CBuildingManager::lookForGameObject(Typ& typ)
{
	auto list = getBuildingList(typ);
	for (int i = 0; i < m_MaxBuildings[(int)typ]; i++)
	{
		if (list[i].getBuildStatus() == false)
		{
			return &list[i];
		}
	}

	// Maximale Anzahl an Geb�ude-Typ verbaut
	return nullptr;
}