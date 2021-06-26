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
	m_startImage.Init("textures\\MarsStartScreen.png");
	m_startOverlay.SetLayer(0.1f);
	
	
	m_loadGame.Init(cursor, font, CFloatRect(0.15f, 0.25f, 0.2, 0.1));
	m_loadGame.SetLayerGui(0.08f);
	m_loadGame.SetLabel("Load Game");
	
	m_newGame.Init(cursor, font, CFloatRect(0.15f, 0.45f, 0.2, 0.1));
	m_newGame.SetLayerGui(0.08f);
	m_newGame.SetLabel("New Game");

	m_exitGame.Init(cursor, font, CFloatRect(0.15f, 0.65f, 0.2, 0.1));
	m_exitGame.SetLayerGui(0.08f);
	m_exitGame.SetLabel("Exit Game");

	
	zv->AddOverlay(&m_startOverlay);
	zv->AddOverlay(&m_newGame);
	zv->AddOverlay(&m_loadGame);
	zv->AddOverlay(&m_exitGame);

	clickable = true;
}

void StartScreen::StartNewGame()
{
	s.ResetGame();
	l.loadPlayerDetails();
	l.AddBuilding();
	switchStartScreenOff();
}

void StartScreen::LoadGame()
{
	l.loadPlayerDetails();
	l.AddBuilding();
	switchStartScreenOff();
}

void StartScreen::ExitGame()
{
}

int StartScreen::update()
{
	int retval = -1;
	if (m_newGame.IsClicked() && clickable) {
		retval = 1;
		StartNewGame();
		clickable = false;
		return retval;
	}
	else if (m_loadGame.IsClicked() && clickable) {
		retval = 1;
		LoadGame();
		ULDebug("load game");

		clickable = false;
		return retval;
	}
	else if (m_exitGame.IsClicked() && clickable) {
		retval = 2;
		LoadGame();
		ULDebug("exit game");
		
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
	m_exitGame.SwitchOff();

	CAudioManager::Instance().Ambient_Title_Music.Stop();
	CAudioManager::Instance().Ambient_Background_Music.Loop();

}


