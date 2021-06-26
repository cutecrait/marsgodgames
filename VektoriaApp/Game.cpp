#include "Game.h"
#include "Player.h"
#include "Apartment.h"
#include "NodeController.h"
#include "JobController.h"

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

	m_level1 = new LevelSystem::Level("Prolog", 1000, 1);
	m_level1->AddMission(new LevelSystem::Mission(1, "Baue 2 Apartments", typeid(Apartment).name(), 0, 2));
	m_level1->AddMission(new LevelSystem::Mission(2, "Baue einen Brunnen", typeid(Well).name(), 0, 1));
	m_level1->AddMission(new LevelSystem::Mission(3, "Baue eine Mine", typeid(Mine).name(), 0, 1));

	m_level2 = new LevelSystem::Level("Post-Prolog", 1000, 2);
	m_level2->AddMission(new LevelSystem::Mission(1, "Baue eine FoodFarm", typeid(FoodFarm).name(), 0, 1));
	m_level2->AddMission(new LevelSystem::Mission(2, "Baue 2 SPPs", typeid(SolarPowerPlant).name(), 0, 2));
	m_level2->AddMission(new LevelSystem::Mission(3, "Baue eine Foundry", typeid(Foundry).name(), 0, 1));

	m_level3 = new LevelSystem::Level("Advanced", 2000, 3);
	m_level3->AddMission(new LevelSystem::Mission(1, "Baue eine GravelPlant", typeid(GravelPlant).name(), 0, 1));
	m_level3->AddMission(new LevelSystem::Mission(2, "Baue ein Labor", typeid(Laboratory).name(), 0, 1));
	m_level3->AddMission(new LevelSystem::Mission(3, "Baue eine Rob-Fab.", typeid(RobotFactory).name(), 0, 1));


	LevelSystem::LevelManager::Instance().AddLevel(m_level1);
	LevelSystem::LevelManager::Instance().AddLevel(m_level2);
	LevelSystem::LevelManager::Instance().AddLevel(m_level3);

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
	CAudioManager::Instance().Init(&m_zs);


	// LIGHTING--------------------------------------
	lightingManager.Init(&m_zs, &m_zpCamera, &m_zv);

	// OVERLAY-----------------------------------------
	// texturen werden jetzt in UI erstellt. 
	// UI = menu, derManager = click-event.
	if (m_ldgame.fileExists("PlayerDetails.txt")) {
		m_ldgame.setPlayerDetails();
		Player::Instance().initPlayer(m_ldgame.playerdets[0], m_ldgame.playerdets[1], m_ldgame.playerdets[2]);

	}
	else {
		Player::Instance().initPlayer(1000, 1000, 1000);
	}
	einsFont.LoadPreset("LucidaConsoleWhite");
	einsFont.SetChromaKeyingOn(); //hiermit hat die font keinen hässlichen hintergrund

	//StartScreen: LOADS CHECKPOINT ---------------------
	m_startscr.InitStartScreen(&einCursor, &einsFont, &m_zv);

	menu.InitMenu(&einCursor, &einsFont, &m_zv);
	derManager.Init(&menu, &m_zs, &CBuildingManager::Instance(), &mapSquare);
	LevelSystem::LevelManager::Instance().GetCurrentLevel()->initLevel(&menu);
	// MAP SQUARES---------------------------------------
	CBuildingManager::Instance().Init(&m_zs);
	MakeMapSquares(&m_zs);

	//LOAD TERRAIN---------------------------------------
	m_zs.AddPlacement(m_ldgame.LoadTerrain());

	CPlacement* robotplacement = new CPlacement();
	JobSystem::JobController::Instance().InitRobots(robotplacement, 5);
	m_zs.AddPlacement(robotplacement);

	derManager.setBuildingGeos(CBuildingManager::Instance().getBuildingGeos());

	foundryCtrl.Init();
	gpCtrl.Init();
	tfCtrl.Init();
}

void CGame::Tick(float fTime, float fTimeDelta)	//ftime seit spielbeginn
{
	m_zr.Tick(fTimeDelta);

	// CAMERA-----------------------------------
	CameraController.UpdateCameraMovement(fTimeDelta); //Aktualisiert die Kamerabewegung

	// lighting
	lightingManager.Tick(fTimeDelta);


	derManager.Click(fTimeDelta, &einCursor, LevelSystem::LevelManager::Instance().GetCurrentLevel());

	// UI-----------------------------------
	if (!ingame) {
		int bla = m_startscr.update();
		if (bla == 1) {
			menu.updatePlayer();
			ingame = true;
		}
		else if (bla == 2) {
			IWantToDIE = true;
		}
	}
	
	//derManager.makeBuilding(selectedPlace,&einCursor);
	mapSquare.setLevel(&m_zdk);

	// buildings
	gpCtrl.Update(fTimeDelta);
	foundryCtrl.Update(fTimeDelta);
	tfCtrl.Update(fTimeDelta);
	JobSystem::JobController::Instance().Update(fTimeDelta);
}

void CGame::MakeMapSquares(CScene* m_zs)
{
	//TODO Klassenvariable???
	const int xSize = 18;
	const int zSize = 18;
	const int offset = 4;
	const int tileSize = 2;

	MapTile* tiles[xSize] = {};

	for (int iz = 0; iz < zSize; iz++)
	{
		for (int ix = 0; ix < xSize; ix++)
		{
			auto sqr = new MapTile(ix, 0.0, iz, tileSize, &mapSquare);
			m_zs->AddPlacement(sqr);
			mapSquare.Add(sqr);

			//Pathfinding
			Pathfinding::Node* n = sqr->GetNode();
			//Verbinding zur vorherigen Reihe (Verbindung Nord Süd)
			if (iz > 0)
				tiles[ix]->GetNode()->AddTwoWayConnection(n, tileSize);
			//Setzte Element in Reihe neu
			tiles[ix] = sqr;
			//Verbindung vorherige und aktuelle Kachel der Reihe (Verbindung Ost West)
			if (ix - 1 > 0)
				tiles[ix - 1]->GetNode()->AddTwoWayConnection(n, tileSize);

			Pathfinding::NodeController::Instance().AddNode(n);

			// Schalte alle Tiles aus, die nicht im ersten Quadrat enthalten sind
			if ((iz < offset || iz > zSize - offset - 1) || (ix < offset || ix > xSize - offset - 1))
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
