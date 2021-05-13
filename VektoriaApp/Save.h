#pragma once
#include "CTerrain.h"
//#include "GameObject.h"

#include "Vektoria\Root.h"
#include <map>
#include <iostream>
#include <array>
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
	int pos_id;

public:
	void getObjects();
	void deleteTxt();
	void writePosToTxt(std::string file_name, std::string object_name, float x_pos, float z_pos); //for Object Positions
	void writeCurrToTxt(std::string file_name, std::string curr_name, float val); // for Currencys 
	void fillPosAr(float x, float y);
	bool saveItAll();

};

