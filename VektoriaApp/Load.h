#pragma once
#include "CTerrain.h"
#include "GameObject.h"
#include "BeispielForGameObject.h"
#include "Vektoria\Root.h"
#include "Apartment.h"
#include "Barrack.h"
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
#include "Player.h"
#include "CBuildingManager.h"
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
	
	int pos_id;
	int obj_cnt;


public:
    Load();
	~Load();
	void loadPlayerDetails();
	void LoadPlacements(CScene scene); //erstellt Placements
	void AttachGeos();
	void getGoID();
	bool fileExists(const char * file_name );
	CBuildingManager::Typ getTyp(std::string obj_name);
	void AddBuilding();
	CPlacement *LoadTerrain();
	void setPlayerDetails();
	void readPos();
	int getObjCount();
	int* LoadPlayerStats();
	int playerdets[15];
	
	//Karo end
};

