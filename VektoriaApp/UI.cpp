#include "UI.h"
#include "Player.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::InitMaterial()
{
	m_material.MakeTextureSprite("textures\\Menu_Button.png");
	
	m_matsForSelectMain[0].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelectMain[1].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelectMain[2].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelectMain[3].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelectMain[4].MakeTextureSprite("textures\\Menu_Button.png");

	m_matsForSelect1[0].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect1[1].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect1[2].MakeTextureSprite("textures\\Menu_Button.png");

	m_matsForSelect2[0].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect2[1].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect2[2].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect2[3].MakeTextureSprite("textures\\Menu_Button.png");

	m_matsForSelect3[0].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect3[1].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect3[2].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect3[3].MakeTextureSprite("textures\\Menu_Button.png");

	m_matsForSelect4[0].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect4[1].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect4[2].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect4[3].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect4[4].MakeTextureSprite("textures\\Menu_Button.png");

	m_matsForSelect5[0].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect5[1].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect5[2].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect5[3].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect5[4].MakeTextureSprite("textures\\Menu_Button.png");
	m_matsForSelect5[5].MakeTextureSprite("textures\\Menu_Button.png");

	m_matStats.MakeTextureSprite("textures\\Player_Stat_Window.png");
	m_matRes.MakeTextureSprite("textures\\Player_Res_Window.png");

	m_resMaterial.MakeTextureSprite("textures\\red_image.jpg");
	m_matsteel.MakeTextureSprite("textures\\Tooltip_stahl_texture.png");
	m_matconcrete.MakeTextureSprite("textures\\Tooltip_concrete_texture.png");
	m_matwood.MakeTextureSprite("textures\\Tooltip_wood_texture.png");

	m_descMaterial.MakeTextureSprite("textures\\green_image.jpg");

}

