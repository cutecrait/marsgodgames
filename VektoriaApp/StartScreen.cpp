#include "StartScreen.h"

StartScreen::StartScreen()
{
}

StartScreen::~StartScreen()
{
}

void StartScreen::InitStartScreen(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv)
{
	m_startOverlay.InitFull(&m_startImage);
	m_startImage.Init("textures\\StartScreen.png");
	m_startOverlay.SetLayer(0.1f);
	//m_buttmat.Init();
	m_buttmat.MakeTextureSprite("textures\\ENV.jpg");
	//m_proot->AddMaterial(&m_buttmat);
	
	
	
	
	m_newGame.Init(cursor, font, CFloatRect(0.6f, 0.8f, 0.2, 0.1));
	m_newGame.SetLayerGui(0.08f);
	m_newGame.SetLabel("New Game");
	
	m_loadGame.Init(cursor, font, CFloatRect(0.2f, 0.8f, 0.2, 0.1));
	m_loadGame.SetLayerGui(0.08f);
	m_loadGame.SetLabel("Load Game");

	//m_newGame->SetMaterial(&m_buttmat);
	// 
	zv->AddOverlay(&m_startOverlay);
	zv->AddOverlay(&m_newGame);
	zv->AddOverlay(&m_loadGame);

	clickable = true;
}

void StartScreen::StartNewGame()
{
	
}

void StartScreen::LoadGame()
{
}

int StartScreen::update()
{
	int retval = -1;
	if (m_newGame.IsClicked() && clickable) {
		retval = 1;
		StartNewGame();
		switchStartScreenOff();
		s.ResetGame();
		clickable = false;
		return retval;
	}
	else if (m_loadGame.IsClicked() && clickable) {
		retval = 0;
		LoadGame();
		ULDebug("load game");
		switchStartScreenOff();
		clickable = false;
		return retval;
	}
	else {
		return retval;
	}
}

void StartScreen::switchStartScreenOff()
{
	m_startImage.SwitchOff();
	m_startOverlay.SwitchOff();
	m_newGame.SwitchOff();
	m_loadGame.SwitchOff();
}


