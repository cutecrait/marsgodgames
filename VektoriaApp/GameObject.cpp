#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Init(char* model, char* material,int res1,int res2,int res3)
{
	setModel(model);
	setMaterial(material);
	m_res1 = res1;
	m_res2 = res2;
	m_res3 = res3;
}

void GameObject::setModel(char* modelpfad)
{
	m_model = m_modelPfad.LoadGeo(modelpfad);
}

void GameObject::setMaterial(char* matPfad)
{
	m_material.MakeTextureSprite(matPfad);
}