void UI::InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv)
{
	m_viewport = zv;
	InitMaterial();
	InitToolTip();

	m_roboPopUP.Init(cursor,&m_matStats,font);
	m_apsPopup.Init(cursor, &m_matStats, font);
	m_CCpopup.Init(cursor, &m_matStats, font);
	m_wellPopup.Init(cursor, &m_matStats, font);

	m_start.Init(cursor, font, CFloatRect(0.f, 0.9, 0.15, 0.1));
	m_start.SetLabel("Menu");


	/*m_resBack.Init(&m_matRes, CFloatRect(0.5, 0, 0.4, 0.1));
	m_resBack.SetLayer(0.98);*/
	m_Ressources.Init(cursor, font, CFloatRect(0.5, 0, 0.4, 0.1));
	m_redFont.LoadPreset("LucidaConsoleRed");
	m_redFont.SetChromaKeyingOn();
	

	
	initRessource(font);

	//m_mainSelect.makeInactiveMats(m_matsForSelectMain);

	m_mainSelect.Init(cursor, font, 5, CFloatRect(0.0f, 0.2f, 0.15, 0.7));

	m_mainSelect.AddOption(" Fabriken");
	m_mainSelect.AddOption(" Wohnen");
	m_mainSelect.AddOption(" Verpflegung");
	m_mainSelect.AddOption(" Was anderes");
	m_mainSelect.AddOption(" Save");
	std::vector <std::string> selectLabel;

	selectLabel.push_back(" Roboterfabrik"); selectLabel.push_back(" FabrikNr2"); selectLabel.push_back(" FabrikNr3");
	//m_specificSelect[0].makeInactiveMats(m_matsForSelect1);
	m_specificSelect[0].Init(cursor, font, 3, CFloatRect(0.15, 0.4, 0.15, 0.5));

	labelMaker(0, 3, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" Hotel"); selectLabel.push_back(" Einfamilienhaus"); selectLabel.push_back(" Mehrfamilienhaus"); selectLabel.push_back(" Villa");
	//m_specificSelect[1].makeInactiveMats(m_matsForSelect2);
	m_specificSelect[1].Init(cursor, font, 4, CFloatRect(0.15, 0.3, 0.15, 0.6)); labelMaker(1, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" Brunnen"); selectLabel.push_back(" Farm"); selectLabel.push_back(" Abwasserreinigung"); selectLabel.push_back(" Strom");
	//m_specificSelect[2].makeInactiveMats(m_matsForSelect3);
	m_specificSelect[2].Init(cursor, font, 4, CFloatRect(0.15, 0.3, 0.15, 0.6)); labelMaker(2, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" ControlCenter"); selectLabel.push_back(" anderes2"); selectLabel.push_back(" anderes3"); selectLabel.push_back(" anderes4"); selectLabel.push_back(" anderes5"); 
	//m_specificSelect[3].makeInactiveMats(m_matsForSelect4);
	m_specificSelect[3].Init(cursor, font, 5, CFloatRect(0.15, 0.2, 0.15, 0.7)); labelMaker(3, 5, selectLabel);

	m_mainSelect.SwitchOff();
	m_specificSelect[0].SwitchOff(); m_specificSelect[1].SwitchOff(); m_specificSelect[2].SwitchOff(); m_specificSelect[3].SwitchOff();

	initPlayer(cursor, font);

	m_confirm.Init(cursor, font, CFloatRect(0.8, 0.9, 0.1, 0.10));
	m_cancel.Init(cursor, font, CFloatRect(0.9, 0.9, 0.1, 0.10));

	m_confirm.SetLabel("Confirm");
	m_cancel.SetLabel("Cancel");
	m_confirm.SwitchOff();
	m_cancel.SwitchOff();


	zv->AddOverlay(&m_start);
	zv->AddOverlay(&m_mainSelect);
	zv->AddOverlay(&m_specificSelect[0]);
	zv->AddOverlay(&m_specificSelect[1]);
	zv->AddOverlay(&m_specificSelect[2]);
	zv->AddOverlay(&m_specificSelect[3]);
	//zv->AddOverlay(&m_specificSelect[4]);
	zv->AddOverlay(&m_confirm);
	zv->AddOverlay(&m_cancel);
	zv->AddOverlay(&m_Ressources);
	//zv->AddOverlay(&m_roboPopUP.m_robo1Add);
	zv->AddOverlay(&m_statistic);
	zv->AddOverlay(&m_statsBack);
	zv->AddOverlay(&m_roboPopUP.m_main);
	zv->AddOverlay(&m_apsPopup.m_main);
	zv->AddOverlay(&m_CCpopup.m_main);
	zv->AddOverlay(&m_wellPopup.m_main);
	//zv->AddOverlay(&m_tooltip);

	

	/*m_resBack.AddOverlay(&m_concrete);
	m_resBack.AddOverlay(&m_wood);
	m_resBack.AddOverlay(&m_steel);
	m_resBack.AddOverlay(&m_concreteMinus);
	m_resBack.AddOverlay(&m_steelMinus);
	m_resBack.AddOverlay(&m_woodMinus);*/
}

