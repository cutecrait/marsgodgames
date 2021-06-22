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
	for (int i = 0; i < 20; i++)
	{
		apartment[i] = new Apartment();
		obama[i] = new Barrack();
		controlcenter[i] = new ControlCenter();
		foodfarm[i] = new FoodFarm();
		gravelplant[i] = new GravelPlant();
		hospital[i] = new Hospital();
		laboratory[i] = new Laboratory();
		launchpad[i] = new Launchpad();
		mine[i] = new Mine();
		nuclearpowerplant[i] = new NuclearPowerPlant();
		robotfactory[i] = new RobotFactory();
		solarpowerplant[i] = new SolarPowerPlant();
		treefarm[i] = new TreeFarm();
		well[i] = new Well();
	}

	apart_anz = 0;
	barr_anz = 0;
	contr_anz = 0;
	food_anz = 0;
	found_anz = 0;
	gravel_anz = 0;
	hos_anz = 0;
	lab_anz = 0;
	launch_anz = 0;
	mine_anz = 0;
	nuc_anz = 0;
	solar_anz = 0;
	robo_anz = 0;
	tree_anz = 0;
	well_anz = 0;

	

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
		

		this->SetGeos(apartment[apart_anz], this->getObjCount());
		apart_anz++;
		return geo_arr[this->getObjCount()];
	}

	else if (obj_name == std::string("Barrack")) {


		this->SetGeos(obama[barr_anz], this->getObjCount());
		barr_anz++;
		return geo_arr[this->getObjCount()];
	}

	else if (obj_name == std::string("ControlCenter")) {
		

		this->SetGeos(controlcenter[contr_anz], this->getObjCount());
		contr_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("FoodFarm")) {
	

		this->SetGeos(foodfarm[food_anz], this->getObjCount());
		food_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Foundry")) {
		

		this->SetGeos(foundry[found_anz], this->getObjCount());
		found_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("GravelPlant")) {
	

		this->SetGeos(gravelplant[gravel_anz], this->getObjCount());
		gravel_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Hospital")) {

		this->SetGeos(hospital[hos_anz], this->getObjCount());
		hos_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Laboratory")) {
		

		this->SetGeos(laboratory[lab_anz], this->getObjCount());
		lab_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Launchpad")) {
		

		this->SetGeos(launchpad[launch_anz], this->getObjCount());
		launch_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Mine")) {
		

		this->SetGeos(mine[mine_anz], this->getObjCount());
		mine_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("NuclearPowerPlant")) {
		

		this->SetGeos(nuclearpowerplant[nuc_anz], this->getObjCount());
		nuc_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("RobotFactory")) {
		

		this->SetGeos(robotfactory[robo_anz], this->getObjCount());
		robo_anz++;
		return geo_arr[this->getObjCount()];
	}

	else if (obj_name == std::string("SolarPowerPlant")) {

		this->SetGeos(solarpowerplant[solar_anz], this->getObjCount());
		solar_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("TreeFarm")) {
		

		this->SetGeos(treefarm[tree_anz], this->getObjCount());
		tree_anz++;
		return geo_arr[this->getObjCount()];
	}
	else if (obj_name == std::string("Well")) {
		

		this->SetGeos(well[well_anz], this->getObjCount());
		well_anz++;
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

void Load::readPos()
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
			std::string z_valstr = tp.substr(0, pos);
			tempstring = z_valstr;
			//Vektoria::ULDebug(tempstring.c_str());
			
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
		ULDebug(tp.c_str());
	}

	file.close();

	

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