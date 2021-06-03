#include "Load.h"

//Karo start

Load::Load()
{
	pos_id = 0;
	obj_cnt = 0;
	//*m_placements = new CPlacement[100];
	for (int i = 0; i < 100; i++)
	{
		m_placements[i] = new CPlacement();
	}

	*pos_arr = new float[100];



	//if (this->fileExists("Positions.txt")) {
		this->readPos();
	//}
	

	
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

void Load::setPosArray(float x, float y, float z)
{
	

	
}

void Load::SetPlacement(float x, float z, GameObject* geo)
{
	m_placements[obj_cnt] = new CPlacement();
	m_placements[obj_cnt]->Translate(x, 0.0f, z);
	m_placements[obj_cnt]->AddGeo(geo->getModel());
}

GameObject *Load::getObj(std::string obj_name)
{
	
	
	if (obj_name == std::string("BeispielForGameObject")) {
		beisforgamobj = new BeispielForGameObject();

		this->SetGeos(beisforgamobj, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}

	else if (obj_name == std::string("Apartment")) {
		apartment = new Apartment();

		this->SetGeos(apartment, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}

	else if (obj_name == std::string("ControlCenter")) {
		controlcenter = new ControlCenter();

		this->SetGeos(controlcenter, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("FoodFarm")) {
		foodfarm = new FoodFarm();

		this->SetGeos(foodfarm, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Foundry")) {
		foundry = new Foundry();

		this->SetGeos(foundry, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("GravelPlant")) {
		gravelplant = new GravelPlant();

		this->SetGeos(gravelplant, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Hospital")) {
		hospital = new Hospital();

		this->SetGeos(hospital, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Laboratory")) {
		laboratory = new Laboratory();

		this->SetGeos(laboratory, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Launchpad")) {
		launchpad = new Launchpad();

		this->SetGeos(launchpad, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Mine")) {
		mine = new Mine();

		this->SetGeos(mine, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("NuclearPowerPlant")) {
		nuclearpowerplant = new NuclearPowerPlant();

		this->SetGeos(nuclearpowerplant, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("RobotFactory")) {
		robotfactory = new RobotFactory();

		this->SetGeos(robotfactory, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}

	else if (obj_name == std::string("SolarPowerPlant")) {
		solarpowerplant = new SolarPowerPlant();

		this->SetGeos(solarpowerplant, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("TreeFarm")) {
		treefarm = new TreeFarm();

		this->SetGeos(treefarm, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Well")) {
		well = new Well();

		this->SetGeos(well, this->getObjCount());
		return geo_arr[this->getObjCount()];
	}
	else {
		return nullptr;
	}
	
}

CPlacement* Load::LoadTerrain()
{
	//collterr.Add(m_lterrain.getGeometry());
	m_lcollisionterr.Add(m_lterrain.getGeometry());
	return m_lterrain.getPlacement();
}


CPlacement* Load::GetPlacements(int i)
{
	if (this->getObjCount() > 0) {
		return m_placements[i];
	}

	else {
		return nullptr;
	}
		
}

void Load::readPos()
{
		Vektoria::ULDebug("Searching for Save-File");
		std::fstream file("Positions.txt");
		if (file.is_open()) {
			Vektoria::ULDebug("Save-File found");
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
			Vektoria::ULDebug(tempstring.c_str());
			
			float x_val = std::stof(x_valstr);
			Vektoria::ULDebug("Get Values");
			tp.erase(0, pos + del.length());
			std::string z_valstr = tp.substr(0, pos);
			tempstring = z_valstr;
			Vektoria::ULDebug(tempstring.c_str());
			
			float z_val = std::stof(z_valstr);
			tp.erase(0, pos + del.length());

			this->SetPlacement(x_val, z_val, this->getObj(obj));
			
			obj_cnt++;
		}

		file.close();
	
}

int Load::getObjCount()
{
	return obj_cnt;
}

int* Load::LoadPlayerStats()
{
	Vektoria::ULDebug("Searching for Player-Stats");
	std::fstream file("Ressources.txt");
	if (file.is_open()) {
		Vektoria::ULDebug("Player-Stats found");
	}

	std::string tp;
	size_t pos = 0;
	int* arr = new int[3];
	while (getline(file, tp)) {
		std::string del = ", ";
		pos = tp.find(del);
		std::string tempstring = tp;

		std::string resstr1 = tp.substr(0, pos);
		Vektoria::ULDebug(resstr1.c_str());
		int res1 = std::stoi(resstr1);
		tp.erase(0, pos + del.length());
		
		pos = tp.find(del);
		std::string resstr2 = tp.substr(0, pos);
		Vektoria::ULDebug(resstr2.c_str());
		int res2 = std::stoi(resstr2);
		tp.erase(0, pos + del.length());

		pos = tp.find(del);
		std::string resstr3 = tp.substr(0, pos);
		Vektoria::ULDebug(resstr3.c_str());
		int res3 = std::stoi(resstr3);
		tp.erase(0, pos + del.length());
		
		arr[0] = res1;
		arr[1] = res2;
		arr[2] = res3;
	}

	file.close();

	return arr;

}



GameObject* Load::GetGeos(int i)
{
	return geo_arr[i];
}

void Load::SetGeos(GameObject * GO, int id)
{
	geo_arr[id] = GO;

	
	
}
//Karo end