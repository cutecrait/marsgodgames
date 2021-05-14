#pragma once


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#endif
#endif


#include "Vektoria\Root.h"
#include "MapTile.h"
#include "CCameraController.h"
#include "clickmanager.h"
#include "CAudioManager.h"
#include "CBuildingManager.h"
#include "Load.h"
#include "UI.h"

using namespace Vektoria;


class CGame
{
public:
	CGame(void);																				// Wird vor Begin einmal aufgerufen (Konstruktor)
	~CGame(void);																				// Wird nach Ende einmal aufgerufen (Destruktor)

	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash);	// Wird zu Begin einmal aufgerufen
	void Tick(float fTime, float fTimeDelta);													// Wird w�hrend der Laufzeit bei jedem Bildaufbau aufgerufen
	void Fini();																				// Wird am Ende einmal aufgerufen

	void WindowReSize(int iNewWidth, int iNewHeight);											// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergr��e ver�ndert hat

private:
    // Hier ist Platz f�r Deine Vektoriaobjekte:

	//lea START
	CRoot m_zr;
	CFrame m_zf;
	CViewport m_zv;
	COverlay m_zo;	//ui
	CScene m_zs;	
	CCamera m_zc;
	CPlacement m_zpCamera;	
	CImage m_zi;
	CDeviceKeyboard m_zdk;
	CDeviceMouse m_zdm;

	//<Darius>
	CCameraController CameraController;
	CAudioManager AudioManager;
	CBuildingManager BuildingManager;
	//</Darius>

	//World Ground
	MapSquare mapSquare;

	//Sun?
	CLightParallel m_zlp;
	//lea END
	// 
	//hendrik start:
	
	CDeviceCursor einCursor;
	clickmanager derManager;
	CWritingFont einsFont;
	CMaterial mat1;
	CMaterial mat2;
	CMaterial mat3;
	CPlacement dummyPlace;
	UI menu;
	Player m_player;
	//hendrik end

	// Karo 
	Load m_ldgame;
};



