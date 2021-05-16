#include "MapTile.h"

MapTile::MapTile()
{

}

MapTile::~MapTile()
{

}

void MapTile::Select()
{
	MainGeo->m_pmaterial->Translate(CColor(0.2, 1.0, 0.2));
	m_mapPointer->DeselectMapTile(this);
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
			lastSelected->MainGeo->m_pmaterial->Translate(CColor(0.6, 0.0, 0.0));
		}

		lastSelected = tile;
	}
}

MapTile::MapTile(float x, float y, float z, float size, MapSquare* map)
{
	MainGeo = new CGeoGrid();
	MainGeo->Init(size, size, new CMaterial(), 2, 2);
	AddGeo(MainGeo);
	Translate(x, y, z);
	MainGeo->m_pmaterial->LoadPreset("CarpetFluffy");
	MainGeo->m_pmaterial->Translate(CColor(0.6, 0.0, 0.0));
	MainGeo->Center();
	m_mapPointer = map;
}

MapSquare::MapSquare()
{
}

MapSquare::~MapSquare()
{
}

