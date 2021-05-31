#pragma once
#include "GuiSelect.h"
#include "GuiButton.h"
using namespace Vektoria;
class roboPopUp : public COverlay
{
public:
	roboPopUp();
	~roboPopUp();
	void Init(CDeviceCursor* cursor, CWritingFont* font1, CMaterial* mat1);
	
	CGuiButton m_robo1Add;// zählt robo1addw hoch 

private:
	COverlay m_main;
	COverlay m_robo1; //hintergrund für robos
	COverlay m_robo2;
	COverlay m_robo3;
	CWriting m_robo1W; //roboter beschreibung
	CWriting m_robo2W;
	CWriting m_robo3W;
	CGuiButton m_robo1b;
	
	CWriting m_robo1AddW; //wie viele robo

};

