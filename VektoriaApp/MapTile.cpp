#include "MapTile.h"

CColor MapTile::defaultColor = CColor(0.25f, 0.0f, 0.0f);
CColor MapTile::selectedColor = CColor(0.2f, 1.0f, 0.2f);

MapTile::MapTile()
{

}

MapTile::~MapTile()
{

}

void MapTile::Select()
{
	MainGeo->m_pmaterial->Translate(selectedColor);
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
			lastSelected->MainGeo->m_pmaterial->Translate(MapTile::defaultColor);
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
	MainGeo->m_pmaterial->LoadPreset("EarthCracked");
	MainGeo->m_pmaterial->Translate(defaultColor);
	MainGeo->Center();
	m_mapPointer = map;
}

MapSquare::MapSquare()
{
}

MapSquare::~MapSquare()
{
}

