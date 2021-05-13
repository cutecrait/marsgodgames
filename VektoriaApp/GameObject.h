#pragma once
#include "Vektoria\root.h"
using namespace Vektoria;
class GameObject
{
public:
	//findet eine klasse die beispiel gameobject heiﬂt da hab ich den monkey mal reingetan.

	GameObject();
	~GameObject();

	virtual void Init(char* model, char* material, int,int,int);
	CPlacement* getPlacement() { return &m_placement; }
	CGeo* getModel() { return m_model; }
	CMaterial* getMaterial() {return &m_material;}
	CFileWavefront getPfad() { return m_modelPfad; }
	int getRes1() { return m_res1; }
	int getRes2() { return m_res2; }
	int getRes3() { return m_res3; }

	virtual void setModel(char*);
	virtual void setMaterial(char* );
private:
	CPlacement m_placement;
	CGeo* m_model;
	CFileWavefront m_modelPfad;
	CMaterial m_material;
protected:
	int m_res1;
	int m_res2;
	int m_res3;
};

