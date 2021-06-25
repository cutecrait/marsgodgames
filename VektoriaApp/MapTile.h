#pragma once
#include "Vektoria\root.h"
#include "MapSquare.h"
#include "Node.h"

using namespace Vektoria;

class MapTile :
	public CPlacement
{
public:
	MapTile();
	MapTile(float x, float y, float z, float size, MapSquare*);
	~MapTile();

	bool Free = true;
	string BuildingName = "";
	CGeoGrid* MainGeo = nullptr;

	void Select();

	// Lege normale (unselektierte, etc.) Textur an
	void setOwnMaterial();

	CPlacement* GetNodePlacement();
	Pathfinding::Node* GetNode();

private:
	MapSquare* m_mapPointer;
	CMaterial* m_MaterialTile_Normal;

	CPlacement* _nodePlacement;
	/// <summary>
	/// Pfadfindungsknoten der Kachel
	/// </summary>
	Pathfinding::Node* _node;
};

