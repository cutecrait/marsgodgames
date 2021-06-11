#pragma once
#include "GuiButton.h"
class popup
{
public:
	popup() {}
	~popup() {}
	virtual void buttonpress(){}
	void init(CMaterial*,CDeviceCursor*,CWritingFont*);
	COverlay m_main;
	COverlay m_headline;
	CWriting m_headlineW;

	CGuiButton m_abort;
};

