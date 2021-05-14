#include "CGameObjectPlacement.h"

CGameObjectPlacement::CGameObjectPlacement()
{
	hasBeenBuild = false;
	SetName("GameObject");
	SwitchOff();

}

CGameObjectPlacement::~CGameObjectPlacement()
{
	if (gameObject)
		delete gameObject;
}

void CGameObjectPlacement::Init()
{

	if (gameObject)
	{
		this->AddGeo(gameObject->getModel());
		//this->m_pgeos->m_apgeo[0]->Init();
	}

}

void CGameObjectPlacement::Update(float deltaTime)
{

}

void CGameObjectPlacement::UpdateOnClick()
{
	
}

bool CGameObjectPlacement::getBuildStatus()
{
	return hasBeenBuild;
}

void CGameObjectPlacement::setBuildStatus(bool b)
{
	hasBeenBuild = b;
}

GameObject* CGameObjectPlacement::getGameObject()
{
	return gameObject;
}

void CGameObjectPlacement::setGameObject(GameObject* go)
{
	gameObject = go;
}

