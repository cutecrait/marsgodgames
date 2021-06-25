#include "Load.h"

//Karo start

Load::Load()
{
	pos_id = 0;
	obj_cnt = 0;
	
}

Load::~Load()
{
}

void Load::LoadPlacements(CScene scene)
{

}

void Load::AttachGeos()
{
}

bool Load::fileExists(const char* file_name)
{
	if (FILE* file = fopen(file_name, "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

CBuildingManager::Typ Load::getTyp(std::string obj_name)
{
	CBuildingManager::Typ typ;

	

	if (obj_name == std::string("Apartment")) {
		typ = CBuildingManager::Typ::Apartment;

		return typ;

	}

	else if (obj_name == std::string("Barrack")) {

		typ = CBuildingManager::Typ::Barrack;

		return typ;
	}

	else if (obj_name == std::string("ControlCenter")) {

		typ = CBuildingManager::Typ::ControlCenter;

		return typ;
	}
	else if (obj_name == std::string("FoodFarm")) {
		typ = CBuildingManager::Typ::FoodFarm;

		return typ;
	}

	else if (obj_name == std::string("Foundry")) {
		typ = CBuildingManager::Typ::Foundry;

		return typ;
	}
	else if (obj_name == std::string("GravelPlant")) {
		typ = CBuildingManager::Typ::GravelPlant;

		return typ;
	}
	else if (obj_name == std::string("Hospital")) {
		typ = CBuildingManager::Typ::Hospital;

		return typ;
	}
	else if (obj_name == std::string("Laboratory")) {
		typ = CBuildingManager::Typ::Laboratory;

		return typ;
	}
	else if (obj_name == std::string("Launchpad")) {
		typ = CBuildingManager::Typ::Launchpad;

		return typ;
	}
	else if (obj_name == std::string("Mine")) {
		typ = CBuildingManager::Typ::Mine;

		return typ;
	}
	else if (obj_name == std::string("NuclearPowerPlant")) {
		typ = CBuildingManager::Typ::NuclearPowerPlant;

		return typ;
	}
	else if (obj_name == std::string("RobotFactory")) {
		typ = CBuildingManager::Typ::RobotFactory;

		return typ;
	}

	else if (obj_name == std::string("SolarPowerPlant")) {
		typ = CBuildingManager::Typ::SolarPowerPlant;

		return typ;
	}
	else if (obj_name == std::string("TreeFarm")) {
		typ = CBuildingManager::Typ::TreeFarm;

		return typ;
	}
	else if (obj_name == std::string("Well")) {
		typ = CBuildingManager::Typ::Well;

		return typ;
	}
	
}

void Load::AddBuilding()
{
	//Vektoria::ULDebug("Searching for Save-File");
	std::fstream file("Positions.txt");
	if (file.is_open()) {
		//Vektoria::ULDebug("Save-File found");
	}

	std::string tp;
	size_t pos = 0;
	while (getline(file, tp)) {
		std::string del = ", ";
		pos = tp.find(del);
		std::string tempstring = tp;
		std::string obj = tp.substr(0, pos);

		tp.erase(0, pos + del.length());
		pos = tp.find(del);
		std::string x_valstr = tp.substr(0, pos);
		tempstring = x_valstr;
		//Vektoria::ULDebug(tempstring.c_str());

		float x_val = std::stof(x_valstr);


		//Vektoria::ULDebug("Get Values");
		tp.erase(0, pos + del.length());
		std::string z_valstr = tp;
		tempstring = z_valstr;
		//Vektoria::ULDebug(tempstring.c_str());

		float z_val = std::stof(z_valstr);
		tp.erase(0, pos + del.length());
		//Vektoria::ULDebug(std::to_string(z_val).c_str());
		CBuildingManager::Instance().AddNewBuilding(this->getTyp(obj), x_val, z_val);

		obj_cnt++;
	}

	file.close();
}

CPlacement* Load::LoadTerrain()
{
	//collterr.Add(m_lterrain.getGeometry());
	m_lcollisionterr.Add(m_lterrain.getGeometry());
	return m_lterrain.getPlacement();
}

void Load::setPlayerDetails()
{
	this->loadPlayerDetails();
	Player::Instance().setConcrete(playerdets[0]);
	Player::Instance().setSteel(playerdets[1]);
	Player::Instance().setWood(playerdets[2]);

	Player::Instance().setConcretePM(playerdets[3]);
	Player::Instance().setSteelPM(playerdets[4]);
	Player::Instance().setWoodPM(playerdets[5]);

	Player::Instance().useWater(playerdets[6]);
	Player::Instance().usePower(playerdets[7]);
	Player::Instance().useWater(playerdets[8]);

	Player::Instance().setWater(playerdets[9]);
	Player::Instance().setPower(playerdets[10]);
	Player::Instance().setFood(playerdets[11]);

	Player::Instance().setWohnung(playerdets[12]);
	Player::Instance().setUsedWohnungen(playerdets[13]);
	Player::Instance().setRobots(playerdets[14]);
}


int Load::getObjCount()
{
	return obj_cnt;
}

int* Load::LoadPlayerStats()
{
	//Vektoria::ULDebug("Searching for Player-Stats");
	std::fstream file("Ressources.txt");
	if (file.is_open()) {
		//Vektoria::ULDebug("Player-Stats found");
	}

	std::string tp;
	size_t pos = 0;
	int* arr = new int[3];
	while (getline(file, tp)) {
		std::string del = ", ";
		pos = tp.find(del);
		std::string tempstring = tp;

		std::string resstr1 = tp.substr(0, pos);
		//Vektoria::ULDebug(resstr1.c_str());
		int res1 = std::stoi(resstr1);
		tp.erase(0, pos + del.length());
		
		pos = tp.find(del);
		std::string resstr2 = tp.substr(0, pos);
		//Vektoria::ULDebug(resstr2.c_str());
		int res2 = std::stoi(resstr2);
		tp.erase(0, pos + del.length());

		pos = tp.find(del);
		std::string resstr3 = tp.substr(0, pos);
		//Vektoria::ULDebug(resstr3.c_str());
		int res3 = std::stoi(resstr3);
		tp.erase(0, pos + del.length());
		
		arr[0] = res1;
		arr[1] = res2;
		arr[2] = res3;
	}

	file.close();

	return arr;

}

void Load::loadPlayerDetails()
{
	//Vektoria::ULDebug("Searching for Player-Stats");
	std::fstream file("PlayerDetails.txt");
	if (file.is_open()) {
		//Vektoria::ULDebug("Player-Stats found");
	}

	std::string tp;
	size_t pos = 0;

	for (int i = 0; i < 15; i++) {
		getline(file, tp);
		
		playerdets[i] = std::stoi(tp);
		//ULDebug(tp.c_str());
	}

	file.close();

	

}


//Karo end