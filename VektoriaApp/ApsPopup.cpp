#include "ApsPopup.h"
ApsPopup::ApsPopup() {

}
ApsPopup::~ApsPopup() {

}
void ApsPopup::Init(CDeviceCursor* cursor, CMaterial* mat1, CWritingFont* font) {


/*	m_main.Init(mat1, CFloatRect(0.25, 0.2, 0.5, 0.6));
	m_main.SwitchOn();
	m_main.SetLayer(0.99);

	m_headline.Init(mat1, CFloatRect(0, 0, 1, 0.2));
	m_headline.SetLayer(0.98);
	m_headline.SetInnerOn();*/
	init(mat1,cursor,font);
	
	m_headlineW.PrintString("Apartment");

	m_info1.Init(mat1, CFloatRect(0, 0.2, 1, 0.1));
	m_info1.SetLayer(0.98);
	m_info1.SetInnerOn();

	m_info1W.Init(CFloatRect(0.1, 0.1, 0.8, 0.8), 25, font);
	m_info1W.SetLayer(0.97);
	m_info1W.SetInnerOn();
	std::string dummystring;
	dummystring = "Wohnungskapazitaet: " + std::to_string(20);
	m_info1W.PrintString(&dummystring[0]);

	m_infotext.Init(mat1,CFloatRect(0, 0.4, 1, 0.6));
	m_infotext.SetLayer(0.98);
	m_infotext.SetInnerOn();

	m_infotextW.Init(CFloatRect(0.1, 0.1, 0.5, 0.3), 5, font);
	m_infotextW.SetLayer(0.97);
	m_infotextW.SetInnerOn();
	m_infotextW.PrintString("Info:");

	m_infotext1.Init(CFloatRect(0.2, 0.5, 0.7, 0.2), 40, font);
	m_infotext1.SetLayer(0.97);
	m_infotext1.SetInnerOn();
	m_infotext1.PrintString("Wohnungskapazitaet bestimmt wie viele ");

	m_infotext2.Init(CFloatRect(0.2, 0.75, 0.7, 0.2), 40, font);
	m_infotext2.SetLayer(0.97);
	m_infotext2.SetInnerOn();
	m_infotext2.PrintString("Bewohner deine Stadt aufnehmen kann.");


	m_main.SwitchOff();

	m_main.AddOverlay(&m_headline);
	m_main.AddOverlay(&m_info1);
	m_main.AddOverlay(&m_infotext);
	m_main.AddOverlay(&m_abort);

	m_headline.AddWriting(&m_headlineW);
	
	m_info1.AddWriting(&m_info1W);

	m_infotext.AddWriting(&m_infotextW);
	m_infotext.AddWriting(&m_infotext1);
	m_infotext.AddWriting(&m_infotext2);


}