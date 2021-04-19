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
	// Hier die Initialisierung Deiner Vektoria-Objekte einf�gen:
	m_zr.Init(psplash);
	//m_zf.SetApiRender(eApiRender_DirectX12);
	m_zf.Init(hwnd, procOS);
	m_zv.InitFull(&m_zc);	//with adresse of camera bcoz viewport
	m_zo.InitFull(&m_zi);
	m_zi.Init("textures\\ENV.jpg");	//double slash
	m_zc.Init(QUARTERPI); //field of view float or variable
	m_zgPlane.Init(10,10, &m_zmPlane, 10, 10);	//world plane

	m_zlp.Init(CHVector(0.2f, -0.2f, -0.8f), CColor(1.0f, 1.0f, 0.0f));	//yellow sun?

	
	//m_zv.AddOverlay(&m_zo);
	

	m_zf.AddDeviceKeyboard(&m_zdk);
	
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
	m_zf.AddDeviceCursor(&einCursor);

	m_zr.AddScene(&m_zs);
	m_zs.AddLightParallel(&m_zlp);
	m_zs.AddPlacement(&m_zpCamera);

	m_zs.AddPlacement(&m_zpPlane);
	m_zpPlane.AddGeo(&m_zgPlane);	

	m_zr.AddFrame(&m_zf);
	m_zf.AddViewport(&m_zv);
	m_zpCamera.AddCamera(&m_zc);
	derManager.InitMenu(&einCursor, &einsFont, allMatsPtr);
	m_zv.AddOverlay(derManager.getStart());
	m_zv.AddOverlay(derManager.getBuildingKind());
	m_zv.AddOverlay(derManager.getSpecfic(0));
	m_zv.AddOverlay(derManager.getSpecfic(1));
	m_zv.AddOverlay(derManager.getSpecfic(2));
	m_zv.AddOverlay(derManager.getSpecfic(3));
	m_zv.AddOverlay(derManager.getSpecfic(4));
	//Cam is looking on the plane in a 45' angle
	m_zpCamera.SetPointing(&m_zpPlane);
	m_zpCamera.TranslateYDelta(20.0f);
	m_zpCamera.RotateXDelta(QUARTERPI);

	m_zmPlane.MakeTextureSprite("textures\\ENV.jpg");



}

void CGame::Tick(float fTime, float fTimeDelta)	//ftime seit spielbeginn
{
	// Hier die Echtzeit-Ver�nderungen einf�gen:
	m_zr.Tick(fTimeDelta);
	//m_zpPlane.RotateX(fTime);
	derManager.Click(fTimeDelta);
	m_zdk.PlaceWASD(m_zpCamera, fTimeDelta);
	

}

//lea END

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einf�gen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergr��e ver�ndert wurde.
	// Hier kannst Du dann die Aufl�sung des Viewports neu einstellen:
}

