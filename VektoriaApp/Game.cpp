#include "Game.h"
#include "Player.h"
#include "Apartment.h"
CGame::CGame(void)
{

}

CGame::~CGame(void)
{

}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash* psplash)	//psplash is splash screen
{
	// ROOT--------------------------------
	m_zr.Init(psplash);
	m_zr.AddScene(&m_zs);
	//m_zf.SetApiRender(eApiRender_DirectX12);
	//m_zf.SetApiSound(eApiSound_DirectSound);
	m_zf.Init(hwnd, procOS);
	m_zr.AddFrame(&m_zf);

	AssetManager::Init("");

	m_level1 = new LevelSystem::Level("ultra", 1000,1);
	m_level1->AddMission(new LevelSystem::Mission("Kaufe Roboterfabrik",typeid(RobotFactory).name(), 0, 1));
	m_level1->AddMission(new LevelSystem::Mission("Kaufe drei Bauroboter",typeid(testRobo).name() , 0, 3));

	m_level2 = new LevelSystem::Level("cool", 1000,2);
	m_level2->AddMission(new LevelSystem::Mission("Kaufe zwei Landwirtroboter", typeid(testRobo).name(), 0, 2));
	m_level2->AddMission(new LevelSystem::Mission("Kaufe ein Apartment", typeid(Apartment).name(), 0, 1));
	
	m_level3 = new LevelSystem::Level("cool", 1000, 3);

	LevelSystem::LevelManager::Instance().AddLevel(m_level1);
	LevelSystem::LevelManager::Instance().AddLevel(m_level2);
	LevelSystem::LevelManager::Instance().AddLevel(m_level3);
	
	// CAMERA & VIEWPORT-------------------------------------------------------
	m_zv.InitFull(&m_zc);	//with adresse of camera bcoz viewport
	m_zv.SetBloomOn();
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
	CAudioManager::Instance().Init(&m_zs);


	// LIGHTING--------------------------------------
	lightingManager.Init(&m_zs, &m_zpCamera);

	// OVERLAY-----------------------------------------
	// texturen werden jetzt in UI erstellt. 
	// UI = menu, derManager = click-event.
	if (m_ldgame.fileExists("Ressources.txt")) {
		Player::Instance().initPlayer(m_ldgame.playerdets[0], m_ldgame.playerdets[1], m_ldgame.playerdets[2]);
		m_ldgame.setPlayerDetails();
	}
	else {
		Player::Instance().initPlayer(1000, 1000, 1000);
	}
	einsFont.LoadPreset("LucidaConsoleWhite");
	einsFont.SetChromaKeyingOn(); //hiermit hat die font keinen hässlichen hintergrund

	//StartScreen
	m_startscr.InitStartScreen(&einCursor, &einsFont, &m_zv);

	menu.InitMenu(&einCursor, &einsFont, &m_zv);
	derManager.Init(&menu, &m_zs, &CBuildingManager::Instance(), &mapSquare);
	LevelSystem::LevelManager::Instance().GetCurrentLevel()->initLevel(&menu);
	// MAP SQUARES---------------------------------------
	CBuildingManager::Instance().Init(&m_zs);
	MakeMapSquares(&m_zs);

	//LOAD TERRAIN---------------------------------------
	m_zs.AddPlacement(m_ldgame.LoadTerrain());

	//LOAD CHECKPOINT------------------------------------
	for (int i = 0; i < m_ldgame.getObjCount(); i++)
	{
		m_zs.AddPlacement(m_ldgame.GetPlacements(i));
	}

	derManager.setBuildingGeos(CBuildingManager::Instance().getBuildingGeos());

	foundryCtrl.Init();
	gpCtrl.Init();
}

void CGame::Tick(float fTime, float fTimeDelta)	//ftime seit spielbeginn
{
	m_zr.Tick(fTimeDelta);

	// CAMERA-----------------------------------
	CameraController.UpdateCameraMovement(fTimeDelta); //Aktualisiert die Kamerabewegung

	// lighting
	lightingManager.Tick(0);
	

	derManager.Click(fTimeDelta, &einCursor, LevelSystem::LevelManager::Instance().GetCurrentLevel());

	// UI-----------------------------------

	if (m_startscr.update() == 1) {
		Reload();
	}

	//derManager.makeBuilding(selectedPlace,&einCursor);
	mapSquare.setLevel(&m_zdk);

	// buildings
	gpCtrl.Update(fTimeDelta);
	foundryCtrl.Update(fTimeDelta);
}

void CGame::MakeMapSquares(CScene* m_zs)
{
	for (int iz = 0; iz < 18; iz++)
	{
		for (int ix = 0; ix < 18; ix++)
		{
			auto sqr = new MapTile(ix, 0.0, iz, 2, &mapSquare);
			m_zs->AddPlacement(sqr);
			mapSquare.Add(sqr);

			// Schalte alle Tiles aus, die nicht im ersten Quadrat enthalten sind
			if ((iz < 4 || iz > 13) || (ix < 4 || ix > 13))
				sqr->SwitchOff();
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
	m_zf.ReSize(iNewWidth, iNewHeight);
}

void CGame::Reload() //Fur den Fall dass ein neues Spiel begonnen wird
{
	//reload Player & Positions
	ULDebug("Reloading");
	for (int i = 0; i < m_ldgame.getObjCount(); i++)
	{
		if (i > 2)
			m_ldgame.GetPlacements(i)->SwitchOff();
	}

	m_ldgame.setPlayerDetails();
	Player::Instance().initPlayer(m_ldgame.playerdets[0], m_ldgame.playerdets[1], m_ldgame.playerdets[2]);
	menu.updatePlayer();
}