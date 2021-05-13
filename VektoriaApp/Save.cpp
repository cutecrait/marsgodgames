#include "Save.h"

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
	remove("Positions.txt");
	
}

void Save::writePosToTxt(std::string file_name, std::string object_name, float x_pos, float z_pos)
{
	std::ofstream file;
	file.open(file_name, std::ios_base::app);
	file << object_name << ", " << x_pos << ", " << z_pos << std::endl;

	file.close();
}

void Save::writeCurrToTxt(std::string file_name, std::string curr_name, float val)
{
}

void Save::fillPosAr(float x, float z)
{
	
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

	for (int i = 0; i < pos_id; i++) {
		this->writePosToTxt("Positions.txt", "CGeoCube", pos_arr[i][0], pos_arr[i][1]);
	}

	return true;
}
