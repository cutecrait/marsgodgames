#include "CTerrain.h"


CTerrain::CTerrain()
{
	m_iSeed = 20;

	m_cutRock.SetHeightLimits(-TERRAIN_ROCK_MAX, TERRAIN_ROCK_MAX);
	m_cutRock.SetHeightInverseOn();
	m_cutRock.SetFlattenLowerOn();
	m_cutRock.SetFlattenUpperOff();


	m_zgTerrainInverseRock.AddCut(&m_cutRock);


	m_zPerlinNoise = new CPerlin(
		m_iSeed,							//zufallsseed
		1.9f,						//Amplitude
		7.0,							//Oktaven
		0.5f,						//Persistenz
		6.0f,						//Frequenz
		0.0f,						//X-Verschiebun  g
		0.0f,						//Y-Verschiebung
		ePerlinInterpol_Standard,	//Interpolationsart
		false);						//Repetivität



	m_zmRock.LoadPreset("RockMossy"); // TBA: echte Mars-Textur
	m_zmRock.MakeTextureDiffuse("textures//Mars_Ground.jpg");;


	//Blobs
	m_zbElevation = new CBlob(0.5f, 0.5f, 2.0f, 2.0f, TERRAIN_HEIGHT, eBlobShapeGround_Donut, eBlobShapeSide_Hill, m_zPerlinNoise);

	//Blob dem Terrain hinzufügen

	m_zgTerrainAll.AddBlob(m_zbElevation);

	//Vertex-Daten erzeugen
	m_zgTerrainAll.CreateField(
		TERRAIN_SIZE, TERRAIN_SIZE,							// Terrain-Größe: Breite x Länge
		TERRAIN_VERTICES, TERRAIN_VERTICES,					//1000 x 1000 vertices
		0.0f, 0.0f,											//UV-textur beginnt bei (0,0)
		100.0f, 100.0f);



	m_zgTerrainInverseRock.InitFromOther(m_zgTerrainAll, &m_zmRock);

	//Geos an placement hängen:
	m_zpTerrain.AddGeo(&m_zgTerrainAll);
	m_zgTerrainAll.SetDrawingOff();

	m_zpTerrain.AddGeo(&m_zgTerrainInverseRock);
	m_zpTerrain.Translate(0.0f,-0.16f, 0.0f);

}

CTerrain::~CTerrain()
{

}

CPlacement* CTerrain::getPlacement()
{
	return &m_zpTerrain;
}

CGeoTerrain* CTerrain::getGeometry()
{
	return &m_zgTerrainAll;
}