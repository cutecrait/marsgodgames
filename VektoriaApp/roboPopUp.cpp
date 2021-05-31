#include "roboPopUp.h"

roboPopUp::roboPopUp()
{
	
}

roboPopUp::~roboPopUp()
{
}


void roboPopUp::Init(CDeviceCursor* cursor,CMaterial* mat1, CWritingFont* font1)
{
	//hintergrund für alle robos
	m_main.Init(mat1, CFloatRect(0.25,0.2,0.5,0.6));
	m_main.SwitchOn();
	m_main.SetLayer(0.99);
	//writing (welcher robo) writing (wie viele) button der 2tes writing hochzählt.
	//hintergrund für robo1
	m_robo1.Init(mat1,CFloatRect(0,0.2,1,0.2)); 
	m_robo1.SetLayer(0.89);
	m_robo1.SetInnerOn();
	//welcher robo
	m_robo1W.Init(CFloatRect(0.1, 0.1, 0.45, 0.8), 25, font1); //0.45 kann man größer machen dementscprechend bei robo1addw und robo1add den ersten wert erhöhen
	m_robo1W.PrintString("Bauroboter kaufen: ");
	m_robo1W.SetInnerOn();
	m_robo1W.SwitchOn();
	m_robo1W.SetLayer(0.88);
	//wie viele robos
	m_robo1AddW.Init(CFloatRect(0.6, 0.1, 0.1, 0.8), 2, font1);
	m_robo1AddW.PrintInt(0);
	m_robo1AddW.SetInnerOn();
	m_robo1AddW.SetLayer(0.88);
	//button der robo1addw hochzählt
	m_robo1Add.Init(cursor, font1, CFloatRect(0.75, 0.1, 0.2, 0.8));
	m_robo1Add.SetLabel("+");
//	m_robo1Add.SetMaterialNormal(); sieht noch kacke aus -> ändert default mat 
	//m_robo1Add.SetMaterialClick(); // -> ändert click mat.
	m_robo1Add.SetLayer(0.8);
	m_robo1Add.SetInnerOn();

	//next robo 0.4y , 0.2y hoch
	//robo3 0.6y, 0.2y hoch 
	//0.8 , 0.15 y hoch für total kosten
	m_robo2.Init(mat1, CFloatRect(0, 0.4, 1, 0.2));
	m_robo2.SetLayer(0.89);
	m_robo2.SetInnerOn();

	m_robo2W.Init(CFloatRect(0.1, 0.1, 0.45, 0.8), 25, font1);
	m_robo2W.PrintString("Landwirtroboter kaufen: ");
	m_robo2W.SetInnerOn();
	m_robo2W.SwitchOn();
	m_robo2W.SetLayer(0.88);
	//wie viele robos
	m_robo2AddW.Init(CFloatRect(0.6, 0.1, 0.1, 0.8), 2, font1);
	m_robo2AddW.PrintInt(0);
	m_robo2AddW.SetInnerOn();
	m_robo2AddW.SetLayer(0.88);
	//button der robo1addw hochzählt
	m_robo2Add.Init(cursor, font1, CFloatRect(0.75, 0.1, 0.2, 0.8));
	m_robo2Add.SetLabel("+");
	//	m_robo1Add.SetMaterialNormal(); sieht noch kacke aus -> ändert default mat 
		//m_robo1Add.SetMaterialClick(); // -> ändert click mat.
	m_robo2Add.SetLayer(0.8);
	m_robo2Add.SetInnerOn();


	m_robo3.Init(mat1, CFloatRect(0, 0.6, 1, 0.2));
	m_robo3.SetLayer(0.89);
	m_robo3.SetInnerOn();

	m_robo3W.Init(CFloatRect(0.1, 0.1, 0.45, 0.8), 25, font1);
	m_robo3W.PrintString("andere Roboter kaufen: ");
	m_robo3W.SetInnerOn();
	m_robo3W.SwitchOn();
	m_robo3W.SetLayer(0.88);
	//wie viele robos
	m_robo3AddW.Init(CFloatRect(0.6, 0.1, 0.1, 0.8), 2, font1);
	m_robo3AddW.PrintInt(0);
	m_robo3AddW.SetInnerOn();
	m_robo3AddW.SetLayer(0.88);
	//button der robo1addw hochzählt
	m_robo3Add.Init(cursor, font1, CFloatRect(0.75, 0.1, 0.2, 0.8));
	m_robo3Add.SetLabel("+");
	//	m_robo1Add.SetMaterialNormal(); sieht noch kacke aus -> ändert default mat 
		//m_robo1Add.SetMaterialClick(); // -> ändert click mat.
	m_robo3Add.SetLayer(0.8);
	m_robo3Add.SetInnerOn();

	kosten.Init(mat1,CFloatRect(0,0.8,1,0.2));
	kosten.SetLayer(0.89);
	kosten.SetInnerOn();
	
	kosten1.Init(mat1, CFloatRect(0.1, 0.2, 0.15, 0.6));
	kosten1.SetLayer(0.88);
	kosten1.SetInnerOn();

	kosten1W.Init(CFloatRect(0, 0, 1, 1), 4, font1);
	kosten1W.SetInnerOn();
	kosten1W.SetLayer(0.87);
	kosten1W.PrintInt(0);


	kosten2.Init(mat1, CFloatRect(0.25, 0.2, 0.15, 0.6));
	kosten2.SetLayer(0.88);
	kosten2.SetInnerOn();

	kosten2W.Init(CFloatRect(0, 0, 1, 1), 4, font1);
	kosten2W.SetInnerOn();
	kosten2W.SetLayer(0.87);
	kosten2W.PrintInt(0);


	kosten3.Init(mat1, CFloatRect(0.4, 0.2, 0.15, 0.6));
	kosten3.SetLayer(0.88);
	kosten3.SetInnerOn();

	kosten3W.Init(CFloatRect(0, 0, 1, 1), 4, font1);
	kosten3W.SetInnerOn();
	kosten3W.SetLayer(0.87);
	kosten3W.PrintInt(0);

	confirm.Init(cursor, font1,CFloatRect(0.6, 0.8, 0.2, 0.2));
	confirm.SetInnerOn();
	confirm.SetLayer(0.87);
	confirm.SetLabel("confirm");

	cancel.Init(cursor, font1, CFloatRect(0.8, 0.8, 0.2, 0.2));
	cancel.SetInnerOn();
	cancel.SetLayer(0.87);
	cancel.SetLabel("cancel");

	m_main.SwitchOff();

	
	m_main.AddOverlay(&m_robo1);
	m_main.AddOverlay(&m_robo2);
	m_main.AddOverlay(&m_robo3);
	m_main.AddOverlay(&kosten);
	m_main.AddOverlay(&confirm);
	m_main.AddOverlay(&cancel);


	m_robo1.AddWriting(&m_robo1W);
	m_robo1.AddWriting(&m_robo1AddW);
	m_robo1.AddOverlay(&m_robo1Add);

	m_robo2.AddWriting(&m_robo2W);
	m_robo2.AddWriting(&m_robo2AddW);
	m_robo2.AddOverlay(&m_robo2Add);

	m_robo3.AddWriting(&m_robo3W);
	m_robo3.AddWriting(&m_robo3AddW);
	m_robo3.AddOverlay(&m_robo3Add);

	kosten.AddOverlay(&kosten1);
	kosten.AddOverlay(&kosten2);
	kosten.AddOverlay(&kosten3);
	
	kosten1.AddWriting(&kosten1W);
	kosten2.AddWriting(&kosten2W);
	kosten3.AddWriting(&kosten3W);
	
}

void roboPopUp::buttonpress()
{
	if (m_robo1Add.IsClicked()) {
		m_main.SwitchOff();
	}
}