void UI::labelMaker(int a, int b, std::vector<std::string> label)
{
	for (int i = 0; i < b; i++) {
		m_specificSelect[a].AddOption(label.at(i));
	}
}
void UI::initRessource(CWritingFont* font) {
/*	m_concrete.Init(cursor, font, CFloatRect(-0.03, 0.2, 0.4, 0.6));
	m_steel.Init(cursor, font, CFloatRect(0.3, 0.2, 0.4, 0.6));
	m_wood.Init(cursor, font, CFloatRect(0.63, 0.2, 0.4, 0.6));

	m_concreteMinus.Init(cursor, &m_redFont, CFloatRect(-0.03, 0.2, 0.4, 0.6));
	m_steelMinus.Init(cursor, &m_redFont, CFloatRect(0.3, 0.2, 0.4, 0.6));
	m_woodMinus.Init(cursor, &m_redFont, CFloatRect(0.63, 0.2, 0.4, 0.6));*/

	
	m_Ressources.SetLayer(0.99);
	m_Ressources.SetMaterial(&m_matRes);

	

	m_concreteW.Init(CFloatRect(0.2,0.1,0.1, 0.8), 5, font);
	m_concreteW.SetInnerOn();
	m_concreteW.SetLayer(0.78);
	m_concreteW.PrintInt(Player::Instance().getConcrete());

	m_concreteW.SwitchOn();



	m_steelW.Init(CFloatRect(0.5, 0.1, 0.1, 0.8), 5, font);
	m_steelW.SetInnerOn();
	m_steelW.SetLayer(0.78);
	m_steelW.PrintInt(Player::Instance().getSteel());

	m_steelW.SwitchOn();
	

	m_woodW.Init(CFloatRect(0.8, 0.1, 0.1, 0.8), 5, font);
	m_woodW.SetInnerOn();
	m_woodW.SetLayer(0.78);
	m_woodW.PrintInt(Player::Instance().getWood());
	m_woodW.SwitchOn();

	m_concreteMinusW.Init(CFloatRect(0.2, 0.1, 0.1, 0.8), 5, &m_redFont);
	m_concreteMinusW.SetInnerOn();
	m_concreteMinusW.SetLayer(0.78);
	m_concreteMinusW.SwitchOff();

	m_steelMinusW.Init(CFloatRect(0.5, 0.1, 0.1, 0.8), 5, &m_redFont);
	m_steelMinusW.SetInnerOn();
	m_steelMinusW.SetLayer(0.78);
	
	m_steelMinusW.SwitchOff();
	m_woodMinusW.Init(CFloatRect(0.8, 0.1, 0.1, 0.8), 5, &m_redFont);
	m_woodMinusW.SetInnerOn();
	m_woodMinusW.SetLayer(0.78);
	
	m_woodMinusW.SwitchOff();
	
	m_Ressources.AddWriting(&m_concreteW);
	m_Ressources.AddWriting(&m_woodW);
	m_Ressources.AddWriting(&m_steelW);

	m_Ressources.AddWriting(&m_concreteMinusW);
	m_Ressources.AddWriting(&m_woodMinusW);
	m_Ressources.AddWriting(&m_steelMinusW);
	
	/*m_concrete.Init();
	m_concrete.SetInnerOn();
	m_concrete.SetLayer(1);
	m_concrete.PrintString("      " + std::to_string(Player::Instance().getConcrete()));

	m_steel.SetLabel("      " + std::to_string(Player::Instance().getSteel()));
	m_steel.SetInnerOn();
	m_steel.SetLayer(1);

	m_wood.SetLabel("      " + std::to_string(Player::Instance().getWood()));
	m_wood.SetInnerOn();
	m_wood.SetLayer(1);

	m_concreteMinus.SetInnerOn();
	m_concreteMinus.SetLayer(1);
	m_concreteMinus.SwitchOff();

	m_steelMinus.SetInnerOn();
	m_steelMinus.SetLayer(1);
	m_steelMinus.SwitchOff();

	m_woodMinus.SetInnerOn();
	m_woodMinus.SetLayer(1);
	m_woodMinus.SwitchOff();*/

}
void UI::initPlayer(CDeviceCursor* cursor, CWritingFont* font) {

	std::string derString;

	m_statistic.Init(cursor, font, CFloatRect(0.9, 0, 0.1, 0.1)); //button
	m_statistic.SetLabel("Player");


	m_statsBack.Init(&m_matStats, CFloatRect(0.8, 0.1, 0.2, 0.8)); // ganzer hintergrund
	m_statsBack.SetLayer(0.98);
	m_statsBack.SwitchOff();

	m_level.Init(&m_matStats, CFloatRect(0, 0, 1, 0.3));
	m_level.SetInnerOn();
	m_level.SetLayer(0.97);
	levelOverlay(&m_level, font, cursor);
	//writing f�r level + variable f�r zahl
	//overlay f�r fortschritt + writing f�r fortschritt
	//button f�r missionen 

	m_wohnungen.Init(&m_matStats, CFloatRect(0, 0.3, 1, 0.05));
	m_wohnungen.SetInnerOn();
	m_wohnungen.SetLayer(0.97);
	m_wohnungenW.Init(CFloatRect(), 20, font);
	derString = "Wohnungen: " + std::to_string(Player::Instance().getWohnung());
	m_wohnungenW.PrintString(&derString[0]);
	m_wohnungenW.SetLayer(0.96);
	m_wohnungenW.SetInnerOn();




	m_statsBack.AddOverlay(&m_wohnungen);
	m_wohnungen.AddWriting(&m_wohnungenW);
	m_statsBack.AddOverlay(&m_level);


}

