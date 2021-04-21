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
	m_zf.SetApiRender(eApiRender_DirectX12);
	m_zf.Init(hwnd, procOS);
	m_zv.InitFull(&m_zc);	//with adresse of camera bcoz viewport
	m_zo.InitFull(&m_zi);
	m_zi.Init("textures//ENV.jpg");	//double slash
	m_zc.Init(QUARTERPI); //field of view float or variable
	//m_zgPlane.Init(10,10, &m_zmPlane, 10, 10);	//world plane
	

	m_zlp.Init(CHVector(0.2f, -0.8f, -0.2f), CColor(1.0f, 1.0f, 0.0f));	//yellow sun?

	m_zr.AddFrame(&m_zf);
	m_zf.AddViewport(&m_zv);
	//m_zv.AddOverlay(&m_zo);

	m_zf.AddDeviceKeyboard(&m_zdk);
	m_zf.AddDeviceCursor(&m_zdc);

	m_zr.AddScene(&m_zs);
	m_zs.AddLightParallel(&m_zlp);
	m_zs.AddPlacement(&m_zpCamera);
	
	// squares = new vector<MapSquare>();
	for (int iz = 0; iz < 10; iz++)
	{
		for (int ix = 0; ix < 10; ix++)
		{
			auto sqr = new MapSquare(ix, 0.0, iz, 2);
			m_zs.AddPlacement(sqr);
			squares.push_back(sqr);
		}
	}

	m_zs.AddPlacement(&m_zpPlane);
	//m_zpPlane.AddGeo(&m_zgPlane);

	m_zpCamera.AddCamera(&m_zc);

	//Cam is looking on the plane in a 45' angle
	m_zpCamera.Translate(10, 10, 10);
	//m_zpCamera.SetPointing(&CHVector(0, 0, 0));
	m_zpCamera.SetPointing(squares.front());

	m_zmPlane.MakeTextureDiffuse("textures//ENV.jpg");
}

void CGame::Tick(float fTime, float fTimeDelta)	//ftime seit spielbeginn
{
	// Hier die Echtzeit-Ver�nderungen einf�gen:
	m_zr.Tick(fTimeDelta);
	//m_zpPlane.RotateX(fTime);
	auto faster = fTimeDelta * 4;
	m_zdk.PlaceWASD(m_zpCamera, faster, true);


	// deselect others
	for (auto const square : squares)
	{
		square->Deselect();
	}

	// raytest
	int mouseX, mouseY;
	m_zdc.GetAbsolute(mouseX, mouseY);
	auto selectedPlace = m_zdc.PickPlacement();
	if(selectedPlace)
		selectedPlace->m_pgeos->m_apgeo[0]->m_pmaterial->Translate(CColor(0.2, 1.0, 0.2));
}

//lea END

void CGame::Fini()
{
	
	// Hier die Finalisierung Deiner Vektoria-Objekte einf�gen
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergr��e ver�ndert wurde.
	// Hier kannst Du dann die Aufl�sung des Viewports neu einstellen:
}

