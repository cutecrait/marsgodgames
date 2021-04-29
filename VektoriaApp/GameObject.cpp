#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Init(char* model, char* material)
{
	setModel(model);
	setMaterial(material);
}

void GameObject::setModel(char* modelpfad)
{
	m_model = m_modelPfad.LoadGeo(modelpfad);
}

void GameObject::setMaterial(char* matPfad)
{
	m_material.MakeTextureSprite(matPfad);
}
