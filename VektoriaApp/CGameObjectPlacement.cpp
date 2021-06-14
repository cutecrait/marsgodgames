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

void CGameObjectPlacement::Init(std::string type)
{

	if (gameObject)
	{
		_type = type;
		if (gameObject->getAudio() != NULL)
		{
			this->AddAudio(gameObject->getAudio());
		}

		this->AddGeo(gameObject->getModel());
		
		//this->m_pgeos->m_apgeo[0]->SetMaterial(gameObject->getMaterial());

		//Nicht alle Objekte besitzen Audio
		
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

std::string CGameObjectPlacement::getType()
{
	return _type;
}

GameObject* CGameObjectPlacement::getGameObject()
{
	return gameObject;
}

void CGameObjectPlacement::setGameObject(GameObject* go)
{
	
	gameObject = go;
}

