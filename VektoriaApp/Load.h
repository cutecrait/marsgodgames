#pragma once
#include "CTerrain.h"
#include "GameObject.h"
#include "BeispielForGameObject.h"
#include "Vektoria\Root.h"
#include "Apartment.h"
#include "Building.h"
#include "ControlCenter.h"
#include "FoodFarm.h"
#include "Foundry.h"
#include "GravelPlant.h"
#include "Hospital.h"
#include "Laboratory.h"
#include "Launchpad.h"
#include "Mine.h"
#include "NuclearPowerPlant.h"
#include "RobotFactory.h"
#include "SolarPowerPlant.h"
#include "TreeFarm.h"
#include "Well.h"
#include <iostream>
#include <fstream>
#include <string>
#include <array>
//Karo start
using namespace Vektoria;
class Load
{

private:
	
	//CPlacement *m_lplace; //How to get Placement from MapSquare?

	CPlacement m_lplaceterrain;
	CTerrain m_lterrain;
	CGeoTerrains m_lcollisionterr;
	
	//GOs
	BeispielForGameObject* beisforgamobj;
	Apartment* apartment;
	ControlCenter* controlcenter;
	FoodFarm* foodfarm;
	Foundry* foundry;
	GravelPlant* gravelplant;
	Hospital* hospital;
	Laboratory* laboratory;
	Launchpad* launchpad;
	Mine* mine; 
	NuclearPowerPlant* nuclearpowerplant;
	RobotFactory* robotfactory;
	SolarPowerPlant* solarpowerplant;
	TreeFarm* treefarm;
	Well* well;
	GameObject* geo_arr[100];
	
	CPlacement* m_placements[100];
	int pos_id;
	float* pos_arr[100];
	int obj_cnt;
	GameObject* GetGeos(int i);
	void SetGeos(GameObject* GO, int id);



public:
    Load();
	~Load();
	void LoadPlacements(CScene scene); //erstellt Placements
	void AttachGeos();
	void getGoID();
	bool fileExists(const char * file_name );
	void setPosArray(float x, float y, float z);
	void SetPlacement(float x, float z, GameObject*geo);
	GameObject *getObj(std::string obj_name);
	CPlacement *LoadTerrain();
	CPlacement* TestCube();
	CPlacement* GetPlacements(int i);
	void readPos();
	int getObjCount();
	int* LoadPlayerStats();
	
	//Karo end
};

