#pragma once
#include "Vektoria\root.h"
#include "GuiSelect.h"
#include "GuiButton.h" 
#include "popup.h"
using namespace Vektoria;
class roboPopUp : public popup
{
public:
	roboPopUp();
	~roboPopUp();
	void Init(CDeviceCursor* cursor,CMaterial*,CWritingFont*);
	void buttonpress()override;
	

private:
	
	COverlay m_robo1; //hintergrund für robos
	COverlay m_robo2;
	COverlay m_robo3;
	CWriting m_robo1W; //roboter beschreibung
	CWriting m_robo2W;
	CWriting m_robo3W;
//	COverlay m_headLine;
	//CWriting m_headlineW;

	COverlay kosten;
	COverlay kosten1;
	COverlay kosten2;
	COverlay kosten3;
	
	COverlay buttonOverlay;
public:
	
	
	//COverlay m_main;
	CGuiButton m_robo1Add;// zählt robo1addw hoch 
	CWriting m_robo1AddW;//wie viele robo
	CWriting m_robo2AddW;
	CWriting m_robo3AddW;
	CGuiButton m_robo1b;
	CGuiButton m_robo2Add;
	CGuiButton m_robo3Add;
	CWriting kosten1W;
	CWriting kosten2W;
	CWriting kosten3W;
	CGuiButton confirm;
	CGuiButton cancel;

};

