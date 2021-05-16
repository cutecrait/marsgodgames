#include "MapSquare.h"

MapSquare::MapSquare(float x, float y, float z, float size)
{
	MainGeo = new CGeoGrid();
	CMaterial* mat = new CMaterial();
	mat->Init();
	MainGeo->Init(size, size, mat, 2, 2);
	AddGeo(MainGeo);
	Translate(x, y, z);
	MainGeo->Center();
	mat->SetTransparencyOn();
	mat->SetTransparency(0.4f);
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
	MainGeo->m_pmaterial->SetTransparencyOff();
	MainGeo->m_pmaterial->SetTransparency(0.0f);
}

void MapSquare::Deselect()
{
	selected = false;
	MainGeo->m_pmaterial->SetTransparencyOn();
}
