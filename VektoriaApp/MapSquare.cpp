#include "MapSquare.h"

MapSquare::MapSquare(float x, float y, float z, float size)
{
	MainGeo = new CGeoGrid();
	MainGeo->Init(size, size, new CMaterial(), 2, 2);
	AddGeo(MainGeo);
	Translate(x, y, z);
	MainGeo->m_pmaterial->LoadPreset("CarpetFluffy");
	MainGeo->m_pmaterial->Translate(CColor(0.6, 0.0, 0.0));
	MainGeo->Center();
}

MapSquare::MapSquare()
{
}

MapSquare::~MapSquare()
{
}

void MapSquare::Select()
{
	selected = true;
	MainGeo->m_pmaterial->Translate(CColor(0.2, 1.0, 0.2));
}

void MapSquare::Deselect()
{
	selected = false;
	MainGeo->m_pmaterial->Translate(CColor(0.6, 0.0, 0.0));
}