void UI::switchOnBuy(int res1, int res2, int res3) {

	m_concreteW.SwitchOff();
	m_steelW.SwitchOff();
	m_woodW.SwitchOff();
	m_concreteMinusW.SwitchOn();
	m_concreteMinusW.PrintInt(Player::Instance().getConcrete() - res1);
	m_steelMinusW.SwitchOn();
	m_steelMinusW.PrintInt(Player::Instance().getSteel() - res2);
	m_woodMinusW.SwitchOn();
	m_woodMinusW.PrintInt(Player::Instance().getWood() - res3);

}



void UI::updatePlayer() {

	m_concreteW.PrintInt(Player::Instance().getConcrete());
	m_steelW.PrintInt(Player::Instance().getSteel());
	m_woodW.PrintInt(Player::Instance().getWood());
	m_woodW.SwitchOn();
	m_concreteW.SwitchOn();
	m_steelW.SwitchOn();
	m_concreteMinusW.SwitchOff();
	m_steelMinusW.SwitchOff();
	m_woodMinusW.SwitchOff();
}
roboPopUp* UI::getRobo(roboPopUp * einsrobo)
{

	return einsrobo;
}
void UI::tooltip(std::string headline, int res1, int res2, int res3, int anzahl, BuildingCategory bla) {
	m_headlineW.PrintString(&headline[0]);
	m_kosten1W.PrintInt(res1);
	m_kosten2W.PrintInt(res2);
	m_kosten3W.PrintInt(res3);

	m_descriptionW2.PrintInt(anzahl);
	
	if (BuildingCategory::Living == bla) {
		m_descriptionW3.PrintString("Wohnungen hinzugefuegt");
	}
	if (BuildingCategory::Farming == bla) {
		m_descriptionW3.PrintString("Nahrungseinheiten hinzugefuegt");
	}
	//hier weitere tooltips hinzufuegen (nur die "if")


	m_toolTipBackGround.SwitchOn();

}


