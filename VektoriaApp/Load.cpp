#include "Load.h"



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
	cube_mat = new CMaterial();
	cube_mat->Init();
	cube_mat->MakeTextureDiffuse("textures\\ENV.jpg");
	m_cube.Init(0.2f, cube_mat, 1.0f);
	this->SetGeos();
	/*for (int iz = 0; iz < 10; iz++)
	{
		for (int ix = 0; ix < 10; ix++)
		{
			m_placements[pos_id] = new CPlacement();
			pos_arr[pos_id] = new float[3];
			pos_arr[pos_id][0] = ix - 0.5f;
			pos_arr[pos_id][1] = 0.2f;
			pos_arr[pos_id][2] = iz - 0.5f;
			
			m_placements[pos_id]->Translate(pos_arr[pos_id][0], pos_arr[pos_id][1], pos_arr[pos_id][2]);
			
			
			m_placements[pos_id]->AddGeo(this->GetGeos(pos_id));

			pos_id += 1;
		}
	}
	
	m_placements[50]->AddGeo(&m_cube);*/	

	
}

Load::~Load()
{
}

void Load::LoadPlacements(CScene scene)
{
	
	
	/*
	for (int iz = 0; iz < 10; iz++)
	{
		for (int ix = 0; ix < 10; ix++)
		{
			m_lplace = new CPlacement();
			m_lplace->Translate(ix, 0.0, iz);
			auto sqr = new MapSquare(ix, 0.0, iz, 2);
			m_zs.AddPlacement(sqr);
			squares.Add(sqr);
		}
	}*/
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

void Load::SetPlacement(float x, float z, CGeo* geo)
{
	//m_placements[obj_cnt] = new CPlacement();
	m_placements[obj_cnt]->Translate(x, 0.5f, z);
	m_placements[obj_cnt]->AddGeo(geo);
}

CGeo *Load::getObj(std::string obj_name)
{
	
	/*if (obj_name == std::string("CGeoCube"))
	{*/
		//((CGeoCube* cube = new CGeoCube();
		
		return geo_arr[this->getObjCount()];
	/*}

	else
	return nullptr;*/
}

CPlacement* Load::LoadTerrain()
{
	//collterr.Add(m_lterrain.getGeometry());
	m_lcollisionterr.Add(m_lterrain.getGeometry());
	return m_lterrain.getPlacement();
}


CPlacement* Load::GetPlacements(int i)
{
	if (this->getObjCount() > 0)
		return m_placements[i];

	else
		return nullptr;
}

void Load::readPos()
{
		std::fstream file;
		file.open("Positions.txt", std::ios::out);
		std::string tp;
		size_t pos = 0; 
		while (getline(file, tp)) {
			
			std::string del = ", ";
			pos = tp.find(del);
			std::string obj = tp.substr(0, pos);
			tp.erase(0, pos + del.length());
			std::string x_valstr = tp.substr(0, pos);
			float x_val = std::stof(x_valstr);
			tp.erase(0, pos + del.length());
			std::string z_valstr = tp.substr(0, pos);
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

CGeo* Load::GetGeos(int i)
{
	return geo_arr[i];
}

void Load::SetGeos()
{
	for (int i = 0; i < 100; i++)
	{
			geo_arr[i] = new CGeoCube();
			geo_arr[i]->Init(1.0f, cube_mat, 1.0f, false);
	}
}
