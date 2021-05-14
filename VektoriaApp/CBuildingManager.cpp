#include "CBuildingManager.h"

CBuildingManager::CBuildingManager()
{
	m_NrOfVersorgung = 0;
	m_NrOfWohungen = 0;
	m_NrOfTestObjects = 0;
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
}

void CBuildingManager::UpdateBuildings(float deltaTime)
{
	for (int i = 0; i < m_NrOfTestObjects; i++)
	{
		BeispielGameObjects[i].Update(deltaTime);
	}
}

void CBuildingManager::IncreaseNrOfBuildings()
{
	m_NrOfTestObjects++;
}

void CBuildingManager::DecreaseNrOfBuildings()
{
	m_NrOfTestObjects--;
}

CGameObjectPlacement* CBuildingManager::lookForGameObject()
{
	int y = 0;

	for (int i = 0; i < 20; i++)
	{
		if (BeispielGameObjects[i].getBuildStatus() == false)
		{
			return &BeispielGameObjects[i];
		}
	}

	// Maximale Anzahl an Gebäude-Typ verbaut
	return nullptr;
}