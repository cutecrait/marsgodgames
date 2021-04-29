#pragma once
#include "Vektoria\root.h"
using namespace Vektoria;
class GameObject
{
public:
	//findet eine klasse die beispiel gameobject heiﬂt da hab ich den monkey mal reingetan.

	GameObject();
	~GameObject();

	virtual void Init(char* model, char* material);
	CPlacement* getPlacement() { return &m_placement; }
	CGeo* getModel() { return m_model; }
	CMaterial* getMaterial() {return &m_material;}
	CFileWavefront getPfad() { return m_modelPfad; }

	virtual void setModel(char*);
	virtual void setMaterial(char* );
private:
	CPlacement m_placement;
	CGeo* m_model;
	CFileWavefront m_modelPfad;
	CMaterial m_material;
};

