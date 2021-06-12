#pragma once
#include "GuiButton.h"
#include "Player.h"
class popup
{
public:
	popup() {}
	~popup() {}
	virtual void buttonpress(){}
	virtual void setInfo(int powerUse,int waterUse,int NutrientUse,int howMuch){}
	void init(CMaterial*,CDeviceCursor*,CWritingFont*);
	COverlay m_main;
	COverlay m_headline;
	CWriting m_headlineW;

	CGuiButton m_abort;

	COverlay m_info2;
	CWriting m_info2W;
	COverlay m_info3;
	CWriting m_info3W;
	COverlay m_info4;
	CWriting m_info4W;

};

