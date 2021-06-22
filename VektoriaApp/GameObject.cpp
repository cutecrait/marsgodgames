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

void GameObject::setModel(char* modelpfad)
{
	m_model = m_modelPfad.LoadGeo(modelpfad, true);     // true; da die Texturen auf den Blender Modellen nicht richtig angezeigt werden
	//m_model->GetChild()->SetName("GameObject");
	//m_model->GetParent()->SetName("GameObject");
	m_model->SetName("GameObject");
	
}

void GameObject::setModel(AssetManager::Models model)
{
	CGeo* geo = AssetManager::getModel(model);
	m_model = geo;
	m_model->SetName("GameObject");
}

void GameObject::setMaterial(char* matPfad)
{
	m_material.MakeTextureSprite(matPfad);
}

void GameObject::setMaterial(char* matPfadB, char* matPfadD, char* matPfadG, char* matPfadS, char* matPfadH) // Texturierung mit Glow bei Nacht
{
	m_material.MakeTextureDiffuse(matPfadD);
	m_material.MakeTextureGlow(matPfadG);
	m_material.MakeTextureHeight(matPfadH);
	m_material.MakeTextureBump(matPfadB);
	m_material.MakeTextureSpecular(matPfadS);

	//m_material.SetSpecularSharpness(0.0f);
	//m_material.SetSpecularStrength(0.1f);
	m_material.SetGlowStrength(3.5f);
}

void GameObject::setMaterial(char* matPfadB, char* matPfadD, char* matPfadG, char* matPfadS, char* matPfadH, int spalt, int zeil, int fr) // Texturierung mit Glow und Animation
{
	m_material.MakeTextureDiffuse(matPfadD);
	m_material.MakeTextureGlow(matPfadG);
	//m_material.MakeTextureHeight(matPfadH);
	//m_material.MakeTextureBump(matPfadB);
	//m_material.MakeTextureSpecular(matPfadS);

	m_material.SetTextureGlowWhite();
	m_material.SetGlowStrength(3.0f);
	m_material.SetAni(spalt, zeil, fr);
}

void GameObject::setAudio(CAudio* audio)
{
	m_audio = audio;
}

float GameObject::CalculateHeight()
{
	
	/*if (m_model)
		return m_model->m_aabb.GetSize().m_fy / 2.f;*/
	return 0;
	
}
