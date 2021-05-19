#include "Save.h"
//Karo start
Save::Save()
{
	*pos_arr = new float[100];
	
	pos_id = 0;
}

Save::~Save()
{
}

void Save::getObjects()
{
}

void Save::deleteTxt()
{
	remove("Ressources.txt");
	
}

std::string Save::getObjName(GameObject *GO)
{
	std::string objName;
	if (dynamic_cast<BeispielForGameObject*>(GO))
	{
		objName = "BeispielForGameObject";
		ULDebug(objName.c_str());
	}
	else {
		objName = "Failure: Object Name not found.";
	}
	return objName;
}

void Save::writePosToTxt(std::string file_name, std::string object_name, float x_pos, float z_pos)
{
	std::ofstream file;
	file.open(file_name, std::ios_base::app);
	file << object_name << ", " << x_pos << ", " << z_pos << std::endl;

	file.close();
}

void Save::writeCurrToTxt(std::string file_name, int val1, int val2, int val3)
{
	std::ofstream file;
	file.open(file_name, std::ios_base::app);
	file << val1 << ", " << val2 << ", " << val3 << std::endl;

	file.close();
}

void Save::fillPosAr(GameObject* GO, float x, float z)
{
	std::string obj_class = this->getObjName(GO);
	
	geo_arr[pos_id] = obj_class;
	
	pos_arr[pos_id] = new float[2];
	pos_arr[pos_id][0] = x;
	pos_arr[pos_id][1] = z;
	
	pos_id += 1; 

}

bool Save::saveItAll()
{
	/*if (pos_arr[pos_id][0] == undefined) {
		pos_arr[pos_id][0] = 1.0f;
		pos_arr[pos_id][1] = 1.0f;
	}*/
	ULDebug(geo_arr[0].c_str());
	for (int i = 0; i < pos_id; i++) {
		this->writePosToTxt("Positions.txt", geo_arr[i], pos_arr[i][0], pos_arr[i][1]);
	}

	return true;
}
//Karo start