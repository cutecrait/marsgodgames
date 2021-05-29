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

void GameObject::Update(float deltaTime)
{
	
}

void GameObject::TransformGeo()
{
	// Verschiebe die Geo in Y-Richtung, damit Objekt korrekt auf dem Boden steht
	CHMat m;
	m.TranslateY(CalculateHeight());
	if (m_model)
	{
		m_model->Transform(m);
	}
}

GameObject::Ressources_Data& GameObject::getRessources()
{
	return ressources;
}

void GameObject::setModel(char* modelpfad)
{
	m_model = m_modelPfad.LoadGeo(modelpfad);
}

void GameObject::setMaterial(char* matPfad)
{
	m_material.MakeTextureSprite(matPfad);
}

float GameObject::CalculateHeight()
{
	
	/*if (m_model)
		return m_model->m_aabb.GetSize().m_fy / 2.f;*/
	return 0;
	
}
