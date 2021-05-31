#include "roboPopUp.h"

roboPopUp::roboPopUp()
{
}

roboPopUp::~roboPopUp()
{
}


void roboPopUp::Init(CDeviceCursor* cursor, CWritingFont* font1, CMaterial* mat1 )
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
	m_robo1W.Init(CFloatRect(0.1, 0.1, 0.45, 0.8), 20, font1); //0.45 kann man größer machen dementscprechend bei robo1addw und robo1add den ersten wert erhöhen
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
	m_robo1Add.SetLayer(0.88);
	m_robo1Add.SetInnerOn();

	//next robo 0.4y , 0.2y hoch
	//robo3 0.6y, 0.2y hoch 
	//0.8 , 0.15 y hoch für total kosten

	this->SwitchOff();



	this->AddOverlay(&m_main);
	m_main.AddOverlay(&m_robo1);
	m_robo1.AddWriting(&m_robo1W);
	m_robo1.AddWriting(&m_robo1AddW);
	m_robo1.AddOverlay(&m_robo1Add);

}
