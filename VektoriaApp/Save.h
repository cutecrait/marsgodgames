#pragma once
#include "CTerrain.h"
#include "GameObject.h"

#include "Vektoria\Root.h"
#include "BeispielForGameObject.h"
#include <map>
#include <iostream>
#include <array>

//Karo
class Save
{
public:
	explicit Save();
	~Save();

private:

	//Was muss alles Festgehalten werden?

	/*
	- Währungen 
	- ObjektPositionen
	- 
	*/
	
	// TBA

	float* pos_arr[100];
	std::string geo_arr[100];
	int pos_id;
	BeispielForGameObject bfgo;


public:
	void getObjects();
	void deleteTxt();
	std::string getObjName(GameObject* GO);
	void writePosToTxt(std::string file_name, std::string object_name, float x_pos, float z_pos); //for Object Positions
	void writeCurrToTxt(std::string file_name, int val1, int val2, int val3); // for Currencys 
	void fillPosAr(GameObject* GO,float x, float y);
	bool saveItAll();

};

