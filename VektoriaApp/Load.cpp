#include "Load.h"



Load::Load()
{
	pos_id = 0;
	*pos_arr = new float[100];
	cube_mat = new CMaterial();
	cube_mat->Init();
	cube_mat->MakeTextureDiffuse("textures\\ENV.jpg");
	m_placecube = new CPlacement();
	m_cube.Init(0.2f, cube_mat, 1.0f);
	this->SetGeos();
	for (int iz = 0; iz < 10; iz++)
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
	
	m_placements[50]->AddGeo(&m_cube);

	m_placecube->AddGeo(&m_cube);
	m_placecube->Translate(pos_arr[4][0], pos_arr[4][1], pos_arr[4][2]);
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

void Load::setPosArray(float x, float y, float z)
{
	

	
}

CPlacement* Load::LoadTerrain()
{
	//collterr.Add(m_lterrain.getGeometry());
	m_lcollisionterr.Add(m_lterrain.getGeometry());
	return m_lterrain.getPlacement();
}

CPlacement* Load::TestCube() 
{
	
	return m_placecube;
}

CPlacement* Load::GetPlacements(int i)
{
	return m_placements[i];
}

CGeo* Load::GetGeos(int i)
{
	return geo_arr[i];
}

void Load::SetGeos()
{
	for (int i = 0; i < 100; i++)
	{
		if ((i % 2) == 0){
			geo_arr[i] = new CGeo();
		geo_arr[i] = &m_cube;
	}
		else {
			geo_arr[i] = new CGeo();
			geo_arr[i] = nullptr;
		}
			

	}
}
