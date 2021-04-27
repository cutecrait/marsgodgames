#pragma once
#include "CTerrain.h"
#include "GameObject.h"

#include "Vektoria\Root.h"
#include <map>
#include <iostream>
#include <array>

using namespace Vektoria;
class Load
{

private:
	
	//CPlacement *m_lplace; //How to get Placement from MapSquare?

	CPlacement m_lplaceterrain;
	CTerrain m_lterrain;
	CGeoTerrains m_lcollisionterr;
	
	CGeo* geo_arr[100];
	// TestCube
	CGeoCube m_cube;
	CMaterial* cube_mat;
	CPlacement* m_placements[100];
	int pos_id;
	float* pos_arr[100];

	CGeo* GetGeos(int i);
	void SetGeos();

public:
    Load();
	~Load();
	void LoadPlacements(CScene scene); //erstellt Placements
	void AttachGeos();
	void getGoID();
	void setPosArray(float x, float y, float z);
	CPlacement *LoadTerrain();
	CPlacement* m_placecube;
	CPlacement* TestCube();
	CPlacement* GetPlacements(int i);


};

