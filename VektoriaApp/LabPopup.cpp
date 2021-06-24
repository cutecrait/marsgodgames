#include "LabPopup.h"

LabPopup::LabPopup()
{
}

LabPopup::~LabPopup()
{
}

void LabPopup::Init(CDeviceCursor* cursor, CMaterial* mat1, CWritingFont* font,CMaterial * mat2)
{
	m_main.Init(mat1, CFloatRect(0.25, 0.2, 0.5, 0.6));
	m_main.SetLayer(0.99);

	m_headline.Init(mat1, CFloatRect(0, 0, 1, 0.2));
	m_headline.SetLayer(0.98);
	m_headline.SetInnerOn();

	m_headlineW.Init(CFloatRect(0.2, 0.2, 0.6, 0.6), 25, font);
	m_headlineW.SetLayer(0.97);
	m_headlineW.SetInnerOn();
	m_headlineW.PrintString("Labor");

	m_abort.Init(cursor, font, CFloatRect(0.85, 0.85, 0.1, 0.1));
	m_abort.SetInnerOn();
	m_abort.SetLayer(0.95);
	m_abort.SetLabel("Close");





	m_forschung1.Init(mat1, CFloatRect(0, 0.2, 1, 0.15));
	m_forschung1.SetLayer(0.98);
	m_forschung1.SetInnerOn();

	m_forschung1W.Init(CFloatRect(0.1, 0.1, 0.65, 0.8), 15, font);
	m_forschung1W.SetLayer(0.97);
	m_forschung1W.SetInnerOn();
	m_forschung1W.PrintString("Minen forschung");
	m_forschung1B.Init(cursor, font, CFloatRect(0.8, 0.1, 0.15, 0.8));
	m_forschung1B.SetLayer(0.97);
	m_forschung1B.SetInnerOn();
	m_forschung1B.SetLabel("Press");


	m_forschung2.Init(mat1, CFloatRect(0, 0.4, 1, 0.15));
	m_forschung2.SetLayer(0.98);
	m_forschung2.SetInnerOn();

	m_forschung2W.Init(CFloatRect(0.1, 0.1, 0.65, 0.8), 22, font);
	m_forschung2W.SetLayer(0.97);
	m_forschung2W.SetInnerOn();
	m_forschung2W.PrintString("GravelPlant forschung");
	m_forschung2B.Init(cursor, font, CFloatRect(0.8, 0.1, 0.15, 0.8));
	m_forschung2B.SetLayer(0.97);
	m_forschung2B.SetInnerOn();
	m_forschung2B.SetLabel("Press");


	m_forschung3.Init(mat1, CFloatRect(0, 0.6, 1, 0.15));
	m_forschung3.SetLayer(0.98);
	m_forschung3.SetInnerOn();

	m_forschung3W.Init(CFloatRect(0.1, 0.1, 0.65, 0.8), 20, font);
	m_forschung3W.SetLayer(0.97);
	m_forschung3W.SetInnerOn();
	m_forschung3W.PrintString("Foundry forschung");
	m_forschung3B.Init(cursor, font, CFloatRect(0.8, 0.1, 0.15, 0.8));
	m_forschung3B.SetLayer(0.97);
	m_forschung3B.SetInnerOn();
	m_forschung3B.SetLabel("Press");


	

	m_buyOverlay.Init(mat1, CFloatRect(0.2, 0.3, 0.6, 0.4));
	m_buyOverlay.SetInnerOn();
	m_buyOverlay.SetLayer(0.7);

	m_confirmB.Init(cursor, font, CFloatRect(0.1, 0.7, 0.25, 0.2));
	m_confirmB.SetLayerGui(0.7);
	m_confirmB.SetInnerOn();
	m_confirmB.SetLabel("confirm");
	m_cancelB.Init(cursor, font, CFloatRect(0.55, 0.7, 0.25, 0.2));
	m_cancelB.SetLayerGui(0.7);
	m_cancelB.SetInnerOn();
	m_cancelB.SetLabel("cancel");

	m_forschungenW1.Init(CFloatRect(0.1, 0.1, 0.8, 0.1), 32, font);
	m_forschungenW1.SetLayer(0.69);
	m_forschungenW1.SetInnerOn();
	m_forschungenW1.PrintString("minen forschung erhoeht");

	m_forschungenW2.Init(CFloatRect(0.1, 0.25, 0.8, 0.1), 23, font);
	m_forschungenW2.SetLayer(0.69);
	m_forschungenW2.SetInnerOn();
	m_forschungenW2.PrintString("sich um 10%");

	m_resOverlay.Init(mat2, CFloatRect(0.1,0.4,0.8,0.25));
	m_resOverlay.SetLayer(0.7);
	m_resOverlay.SetInnerOn();

	m_concreteW.Init(CFloatRect(0.2, 0.1, 0.1, 0.8), 3, font);
	m_concreteW.SetInnerOn();
	m_concreteW.SetLayer(0.69);
	m_steelW.Init(CFloatRect(0.5, 0.1, 0.1, 0.8), 3, font);
	m_steelW.SetInnerOn();
	m_steelW.SetLayer(0.69);
	m_woodW.Init(CFloatRect(0.8, 0.1, 0.1, 0.8), 3, font);
	m_woodW.SetInnerOn();
	m_woodW.SetLayer(0.69);

	m_woodW.PrintInt(10);
	m_steelW.PrintInt(10);
	m_concreteW.PrintInt(10);



	m_buyOverlay.SwitchOff();
	m_main.SwitchOff();
	m_main.AddOverlay(&m_headline);
	m_main.AddOverlay(&m_forschung1);
	m_main.AddOverlay(&m_forschung2);
	m_main.AddOverlay(&m_forschung3);

	m_main.AddOverlay(&m_buyOverlay);
	m_main.AddOverlay(&m_abort);

	m_forschung1.AddWriting(&m_forschung1W);
	m_forschung1.AddOverlay(&m_forschung1B);

	m_forschung2.AddWriting(&m_forschung2W);
	m_forschung2.AddOverlay(&m_forschung2B);
	
	m_forschung3.AddWriting(&m_forschung3W);
	m_forschung3.AddOverlay(&m_forschung3B);

	m_buyOverlay.AddOverlay(&m_cancelB);
	m_buyOverlay.AddOverlay(&m_confirmB);
	m_buyOverlay.AddOverlay(&m_resOverlay);
	m_buyOverlay.AddWriting(&m_forschungenW1);
	m_buyOverlay.AddWriting(&m_forschungenW2);

	m_resOverlay.AddWriting(&m_concreteW);
	m_resOverlay.AddWriting(&m_steelW);
	m_resOverlay.AddWriting(&m_woodW);
	

	m_headline.AddWriting(&m_headlineW);
}

void LabPopup::deaktivate()
{
	m_forschung1.SwitchOff();
	m_forschung2.SwitchOff();
	m_forschung3.SwitchOff();
}

void LabPopup::activate()
{

	m_forschung1.SwitchOn();
	m_forschung2.SwitchOn();
	m_forschung3.SwitchOn();
}

void LabPopup::buyOverlay(int i)
{
	if (i == 1) {
		m_forschungenW1.PrintString("Forschung erhoeht die Effizienz");
		m_forschungenW2.PrintString("der Mine um 10%");
	}
	else if (i == 2) {
		m_forschungenW1.PrintString("Forschung erhoeht die Effizienz");
		m_forschungenW2.PrintString("der GravelPlant um 10%");
	}
	else if (i == 3) {
		m_forschungenW1.PrintString("Forschung erhoeht die Effizienz");
		m_forschungenW2.PrintString("der Foundry um 10%");
	}
}