void UI::InitToolTip() {
	m_toolTipBackGround.Init(&m_matStats, CFloatRect(0.4, 0.6, 0.4, 0.4));
	m_toolTipBackGround.SetLayer(0.99); // das setlayer(1) = man sieht den hintergrund nie! (aber gut um alles anzuschalten bzw aus)

	m_viewport->AddOverlay(&m_toolTipBackGround);

	//ueberschrift
	m_headline.Init(&m_matStats, CFloatRect(0, 0, 0.25, 0.5));
	m_headlineW.Init(CFloatRect(0.1, 0.2, 1, 0.5), 11, &m_redFont);
	m_headline.SetInnerOn();
	m_headline.SetLayer(1);
	m_headlineW.SetInnerOn();
	m_headlineW.SetLayer(0.97);

	//ressource1
	m_kosten1.Init(&m_matsteel, CFloatRect(0, 0.75, 0.3, 0.25));
	m_kosten1.SetLayer(0.98);
	m_kosten1.SetInnerOn();
	m_kosten1W.Init(CFloatRect(0, 0, 1, 1), 5, &m_redFont);
	m_kosten1W.SetInnerOn();
	m_kosten1W.SetLayer(0.97);

	//ressource2
	m_kosten2.Init(&m_matconcrete, CFloatRect(0.33, 0.75, 0.3, 0.25));
	m_kosten2.SetLayer(0.98);
	m_kosten2.SetInnerOn();
	m_kosten2W.Init(CFloatRect(0, 0, 1, 1), 5, &m_redFont);
	m_kosten2W.SetInnerOn();
	m_kosten2W.SetLayer(0.97);

	//ressource3
	m_kosten3.Init(&m_matwood, CFloatRect(0.66, 0.75, 0.3, 0.25));
	m_kosten3.SetLayer(0.98);
	m_kosten3.SetInnerOn();
	m_kosten3W.Init(CFloatRect(0, 0, 1, 1), 5, &m_redFont);
	m_kosten3W.SetInnerOn();
	m_kosten3W.SetLayer(0.97);

	//description
	m_description.Init(&m_descMaterial, CFloatRect(0.3, 0, 0.7, 0.65));
	m_description.SetInnerOn();
	m_description.SetLayer(0.98);

	m_descriptionW1.Init(CFloatRect(0.1, 0.1, 1, 0.3), 20, &m_redFont);
	m_descriptionW1.SetLayer(0.96);
	m_descriptionW1.SetInnerOn();
	m_descriptionW1.PrintString("beim kauf werden: ");

	m_descriptionW2.Init(CFloatRect(0.4, 0.4, 1, 0.2), 20, &m_redFont);
	m_descriptionW2.SetLayer(0.96);
	m_descriptionW2.SetInnerOn();

	m_descriptionW3.Init(CFloatRect(0.1, 0.6, 1, 0.3), 30, &m_redFont);
	m_descriptionW3.SetLayer(0.96);
	m_descriptionW3.SetInnerOn();


	m_toolTipBackGround.AddOverlay(&m_headline);
	m_headline.AddWriting(&m_headlineW);
	m_toolTipBackGround.AddOverlay(&m_kosten1);
	m_kosten1.AddWriting(&m_kosten1W);
	m_toolTipBackGround.AddOverlay(&m_kosten2);
	m_kosten2.AddWriting(&m_kosten2W);
	m_toolTipBackGround.AddOverlay(&m_kosten3);
	m_kosten3.AddWriting(&m_kosten3W);
	m_toolTipBackGround.AddOverlay(&m_description);
	m_description.AddWriting(&m_descriptionW1);
	m_description.AddWriting(&m_descriptionW2);
	m_description.AddWriting(&m_descriptionW3);

	m_toolTipBackGround.SwitchOff();
}
//beim programmstart 
void UI::levelOverlay(COverlay* background, CWritingFont* font, CDeviceCursor* cursor)
{
	laenge = 0.5;
	std::string dummy;
	dummy = "Level " + std::to_string(1);
	m_levelW.Init(CFloatRect(0.1, 0.05, 0.7, 0.2), 8, &m_redFont);
	m_levelW.PrintString(&dummy[0]);
	m_levelW.SetInnerOn();
	m_levelW.SetLayer(0.96);

	levelFortschritt.Init(&m_resMaterial, CFloatRect(0.1, 0.3, 0.8, 0.1));
	levelFortschritt.SetInnerOn();
	levelFortschritt.SetLayer(0.97);

	m_levelFortschritt.Init(&m_descMaterial, CFloatRect(0, 0, 0, 1));
	m_levelFortschritt.SetInnerOn();
	m_levelFortschritt.SetLayer(0.96);

	dummy = std::to_string(50) + "%";
	levelFortschrittW.Init(CFloatRect(0.7, 0.25, 0.25, 0.5), 10, font);
	levelFortschrittW.SetInnerOn();
	levelFortschrittW.SetLayer(0.95);
	levelFortschrittW.PrintString(&dummy[0]);

	m_missionen.Init(cursor, font, CFloatRect(0, 0.5, 0.7, 0.4));
	m_missionen.SetInnerOn();
	m_missionen.SetLayer(0.97);
	m_missionen.SetMaterialNormal(m_matStats);
	m_missionen.SetLabel("Missionen: " + std::to_string(0) + "/" + std::to_string(0));

	m_missionenBack.Init(&m_matStats, CFloatRect(0, 0.3, 1, 0.3));
	m_missionenBack.SetInnerOn();
	m_missionenBack.SetLayer(0.908);
	m_missionenBack.SwitchOff();
	buildMission(&m_missionenBack, font);


	background->AddWriting(&m_levelW);
	background->AddOverlay(&levelFortschritt);
	levelFortschritt.AddOverlay(&m_levelFortschritt);
	levelFortschritt.AddWriting(&levelFortschrittW);
	background->AddOverlay(&m_missionen);

	m_statsBack.AddOverlay(&m_missionenBack);

}
void UI::buildMission(COverlay* missions, CWritingFont* font)
{

	for (int i = 0; i < 5; i++) {
		m_missi[i].Init(&m_matStats, CFloatRect());
		m_missi[i].SetInnerOn();
		m_missi[i].SetLayer(1);
		m_missi[i].SwitchOff();
		
		m_missiStatus[i].Init(&m_resMaterial, CFloatRect());
		m_missiStatus[i].SetInnerOn();
		m_missiStatus[i].SetLayer(0.8);
		m_missiStatus[i].SwitchOff();

		m_missiW[i].Init(CFloatRect(), 25, font);
		m_missiW[i].SetInnerOn();
		m_missiW[i].SetLayer(0.906);
		m_missiW[i].SwitchOff();

		missions->AddOverlay(&m_missi[i]);
		missions->AddOverlay(&m_missiStatus[i]);
		m_missi[i].AddWriting(&m_missiW[i]);

	}
	
	//diese funktion muss am besten in der game cpp ausgef�hrt werden anstatt hier oder im clickmanager.


}

