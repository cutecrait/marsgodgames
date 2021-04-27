#pragma once

#include "Vektoria\Root.h"
using namespace Vektoria;


#ifndef _M_X64
#error "64 bit architecture is required for the Terrain"
#endif // !_M_X64


constexpr float TERRAIN_SIZE = 550.0f;
constexpr int TERRAIN_VERTICES = 301;
constexpr float TERRAIN_HEIGHT = 1200.0f;
constexpr float TERRAIN_SAND_MAX = 3.0f;
constexpr float TERRAIN_ROCK_MAX = 500.0f;



class CTerrain
{
public:
	CTerrain();
	~CTerrain();
	bool setPlacement(CPlacement& placement);
	bool setSeed(float perlineSeed);
	CGeoTerrain* construct();
	CPlacement* getPlacement();
	CGeoTerrain* getGeometry();



private:
	CPlacement m_zpTerrain;


	CGeoTerrain m_zgTerrainAll; //Gesamtes Terrain

	CGeoTerrain m_zgTerrainInverseRock;

	CPerlin* m_zPerlinNoise = nullptr; //Perlin-Noise

	CBlob* m_zbElevation = nullptr; //Erhebungen, Hügel, Berge


	//Schnitte des Terrains

	CCut m_cutRock;

	//Materialien
	CMaterial m_zmRock;  //steiniges Material




	CRandom m_RandomSeed;
	int m_iSeed;

};