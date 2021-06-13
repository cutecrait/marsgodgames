#include "NuclearPopup.h"



NuclearPopup::NuclearPopup()
{
}

NuclearPopup::~NuclearPopup()
{
}

void NuclearPopup::Init(CDeviceCursor* cursor, CMaterial* mat1, CWritingFont*font)
{
	init(mat1, cursor, font);

	m_headlineW.PrintString("Atomkraftwerk");

	m_info1.Init(mat1, CFloatRect(0, 0.2, 1, 0.1));
	m_info1.SetLayer(0.98);
	m_info1.SetInnerOn();

	m_info1W.Init(CFloatRect(0.1, 0.1, 0.8, 0.8), 30, font);
	m_info1W.SetLayer(0.97);
	m_info1W.SetInnerOn();
	std::string dummystring;
	dummystring = "Stromherstellung: " + std::to_string(10);
	m_info1W.PrintString(&dummystring[0]);


	m_infotext.Init(mat1, CFloatRect(0, 0.6, 1, 0.4));
	m_infotext.SetLayer(0.98);
	m_infotext.SetInnerOn();

	m_infotextW.Init(CFloatRect(0.1, 0.1, 0.5, 0.3), 5, font);
	m_infotextW.SetLayer(0.97);
	m_infotextW.SetInnerOn();
	m_infotextW.PrintString("Info:");

	m_infotext1.Init(CFloatRect(0.1, 0.5, 0.7, 0.2), 50, font);
	m_infotext1.SetLayer(0.97);
	m_infotext1.SetInnerOn();
	m_infotext1.PrintString("Strom pro Stunde bestimmt wie viel KW pro Stunde");

	m_infotext2.Init(CFloatRect(0.1, 0.75, 0.7, 0.2), 50, font);
	m_infotext2.SetLayer(0.97);
	m_infotext2.SetInnerOn();
	m_infotext2.PrintString("hergestellt wird, Gebaeude brauchen Strom.");


	m_main.SwitchOff();

	m_main.AddOverlay(&m_headline);
	m_main.AddOverlay(&m_info1);
	m_main.AddOverlay(&m_infotext);
	m_main.AddOverlay(&m_abort);
	m_main.AddOverlay(&m_info2);
	m_main.AddOverlay(&m_info3);
	m_main.AddOverlay(&m_info4);

	m_headline.AddWriting(&m_headlineW);

	m_info1.AddWriting(&m_info1W);
	m_info2.AddWriting(&m_info2W);
	m_info3.AddWriting(&m_info3W);
	m_info4.AddWriting(&m_info4W);

	m_infotext.AddWriting(&m_infotextW);
	m_infotext.AddWriting(&m_infotext1);
	m_infotext.AddWriting(&m_infotext2);
}

void NuclearPopup::setInfo(int powerUse, int waterUse, int NutrientUse, int howMuch)
{
	std::string dumyString;
	dumyString = "Stromherstellung: " + std::to_string(howMuch);
	m_info1W.PrintString(&dumyString[0]);

	dumyString = "Stromverbrauch: " + std::to_string(powerUse);
	m_info2W.PrintString(&dumyString[0]);

	dumyString = "Wasserverbrauch: " + std::to_string(waterUse);
	m_info3W.PrintString(&dumyString[0]);

	dumyString = "Nahrungsverbrauch: " + std::to_string(NutrientUse);
	m_info4W.PrintString(&dumyString[0]);
}
