#pragma once
#include "Vektoria\root.h"
#include "MapSquare.h"

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


private:

    MapSquare* m_mapPointer;

};
