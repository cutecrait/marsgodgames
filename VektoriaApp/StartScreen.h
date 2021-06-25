#pragma once

#include "Vektoria\root.h"
#include "GuiSelect.h"
#include "Save.h"
#include "Load.h"
#include "UI.h"
#include "CAudioManager.h"

class StartScreen
{

public:
	StartScreen();
	~StartScreen();

	
	void InitStartScreen(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv);
	
	void StartNewGame();
	void LoadGame();
	int update();
	void switchStartScreenOff();



	
private:
	COverlay m_startOverlay;
	CImage m_startImage;
	Save s;
	Load l;


	CGuiButton m_newGame;
	CGuiButton m_loadGame;

	bool clickable;
};

