#include "CBuildingManager.h"

CBuildingManager::CBuildingManager()
{
	m_NrOfVersorgung = 0;
	m_NrOfWohungen = 0;
	m_NrOfTestObjects = 0;
	m_NrOfNuclearPerPlants = 0;
	m_NrOfSolarPowerPlants = 0;
	m_NrOfDomes = 0;
	m_NrOfWaterTanks = 0;
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
		BeispielGameObjects[i].Init();
		BeispielGameObjects[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&BeispielGameObjects[i]);
	}
	for (int i = 0; i < 20; i++) {
		Apartments[i].setGameObject(new Apartment);
		Apartments[i].Init();
		Apartments[i].getGameObject()->TransformGeo();
		m_zs->AddPlacement(&Apartments[i]);
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
		
		if (Apartments[i].getBuildStatus() == true)
		{
			Apartments[i].Update(deltaTime);
			y++;
			if (y == m_NrOfTestObjects)
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
		m_NrOfTestObjects++;

		break;

	case Typ::NuclearPowerPlant:
	case Typ::SolarPowerPlant:
	case Typ::Villa:
	case Typ::WaterTank:

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
		m_NrOfTestObjects--;

		break;

	case Typ::NuclearPowerPlant:
	case Typ::SolarPowerPlant:
	case Typ::Villa:
	case Typ::WaterTank:

	default: break;

	}
	
}

CGameObjectPlacement* CBuildingManager::lookForGameObject(Typ& typ)
{
	// Überprüft, welcher Typ übergeben wurde und sucht entspechendes Gebäude
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

		default: break;

	}

	// Maximale Anzahl an Gebäude-Typ verbaut
	return nullptr;
}