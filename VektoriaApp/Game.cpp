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
	m_zpCamera.RotateYDelta(PI);
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


	// LIGHTING--------------------------------------
	m_zlp.Init(CHVector(0.2f, 0.8f, 0.2f), CColor(1.0f, 1.0f, 0));	//yellow sun?
	m_zs.AddLightParallel(&m_zlp);


	// OVERLAY-----------------------------------------
	mat1.MakeTextureSprite("textures\\ENV.jpg");
	mat2.MakeTextureSprite("textures\\Des.jpg");
	mat3.MakeTextureSprite("textures\\red_image.jpg");
	//der allMatsPtr muss noch bestückt werden hier erstmal nur 3 materials für insgesamt 27 buttons:
	for (int i = 0; i < 9; i++) {
		allMatsPtr.push_back(&mat1);
		allMatsPtr.push_back(&mat2);
		allMatsPtr.push_back(&mat3);
	}
	einsFont.LoadPreset("LucidaConsoleBlack");
	einsFont.SetChromaKeyingOn(); //hiermit hat die font keinen hässlichen hintergrund

	derManager.InitMenu(&einCursor, &einsFont, allMatsPtr);
	m_zv.AddOverlay(derManager.getStart());
	m_zv.AddOverlay(derManager.getBuildingKind());
	m_zv.AddOverlay(derManager.getSpecfic(0));
	m_zv.AddOverlay(derManager.getSpecfic(1));
	m_zv.AddOverlay(derManager.getSpecfic(2));
	m_zv.AddOverlay(derManager.getSpecfic(3));
	m_zv.AddOverlay(derManager.getSpecfic(4));
	

	// MAP SQUARES---------------------------------------
	for (int iz = 0; iz < 10; iz++)
	{
		for (int ix = 0; ix < 10; ix++)
		{
			auto sqr = new MapSquare(ix, 0.0, iz, 2);
			m_zs.AddPlacement(sqr);
			squares.Add(sqr);
		}
	}

}

void CGame::Tick(float fTime, float fTimeDelta)	//ftime seit spielbeginn
{
	m_zr.Tick(fTimeDelta);

	// CAMERA-----------------------------------
	CameraController.UpdateCameraMovement(fTimeDelta); //Aktualisiert die Kamerabewegung

	// MAP SQUARES---------------------------------------
	// deselect other map squares
	for (int i = 0; i<squares.m_iPlacements; i++)
	{
		auto sqr = static_cast<MapSquare*>(squares.m_applacement[i]);
		if(sqr)
			sqr->Deselect();
	}
	//int mouseX, mouseY;
	//einCursor.GetAbsolute(mouseX, mouseY);
	auto selectedPlace = einCursor.PickPlacement();
	if (selectedPlace)
		selectedPlace->m_pgeos->m_apgeo[0]->m_pmaterial->Translate(CColor(0.2, 0.8, 0.2));

	
	// UI-----------------------------------
	derManager.Click(fTimeDelta);
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

