#include "MapTile.h"

MapTile::MapTile()
{

}

MapTile::~MapTile()
{
	
}

void MapTile::Select()
{
	//MainGeo->m_pmaterial->Translate(CColor(0.2, 1.0, 0.2));
	MainGeo->SetMaterial(&m_mapPointer->m_MaterialTile_Selected);
	//MainGeo->m_pmaterial->SetTransparencyOn();
	m_mapPointer->DeselectMapTile(this);
}

void MapTile::setOwnMaterial()
{
	//MainGeo->m_pmaterial->SetTransparencyOn();
	MainGeo->SetMaterial(m_MaterialTile_Normal);
	
}

CPlacement* MapTile::GetNodePlacement()
{
	return _nodePlacement;
}

Pathfinding::Node* MapTile::GetNode()
{
	return _node;
}

void MapSquare::DeselectMapTile(MapTile* tile)
{
	if ((tile == NULL && lastSelected == NULL) || tile == lastSelected)
	{
		return;
	}

	if (lastSelected != tile)
	{
		if (lastSelected) {
			//lastSelected->MainGeo->m_pmaterial->Translate(CColor(0.6, 0.0, 0.0));
			lastSelected->setOwnMaterial();
		}

		lastSelected = tile;
	}
}

void MapSquare::setLevel(CDeviceKeyboard* m_zdk)
{
	if (m_zdk->KeyDown(DIK_1))
	{
		for (int i = 0; i < m_iPlacements; i++)
		{
			CHVector temp = m_applacement[i]->GetPos();
			if ((temp.m_fz < 4 || temp.m_fz > 13) || (temp.m_fx < 4 || temp.m_fx > 13))
			{
				m_applacement[i]->SwitchOff();
			}
		}
		return;
	}

	if (m_zdk->KeyDown(DIK_2))
	{
		for (int i = 0; i < m_iPlacements; i++)
		{
			CHVector temp = m_applacement[i]->GetPos();

			m_applacement[i]->SwitchOn();			

			if ((temp.m_fz < 2 || temp.m_fz > 15) || (temp.m_fx < 2 || temp.m_fx > 15))
			{
				m_applacement[i]->SwitchOff();
			}
		}
		return;
	}

	if (m_zdk->KeyDown(DIK_3))
	{
		for (int i = 0; i < m_iPlacements; i++)
		{
				m_applacement[i]->SwitchOn();
		}
		return;
	}

}

MapTile::MapTile(float x, float y, float z, float size, MapSquare* map)
{
	MainGeo = new CGeoGrid();
	MainGeo->Init(size, size, new CMaterial(), 2, 2);
	AddGeo(MainGeo);
	Translate(x, y, z);
	MainGeo->m_pmaterial->MakeTextureDiffuse("textures\\MapTile.png");
	m_MaterialTile_Normal = MainGeo->m_pmaterial;
	MainGeo->m_pmaterial->SetTransparencyOn();
	//MainGeo->m_pmaterial->Translate(CColor(0.6, 0.0, 0.0));
	MainGeo->Center();
	m_mapPointer = map;
	
	//Pathfinding Node
	_nodePlacement = new CPlacement();
	this->AddPlacement(_nodePlacement);
	_node = new Pathfinding::Node(this);
}

MapSquare::MapSquare()
{
	m_MaterialTile_Selected.MakeTextureDiffuse("textures\\MapTile_Selected.png");
	m_MaterialTile_Selected.SetTransparencyOn();
	m_MaterialTile_Selected.SetTransparency(0.6);
	
}

MapSquare::~MapSquare()
{
	for (int i = 0; i < m_iPlacements; i++)
	{
		delete m_applacement[i];
	}
}

