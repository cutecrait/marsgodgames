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
#include "LightingManager.h"
#include "CAudioManager.h"
#include "CBuildingManager.h"
#include "Load.h"
#include "UI.h"
#include "Level.h"
#include "Mission.h"

#include "LevelManager.h"


using namespace Vektoria;


class CGame
{
public:
	CGame(void);																				// Wird vor Begin einmal aufgerufen (Konstruktor)
	~CGame(void);																				// Wird nach Ende einmal aufgerufen (Destruktor)

	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash);	// Wird zu Begin einmal aufgerufen
	void Tick(float fTime, float fTimeDelta);													// Wird w�hrend der Laufzeit bei jedem Bildaufbau aufgerufen
	void MakeMapSquares(CScene* m_zs);
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
	LightingManager lightingManager;

	//lea END
	// 
	//hendrik start:
	
	//LevelSystem::LevelManager m_levelManager;
	CDeviceCursor einCursor;
	clickmanager derManager;
	CWritingFont einsFont;
	CMaterial mat1;
	CMaterial mat2;
	CMaterial mat3;
	CPlacement dummyPlace;
	UI menu;
	LevelSystem::Level* m_level1;
	//hendrik end

	// Karo 
	Load m_ldgame;
};



