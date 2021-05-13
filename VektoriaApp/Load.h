#pragma once
#include "CTerrain.h"
//#include "GameObject.h"

#include "Vektoria\Root.h"
#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace Vektoria;
class Load
{

private:
	
	//CPlacement *m_lplace; //How to get Placement from MapSquare?

	CPlacement m_lplaceterrain;
	CTerrain m_lterrain;
	CGeoTerrains m_lcollisionterr;
	
	CGeoCube* geo_arr[100];
	// TestCube
	CGeoCube m_cube;
	CMaterial* cube_mat;
	CPlacement* m_placements[100];
	int pos_id;
	float* pos_arr[100];
	int obj_cnt;
	CGeo* GetGeos(int i);
	void SetGeos();

public:
    Load();
	~Load();
	void LoadPlacements(CScene scene); //erstellt Placements
	void AttachGeos();
	void getGoID();
	bool fileExists(const char * file_name );
	void setPosArray(float x, float y, float z);
	void SetPlacement(float x, float z, CGeo *geo);
	CGeo *getObj(std::string obj_name);
	CPlacement *LoadTerrain();
	CPlacement* TestCube();
	CPlacement* GetPlacements(int i);
	void readPos();
	int getObjCount();


};

