#include "Game.h"

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

//lea START
void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)	//psplash is splash screen
{
	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	m_zr.Init(psplash);
	//m_zf.SetApiRender(eApiRender_DirectX12);
	m_zf.Init(hwnd, procOS);
	m_zv.InitFull(&m_zc);	//with adresse of camera bcoz viewport
	m_zo.InitFull(&m_zi);
	m_zi.Init("textures//ENV.jpg");	//double slash
	m_zc.Init(QUARTERPI); //field of view float or variable
	m_zgPlane.Init(500, 500, &m_zmPlane, 10, 10);	//world plane
	m_zs.SetSkyOn(&m_zpCamera);
	m_zlp.Init(CHVector(0.2f, -0.2f, -0.8f), CColor(1.0f, 1.0f, 0.0f));	//yellow sun?

	m_zr.AddFrame(&m_zf);
	m_zf.AddViewport(&m_zv);
	//m_zv.AddOverlay(&m_zo);

	m_zf.AddDeviceKeyboard(&m_zdk);

	m_zr.AddScene(&m_zs);
	m_zs.AddLightParallel(&m_zlp);
	m_zs.AddPlacement(&m_zpCamera);

	m_zs.AddPlacement(&m_zpPlane); // Plane simulates "building ground" & flickers through the Terrain
	m_zpPlane.AddGeo(&m_zgPlane);
	m_zpPlane.TranslateY(1.0f);

	m_zs.AddPlacement(m_zTerrain.getPlacement());
	m_zCollisionTerrain.Add(m_zTerrain.getGeometry());

	m_zpCamera.AddCamera(&m_zc);

	//Cam is looking on the plane in a 45' angle
	m_zpCamera.SetPointing(&m_zTerrainPlacement); // Cam now looking at the Center of Terrain

	m_zpCamera.SetTranslationSensitivity(40);
	m_zpCamera.Translate(500.0f, 1500.0f, 0.0f);

	m_zpCamera.RotateXDelta(QUARTERPI);



	m_zmPlane.MakeTextureDiffuse("textures//ENV.jpg");
}

void CGame::Tick(float fTime, float fTimeDelta)	//ftime seit spielbeginn
{
	// Hier die Echtzeit-Veränderungen einfügen:
	m_zr.Tick(fTimeDelta);
	//m_zpPlane.RotateX(fTime);
	m_zdk.PlaceWASD(m_zpCamera, fTimeDelta);
}

//lea END

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
}

