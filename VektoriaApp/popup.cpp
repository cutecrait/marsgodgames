#include "popup.h"

void popup::init(CMaterial * mat1,CDeviceCursor* cursor, CWritingFont* font)
{
	m_main.Init(mat1, CFloatRect(0.25, 0.2, 0.5, 0.6));
	m_main.SwitchOn();
	m_main.SetLayer(0.99);

	m_headline.Init(mat1, CFloatRect(0, 0, 1, 0.2));
	m_headline.SetLayer(0.98);
	m_headline.SetInnerOn();

	m_headlineW.Init(CFloatRect(0.2, 0.2, 0.6, 0.6), 25, font);
	m_headlineW.SetLayer(0.97);
	m_headlineW.SetInnerOn();


	m_info2.Init(mat1, CFloatRect(0, 0.3, 1, 0.1));
	m_info2.SetLayer(0.98);
	m_info2.SetInnerOn();
	m_info2W.Init(CFloatRect(0.1, 0.1, 0.8, 0.8),30,font);
	m_info2W.SetLayer(0.97);
	m_info2W.SetInnerOn();
	

	m_info3.Init(mat1, CFloatRect(0, 0.4, 1, 0.1));
	m_info3.SetLayer(0.98);
	m_info3.SetInnerOn();
	m_info3W.Init(CFloatRect(0.1, 0.1, 0.8, 0.8), 30, font);
	m_info3W.SetLayer(0.97);
	m_info3W.SetInnerOn();


	m_info4.Init(mat1, CFloatRect(0, 0.5, 1, 0.1));
	m_info4.SetLayer(0.98);
	m_info4.SetInnerOn();
	m_info4W.Init(CFloatRect(0.1, 0.1, 0.8, 0.8), 30, font);
	m_info4W.SetLayer(0.97);
	m_info4W.SetInnerOn();


	m_main.AddOverlay(&m_headline);
	m_headline.AddWriting(&m_headlineW);

	m_abort.Init(cursor, font, CFloatRect(0.85, 0.85, 0.1, 0.1));
	m_abort.SetInnerOn();
	m_abort.SetLayer(0.95);
	m_abort.SetLabel("Close");


	
}
