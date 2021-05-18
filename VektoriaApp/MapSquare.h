#pragma once

#include "Vektoria\Root.h"
using namespace Vektoria;
using namespace std;

class MapTile;

class MapSquare : public CPlacements
{
public:
	MapSquare();
	~MapSquare();

	bool Free = true;
	string BuildingName = "";
	CGeoGrid* MainGeo = nullptr;

	//void AddAsChild(CScene* parent);
	//void Select();

	void DeselectMapTile(MapTile*);

	void setLevel(CDeviceKeyboard*);

	CMaterial m_MaterialTile_Selected;

private:

	bool selected = false;
	

	// Pointer auf das letzte selektierte Element
	MapTile* lastSelected = NULL;
};