void UI::updateWriting(std::string label, CWriting* writing)
{
	writing->PrintString(&label[0]);
}

void UI::makeAMission(std::string bla, int missionNr)
{
	m_missiW[missionNr].PrintString(&bla[0]);
}

//standard missions macher
//diese funktion wird am anfang an wenn man ein neues level ereicht ausgef�hrt 

void UI::makeAllMissions(float missionAnzahl, int currentLevel,std::string m1, std::string m2 , std::string m3, std::string m4, std::string m5)
{
	std::string dummystring;
	m_levelFortschritt.Init(&m_descMaterial, CFloatRect(0, 0, 0, 1));
	dummystring = std::to_string(0) + "%";
	levelFortschrittW.PrintString(&dummystring[0]);
	dummystring = "Level: " + std::to_string(currentLevel);
	m_levelW.PrintString(&dummystring[0]);

	int dummyint = missionAnzahl;
	m_missionen.SetLabel("Missionen: " + std::to_string(0) + "/" + std::to_string(dummyint));
	float y_pos =0.05;
	std::string dummyArray[5] = { m1,m2,m3,m4,m5 };
	
	for (int i = 0; i < missionAnzahl; i++) {
		dummystring = dummyArray[i];
		m_missi[i].Init(&m_matStats, CFloatRect(0.05, y_pos, 0.8, 0.95 / missionAnzahl));
		m_missiStatus[i].Init(&m_resMaterial,CFloatRect(0.85,y_pos,0.1,0.1));
		m_missiStatus[i].SwitchOn();
		y_pos += 0.95f / missionAnzahl;
		m_missi[i].SwitchOn();

		m_missiW[i].Init(CFloatRect(0.1,0.1,1,0.8), 40, &m_redFont);
		m_missiW[i].PrintString(&dummystring[0]);
		m_missiW[i].SwitchOn();
		
	}
	
}

void UI::updateLevelUI(float anzahlMissGesamt, float anzahlAbgeschlossenerMiss, int welchesLevel) {
	std::string dummy;
	int dummyint = anzahlAbgeschlossenerMiss;
	int dummyint1 = anzahlMissGesamt;
	dummy = "Missionen: " +std::to_string(dummyint) +"/" +std::to_string(dummyint1);
	m_missionen.SetLabel(&dummy[0]);
	m_missiStatus[dummyint-1].SetMaterial(&m_descMaterial);
	m_levelFortschritt.Init(&m_descMaterial, CFloatRect(0, 0, (1.0f / anzahlMissGesamt) * anzahlAbgeschlossenerMiss, 1));

	//dummy = std::to_string((anzahlAbgeschlossenerMiss / anzahlMissGesamt) * 100) + "%";
	dummyint = (anzahlAbgeschlossenerMiss / anzahlMissGesamt) * 100;
	dummy = std::to_string(dummyint) + "%";
	levelFortschrittW.PrintString(&dummy[0]);
	
	
	
}

popup* UI::getPopup(std::string type)
{
	if (type == typeid(RobotFactory).name()) {
		
		return& m_roboPopUP;
	}
	if (type == typeid(Apartment).name()) {
		return&m_apsPopup;
	}

	if (type == typeid(ControlCenter).name()) {
		return&m_CCpopup;
	}

	if (type == typeid(Well).name()) {
		return &m_wellPopup;
	}
	return nullptr;
}

//update individual mission
//kriegt 