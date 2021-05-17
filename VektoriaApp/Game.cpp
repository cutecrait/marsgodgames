#include "Game.h"
#include "MapSquare.h"
#include "CCameraController.h"

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
	
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)	//psplash is splash screen
{
	// ROOT--------------------------------
	m_zr.Init(psplash);
	m_zr.AddScene(&m_zs);
	//m_zf.SetApiRender(eApiRender_DirectX12);
	m_zf.Init(hwnd, procOS);
	m_zr.AddFrame(&m_zf);
	

	// CAMERA & VIEWPORT-------------------------------------------------------
	m_zv.InitFull(&m_zc);	//with adresse of camera bcoz viewport
	m_zo.InitFull(&m_zi);
	m_zi.Init("textures\\ENV.jpg");	//double slash
	m_zc.Init(QUARTERPI); //field of view float or variable
	m_zs.AddPlacement(&m_zpCamera);
	m_zpCamera.AddCamera(&m_zc);
	m_zf.AddViewport(&m_zv);

	m_zpCamera.RotateX(-QUARTERPI); //45°-Winkel
	m_zpCamera.RotateYDelta(PI + QUARTERPI);
	m_zpCamera.TranslateDelta(0, 5.f, 0);

	//<Darius>
	CameraController.AssignCameraPlacement(&m_zpCamera);
	CameraController.AssignDeviceKeyboard(&m_zdk);
	CameraController.AssignDeviceMouse(&m_zdm);
	/*
	Funktionsweise der Kamera:
		WASD: Translieren der Kamera parallel zur XZ-Ebene
		Mausrad: Zoomen (Bewegung in Blickrichtung)
		rechter Mausbutton + Schwenken: Kamerarotation
	*/
	//</Darius>


	// INPUTS---------------------------------------------------
	m_zf.AddDeviceCursor(&einCursor);
	m_zf.AddDeviceKeyboard(&m_zdk);
	m_zf.AddDeviceMouse(&m_zdm);

	// AUDIO------------------------------------------------
	AudioManager.Init(&m_zs);
	

	// LIGHTING--------------------------------------
	lightingManager.Init(&m_zs, &m_zpCamera);

	// OVERLAY-----------------------------------------
	// texturen werden jetzt in UI erstellt. 
	// UI = menu, derManager = click-event.
	m_player.initPlayer(1000, 1000, 1000);
	einsFont.LoadPreset("LucidaConsoleWhite");
	einsFont.SetChromaKeyingOn(); //hiermit hat die font keinen hässlichen hintergrund
	menu.InitMenu(&einCursor, &einsFont, &m_zv, &m_player);
	derManager.Init(&menu, &m_zs, &AudioManager, &m_player, &BuildingManager, &mapSquare);

	// MAP SQUARES---------------------------------------
	MakeMapSquares(&m_zs);
	BuildingManager.Init(&m_zs);

	//Terrain
	m_zs.AddPlacement(m_ldgame.LoadTerrain());

	// Testcubes
	/*
	for (int i = 0; i < 100; i++)
	{
		m_zs.AddPlacement(m_ldgame.GetPlacements(i));
	}
	*/


	

}

void CGame::Tick(float fTime, float fTimeDelta)	//ftime seit spielbeginn
{
	m_zr.Tick(fTimeDelta);

	// CAMERA-----------------------------------
	CameraController.UpdateCameraMovement(fTimeDelta); //Aktualisiert die Kamerabewegung

	// lighting
	lightingManager.Tick(fTimeDelta);
	

	derManager.Click(fTimeDelta, &einCursor);
	
	// UI-----------------------------------
	
	
	//derManager.makeBuilding(selectedPlace,&einCursor);
}

void CGame::MakeMapSquares(CScene* m_zs)
{
	for (int iz = 0; iz < 10; iz++)
	{
		for (int ix = 0; ix < 10; ix++)
		{
			auto sqr = new MapTile(ix, 0.0, iz, 2, &mapSquare);
			m_zs->AddPlacement(sqr);
			mapSquare.Add(sqr);
		}
	}
}

void CGame::Fini()
{
	
	// Hier die Finalisierung Deiner Vektoria-Objekte einf�gen
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergr��e ver�ndert wurde.
	// Hier kannst Du dann die Aufl�sung des Viewports neu einstellen:
}

