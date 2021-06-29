#include "ControlCPopup.h"

ControlCPopup::ControlCPopup()
{
}

ControlCPopup::~ControlCPopup()
{
}

void ControlCPopup::Init(CDeviceCursor* cursor, CMaterial* mat1, CWritingFont* font1,CWritingFont* redFont)
{
	init(mat1,cursor, font1);
	m_redFont = redFont;
	//font = font1;
	
	m_headlineW.PrintString("ControlCenter");

	m_wohnungen.Init(mat1, CFloatRect(0, 0.2, 1, 0.15));
	m_wohnungen.SetInnerOn();
	m_wohnungen.SetLayer(0.98);
	
	
	m_wohnungenW.Init(cursor, font1, CFloatRect(0.05, 0.1, 0.4, 0.8),22);
	m_wohnungenW.SetInnerOn();
	m_wohnungenW.SetLayer(0.97);
	m_wohnungenW.SetLabel("Wohnungen insgesamt: ");

	m_wohnungenInsgesamt.Init(CFloatRect(0.47, 0.1, 0.3, 0.8), 10,font1);
	m_wohnungenInsgesamt.SetInnerOn();
	m_wohnungenInsgesamt.SetLayer(0.97);
	m_wohnungenInsgesamt.PrintInt(200);
	
	/*m_usedWohnungen.Init(CFloatRect(0.6, 0.1, 0.3, 0.8), 23, font1);
	m_usedWohnungen.SetInnerOn();
	m_usedWohnungen.SetLayer(0.97);
	m_usedWohnungen.PrintString(" Davon werden benutzt: ");

	m_usedWohnungenInt.Init(CFloatRect(0.9, 0.1, 0.1, 0.8), 4, font1);
	m_usedWohnungenInt.SetInnerOn();
	m_usedWohnungenInt.SetLayer(0.97);
	m_usedWohnungenInt.PrintInt(100);*/





	m_strom.Init(mat1, CFloatRect(0, 0.35, 1, 0.15));
	m_strom.SetInnerOn();
	m_strom.SetLayer(0.98);

	m_StromW.Init(cursor, font1, CFloatRect(0.05, 0.1, 0.4, 0.8),22);
	m_StromW.SetInnerOn();
	m_StromW.SetLayer(0.97);
	m_StromW.SetLabel("Strom zurverfuegung: ");

	m_stromInsgesamt.Init(CFloatRect(0.47, 0.1, 0.3, 0.8), 10, font1);
	m_stromInsgesamt.SetInnerOn();
	m_stromInsgesamt.SetLayer(0.97);
	m_stromInsgesamt.PrintInt(200);

/*	m_usedStrom.Init(CFloatRect(0.6, 0.1, 0.3, 0.8), 23, font1);
	m_usedStrom.SetInnerOn();
	m_usedStrom.SetLayer(0.97);
	m_usedStrom.PrintString(" Davon werden benutzt: ");

	m_usedStromInt.Init(CFloatRect(0.9, 0.1, 0.1, 0.8), 4, font1);
	m_usedStromInt.SetInnerOn();
	m_usedStromInt.SetLayer(0.97);
	m_usedStromInt.PrintInt(100);*/



	m_wasser.Init(mat1, CFloatRect(0, 0.5, 1, 0.15));
	m_wasser.SetInnerOn();
	m_wasser.SetLayer(0.98);

	m_wasserW.Init(cursor, font1, CFloatRect(0.05, 0.1, 0.4, 0.8),22);
	m_wasserW.SetInnerOn();
	m_wasserW.SetLayer(0.97);
	m_wasserW.SetLabel("Wasser zurverfuegung: ");

	m_wasserInsgesamt.Init(CFloatRect(0.47, 0.1, 0.3, 0.8), 10, font1);
	m_wasserInsgesamt.SetInnerOn();
	m_wasserInsgesamt.SetLayer(0.97);
	m_wasserInsgesamt.PrintInt(200);

	/*m_usedWasser.Init(CFloatRect(0.6, 0.1, 0.3, 0.8), 23, font1);
	m_usedWasser.SetInnerOn();
	m_usedWasser.SetLayer(0.97);
	m_usedWasser.PrintString(" Davon werden benutzt: ");

	m_usedWasserInt.Init(CFloatRect(0.9, 0.1, 0.1, 0.8), 4, font1);
	m_usedWasserInt.SetInnerOn();
	m_usedWasserInt.SetLayer(0.97);
	m_usedWasserInt.PrintInt(100);*/



	m_food.Init(mat1, CFloatRect(0, 0.65, 1, 0.15));
	m_food.SetInnerOn();
	m_food.SetLayer(0.98);

	m_foodW.Init(cursor, font1, CFloatRect(0.05, 0.1, 0.4, 0.8), 25);
	m_foodW.SetInnerOn();
	m_foodW.SetLayer(0.97);
	m_foodW.SetLabel("Nahrung zurverfuegung: ");

	m_foodInsgesamt.Init(CFloatRect(0.47, 0.1, 0.3, 0.8), 10, font1);
	m_foodInsgesamt.SetInnerOn();
	m_foodInsgesamt.SetLayer(0.97);
	m_foodInsgesamt.PrintInt(200);

	/*m_usedFood.Init(CFloatRect(0.6, 0.1, 0.3, 0.8), 23, font1);
	m_usedFood.SetInnerOn();
	m_usedFood.SetLayer(0.97);
	m_usedFood.PrintString(" Davon werden benutzt: ");

	m_usedFoodInt.Init(CFloatRect(0.9, 0.1, 0.1, 0.8), 4, font1);
	m_usedFoodInt.SetInnerOn();
	m_usedFoodInt.SetLayer(0.97);
	m_usedFoodInt.PrintInt(100);*/



	m_roboter.Init(mat1, CFloatRect(0, 0.8, 1, 0.15));
	m_roboter.SetInnerOn();
	m_roboter.SetLayer(0.98);

	m_roboterW.Init(cursor, font1, CFloatRect(0.05, 0.1, 0.4, 0.8),22);
	m_roboterW.SetInnerOn();
	m_roboterW.SetLayer(0.97);
	m_roboterW.SetLabel("Roboter insgesamt: ");

	m_roboterInsgesamt.Init(CFloatRect(0.47, 0.1, 0.1, 0.8), 4, font1);
	m_roboterInsgesamt.SetInnerOn();
	m_roboterInsgesamt.SetLayer(0.97);
	m_roboterInsgesamt.PrintInt(200);

	
	m_main.SwitchOff();

	m_main.AddOverlay(&m_abort);
	m_main.AddOverlay(&m_wohnungen);
	m_main.AddOverlay(&m_strom);
	m_main.AddOverlay(&m_wasser);
	m_main.AddOverlay(&m_roboter);
	m_main.AddOverlay(&m_food);

	m_wohnungen.AddOverlay(&m_wohnungenW);
	m_wohnungen.AddWriting(&m_wohnungenInsgesamt);
	//m_wohnungen.AddWriting(&m_usedWohnungen);
	//m_wohnungen.AddWriting(&m_usedWohnungenInt);

	m_strom.AddOverlay(&m_StromW);
	m_strom.AddWriting(&m_stromInsgesamt);
	//m_strom.AddWriting(&m_usedStrom);
	//m_strom.AddWriting(&m_usedStromInt);
	
	m_wasser.AddOverlay(&m_wasserW);
	m_wasser.AddWriting(&m_wasserInsgesamt);
	//m_wasser.AddWriting(&m_usedWasser);
	//m_wasser.AddWriting(&m_usedWasserInt);

	m_food.AddOverlay(&m_foodW);
	m_food.AddWriting(&m_foodInsgesamt);
	//m_food.AddWriting(&m_usedFood);
	//m_food.AddWriting(&m_usedFoodInt);

	m_roboter.AddOverlay(&m_roboterW);
	m_roboter.AddWriting(&m_roboterInsgesamt);

}

void ControlCPopup::updatePopup()
{
	

	std::string dummystring;
	dummystring = std::to_string(Player::Instance().getUsedWohnungen()) + "/" + std::to_string(Player::Instance().getWohnung());
	m_wohnungenInsgesamt.PrintString(&dummystring[0]);
	
	dummystring = std::to_string(Player::Instance().getUsePower()) + "/" + std::to_string(Player::Instance().getPower());
	m_stromInsgesamt.PrintString(&dummystring[0]);
	
	dummystring = std::to_string(Player::Instance().getUseWater()) + "/" + std::to_string(Player::Instance().getWater());
	m_wasserInsgesamt.PrintString(&dummystring[0]);
	

	dummystring = std::to_string(Player::Instance().getUseFood()) + "/"+ std::to_string(Player::Instance().getFood());
	m_foodInsgesamt.PrintString(&dummystring[0]);
	

	m_roboterInsgesamt.PrintInt(Player::Instance().getRobots());

	
}
