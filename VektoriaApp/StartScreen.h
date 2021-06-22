#pragma once

#include "Vektoria\root.h"
#include "GuiSelect.h"
#include "Save.h"
#include "UI.h"

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
	CMaterial m_buttmat;

	CGuiButton m_newGame;
	CGuiButton m_loadGame;

	bool clickable;
};

