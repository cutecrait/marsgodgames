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
	m_forschung1W.PrintString("Minen upgrades");
	m_forschung1B.Init(cursor, font, CFloatRect(0.8, 0.1, 0.15, 0.8));
	m_forschung1B.SetLayer(0.97);
	m_forschung1B.SetInnerOn();
	m_forschung1B.SetLabel("Press");


	m_forschung2.Init(cursor, font, CFloatRect(0.1, 0.35, 0.8, 0.15));
	m_forschung2.SetLayerGui(0.97);
	m_forschung2.SetInnerOn();
	m_forschung2.SetLabel("Minen upgrades");


	m_mineUpgrade.Init(mat1, CFloatRect(0.1, 0.1,0.8, 0.8));
	m_mineUpgrade.SetLayer(0.9);
	m_mineUpgrade.SetInnerOn();
	m_mineUpgrade.SwitchOff();

	m_mineUpgrade1.Init(mat1, CFloatRect(0, 0, 1, 0.2));
	m_mineUpgrade1.SetLayer(0.88);
	m_mineUpgrade1.SetInnerOn();
	m_mineUpgrade1W.Init(CFloatRect(0.1, 0.1, 0.7, 0.8),15,font);
	m_mineUpgrade1W.SetLayer(0.87);
	m_mineUpgrade1W.SetInnerOn();
	m_mineUpgrade1W.PrintString("MinenUpgrade1");
	m_mineUpgrade1B.Init(cursor, font, CFloatRect(0.85, 0.1, 0.15, 0.8));
	m_mineUpgrade1B.SetLayerGui(0.87);
	m_mineUpgrade1B.SetInnerOn();
	m_mineUpgrade1B.SetLabel("buy");

	m_mineUpgrade2.Init(mat1, CFloatRect(0, 0.2, 1, 0.2));
	m_mineUpgrade2.SetLayer(0.88);
	m_mineUpgrade2.SetInnerOn();
	m_mineUpgrade2W.Init(CFloatRect(0.1, 0.1, 0.7, 0.8), 15, font);
	m_mineUpgrade2W.SetLayer(0.87);
	m_mineUpgrade2W.SetInnerOn();
	m_mineUpgrade2W.PrintString("MinenUpgrade2");
	m_mineUpgrade2B.Init(cursor, font, CFloatRect(0.85, 0.1, 0.15, 0.8));
	m_mineUpgrade2B.SetLayerGui(0.87);
	m_mineUpgrade2B.SetInnerOn();
	m_mineUpgrade2B.SetLabel("buy");

	m_mineUpgrade3.Init(mat1, CFloatRect(0, 0.4, 1, 0.2));
	m_mineUpgrade3.SetLayer(0.88);
	m_mineUpgrade3.SetInnerOn();
	m_mineUpgrade3W.Init(CFloatRect(0.1, 0.1, 0.7, 0.8), 15, font);
	m_mineUpgrade3W.SetLayer(0.87);
	m_mineUpgrade3W.SetInnerOn();
	m_mineUpgrade3W.PrintString("MinenUpgrade3");
	m_mineUpgrade3B.Init(cursor, font, CFloatRect(0.85, 0.1, 0.15, 0.8));
	m_mineUpgrade3B.SetLayerGui(0.87);
	m_mineUpgrade3B.SetInnerOn();
	m_mineUpgrade3B.SetLabel("buy");

	m_buyOverlay.Init(mat1, CFloatRect(0.3, 0.6, 0.4, 0.3));
	m_buyOverlay.SetInnerOn();
	m_buyOverlay.SetLayer(0.7);

	m_confirmB.Init(cursor, font, CFloatRect(0.1, 0.6, 0.35, 0.3));
	m_confirmB.SetLayerGui(0.7);
	m_confirmB.SetInnerOn();
	m_confirmB.SetLabel("confirm");
	m_cancelB.Init(cursor, font, CFloatRect(0.55, 0.6, 0.35, 0.3));
	m_cancelB.SetLayerGui(0.7);
	m_cancelB.SetInnerOn();
	m_cancelB.SetLabel("cancel");

	m_resOverlay.Init(mat2, CFloatRect(0.1,0.3,0.8,0.25));
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
	m_main.AddOverlay(&m_mineUpgrade);
	m_main.AddOverlay(&m_buyOverlay);
	m_main.AddOverlay(&m_abort);

	m_forschung1.AddWriting(&m_forschung1W);
	m_forschung1.AddOverlay(&m_forschung1B);

	m_mineUpgrade.AddOverlay(&m_mineUpgrade1);
	m_mineUpgrade1.AddWriting(&m_mineUpgrade1W);
	m_mineUpgrade1.AddOverlay(&m_mineUpgrade1B);

	m_mineUpgrade.AddOverlay(&m_mineUpgrade2);
	m_mineUpgrade2.AddWriting(&m_mineUpgrade2W);
	m_mineUpgrade2.AddOverlay(&m_mineUpgrade2B);

	m_mineUpgrade.AddOverlay(&m_mineUpgrade3);
	m_mineUpgrade3.AddWriting(&m_mineUpgrade3W);
	m_mineUpgrade3.AddOverlay(&m_mineUpgrade3B);

	m_buyOverlay.AddOverlay(&m_cancelB);
	m_buyOverlay.AddOverlay(&m_confirmB);
	m_buyOverlay.AddOverlay(&m_resOverlay);

	m_resOverlay.AddWriting(&m_concreteW);
	m_resOverlay.AddWriting(&m_steelW);
	m_resOverlay.AddWriting(&m_woodW);
	

	m_headline.AddWriting(&m_headlineW);
}
