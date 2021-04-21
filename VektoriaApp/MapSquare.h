#pragma once

#include "Vektoria\Root.h"
using namespace Vektoria;
using namespace std;

class MapSquare : public CPlacement
{
public:
	MapSquare();
	MapSquare(float x, float y, float z, float size);
	~MapSquare();

	bool Free = true;
	string BuildingName = "";
	CGeoGrid* MainGeo = nullptr;

	//void AddAsChild(CScene* parent);
	void Select();
	void Deselect();

private:
	bool selected = false;
};

