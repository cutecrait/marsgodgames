#include "UI.h"

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

	m_resMaterial.MakeTextureSprite("textures\\blue_image.jpg");
	m_matstein.MakeTextureSprite("textures\\Tooltip_stein_texture.png");
	m_matchrom.MakeTextureSprite("textures\\Tooltip_chrom_texture.png");
	m_matstahl.MakeTextureSprite("textures\\Tooltip_stahl_texture.png");

	m_descMaterial.MakeTextureSprite("textures\\green_image.jpg");

}

void UI::InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv, Player* player)
{
	m_viewport = zv;
	InitMaterial();
	InitToolTip();
	m_playerStats = player;
	m_start.Init(cursor, font, CFloatRect(0.f, 0.9, 0.15, 0.1));
	m_start.SetLabel("Menu");


	m_resBack.Init(&m_matRes, CFloatRect(0.5, 0, 0.4, 0.1));
	m_resBack.SetLayer(0.98);
	m_redFont.LoadPreset("LucidaConsoleRed");
	m_redFont.SetChromaKeyingOn();
	m_res1.Init(cursor, font, CFloatRect(-0.03, 0.2, 0.4, 0.6));
	m_res2.Init(cursor, font, CFloatRect(0.3, 0.2, 0.4, 0.6));
	m_res3.Init(cursor, font, CFloatRect(0.63, 0.2, 0.4, 0.6));

	m_res1Minus.Init(cursor, &m_redFont, CFloatRect(-0.03, 0.2, 0.4, 0.6));
	m_res2Minus.Init(cursor, &m_redFont, CFloatRect(0.3, 0.2, 0.4, 0.6));
	m_res3Minus.Init(cursor, &m_redFont, CFloatRect(0.63, 0.2, 0.4, 0.6));
	initRessource();

	//m_mainSelect.makeInactiveMats(m_matsForSelectMain);

	m_mainSelect.Init(cursor, font, 5, CFloatRect(0.0f, 0.2f, 0.15, 0.7));

	m_mainSelect.AddOption(" Roboter");
	m_mainSelect.AddOption(" Wohnen");
	m_mainSelect.AddOption(" Verpflegung");
	m_mainSelect.AddOption(" Was anderes");
	m_mainSelect.AddOption(" Save");
	std::vector <std::string> selectLabel;

	selectLabel.push_back(" Bauroboter"); selectLabel.push_back(" Minenroboter"); selectLabel.push_back(" Landwirtroboter");
	//m_specificSelect[0].makeInactiveMats(m_matsForSelect1);
	m_specificSelect[0].Init(cursor, font, 3, CFloatRect(0.15, 0.4, 0.15, 0.5));

	labelMaker(0, 3, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" Hotel"); selectLabel.push_back(" Einfamilienhaus"); selectLabel.push_back(" Mehrfamilienhaus"); selectLabel.push_back(" Villa");
	//m_specificSelect[1].makeInactiveMats(m_matsForSelect2);
	m_specificSelect[1].Init(cursor, font, 4, CFloatRect(0.15, 0.3, 0.15, 0.6)); labelMaker(1, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" Gemüsegarten"); selectLabel.push_back(" Insektenzucht"); selectLabel.push_back(" Abwasserreinigung"); selectLabel.push_back("Strom");
	//m_specificSelect[2].makeInactiveMats(m_matsForSelect3);
	m_specificSelect[2].Init(cursor, font, 4, CFloatRect(0.15, 0.3, 0.15, 0.6)); labelMaker(2, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" anderes1"); selectLabel.push_back(" anderes2"); selectLabel.push_back(" anderes3"); selectLabel.push_back(" anderes4"); selectLabel.push_back(" anderes5"); 
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
	zv->AddOverlay(&m_resBack);

	zv->AddOverlay(&m_statistic);
	zv->AddOverlay(&m_statsBack);
	//zv->AddOverlay(&m_tooltip);

	m_resBack.AddOverlay(&m_res1);
	m_resBack.AddOverlay(&m_res3);
	m_resBack.AddOverlay(&m_res2);
	m_resBack.AddOverlay(&m_res1Minus);
	m_resBack.AddOverlay(&m_res2Minus);
	m_resBack.AddOverlay(&m_res3Minus);
}

void UI::labelMaker(int a, int b, std::vector<std::string> label)
{
	for (int i = 0; i < b; i++) {
		m_specificSelect[a].AddOption(label.at(i));
	}
}
void UI::initRessource() {


	m_res1.SetInnerOn();
	m_res1.SetLayer(1);
	m_res1.SetLabel("      " + std::to_string(m_playerStats->getRessource1()));

	m_res2.SetLabel("      " + std::to_string(m_playerStats->getRessource2()));
	m_res2.SetInnerOn();
	m_res2.SetLayer(1);

	m_res3.SetLabel("      " + std::to_string(m_playerStats->getRessource3()));
	m_res3.SetInnerOn();
	m_res3.SetLayer(1);

	m_res1Minus.SetInnerOn();
	m_res1Minus.SetLayer(1);
	m_res1Minus.SwitchOff();

	m_res2Minus.SetInnerOn();
	m_res2Minus.SetLayer(1);
	m_res2Minus.SwitchOff();

	m_res3Minus.SetInnerOn();
	m_res3Minus.SetLayer(1);
	m_res3Minus.SwitchOff();

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
	//writing für level + variable für zahl
	//overlay für fortschritt + writing für fortschritt
	//button für missionen 

	m_wohnungen.Init(&m_matStats, CFloatRect(0, 0.3, 1, 0.05));
	m_wohnungen.SetInnerOn();
	m_wohnungen.SetLayer(0.97);
	m_wohnungenW.Init(CFloatRect(), 20, font);
	derString = "Wohnungen: " + std::to_string(m_playerStats->getWohnung());
	m_wohnungenW.PrintString(&derString[0]);
	m_wohnungenW.SetLayer(0.96);
	m_wohnungenW.SetInnerOn();




	m_statsBack.AddOverlay(&m_wohnungen);
	m_wohnungen.AddWriting(&m_wohnungenW);
	m_statsBack.AddOverlay(&m_level);


}

void UI::switchOnBuy(int res1, int res2, int res3) {

	m_res1.SwitchOff();
	m_res2.SwitchOff();
	m_res3.SwitchOff();
	m_res1Minus.SwitchOn();
	m_res1Minus.SetLabel("      " + std::to_string(m_playerStats->getRessource1() - res1));
	m_res2Minus.SwitchOn();
	m_res2Minus.SetLabel("      " + std::to_string(m_playerStats->getRessource2() - res2));
	m_res3Minus.SwitchOn();
	m_res3Minus.SetLabel("      " + std::to_string(m_playerStats->getRessource3() - res3));

}



void UI::updatePlayer() {

	m_res1.SetLabel("      " + std::to_string(m_playerStats->getRessource1()));
	m_res2.SetLabel("      " + std::to_string(m_playerStats->getRessource2()));
	m_res3.SetLabel("      " + std::to_string(m_playerStats->getRessource3()));
	m_res3.SwitchOn();
	m_res1.SwitchOn();
	m_res2.SwitchOn();
	m_res1Minus.SwitchOff();
	m_res2Minus.SwitchOff();
	m_res3Minus.SwitchOff();
}
void UI::tooltip(std::string headline, int res1, int res2, int res3, int anzahl, std::string whatHappens) {
	m_headlineW.PrintString(&headline[0]);
	m_kosten1W.PrintInt(res1);
	m_kosten2W.PrintInt(res2);
	m_kosten3W.PrintInt(res3);

	m_descriptionW2.PrintInt(anzahl);
	m_descriptionW3.PrintString(&whatHappens[0]);
	m_toolTipBackGround.SwitchOn();

}


void UI::InitToolTip() {
	m_toolTipBackGround.Init(&m_matStats, CFloatRect(0.4, 0.6, 0.4, 0.4));
	m_toolTipBackGround.SetLayer(0.99); // das setlayer(1) = man sieht den hintergrund nie! (aber gut um alles anzuschalten bzw aus)

	m_viewport->AddOverlay(&m_toolTipBackGround);

	//ueberschrift
	m_headline.Init(&m_matStats, CFloatRect(0, 0, 0.25, 0.5));
	m_headlineW.Init(CFloatRect(0, 0, 0.5, 0.5), 11, &m_redFont);
	m_headline.SetInnerOn();
	m_headline.SetLayer(0.98);
	m_headlineW.SetInnerOn();
	m_headlineW.SetLayer(0.97);

	//ressource1
	m_kosten1.Init(&m_matstein, CFloatRect(0, 0.75, 0.3, 0.25));
	m_kosten1.SetLayer(0.98);
	m_kosten1.SetInnerOn();
	m_kosten1W.Init(CFloatRect(0, 0, 1, 1), 5, &m_redFont);
	m_kosten1W.SetInnerOn();
	m_kosten1W.SetLayer(0.97);

	//ressource2
	m_kosten2.Init(&m_matstahl, CFloatRect(0.33, 0.75, 0.3, 0.25));
	m_kosten2.SetLayer(0.98);
	m_kosten2.SetInnerOn();
	m_kosten2W.Init(CFloatRect(0, 0, 1, 1), 5, &m_redFont);
	m_kosten2W.SetInnerOn();
	m_kosten2W.SetLayer(0.97);

	//ressource3
	m_kosten3.Init(&m_matchrom, CFloatRect(0.66, 0.75, 0.3, 0.25));
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

	m_descriptionW3.Init(CFloatRect(0.1, 0.6, 1, 0.3), 25, &m_redFont);
	m_descriptionW3.SetLayer(0.96);
	m_descriptionW3.SetInnerOn();

	m_toolTipBackGround.AddWriting(&m_headlineW);
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
	std::string stringForMissi;
	for (int i = 0; i < 5; i++) {
		m_missi[i].Init(&m_matStats, CFloatRect());
		m_missi[i].SetInnerOn();
		m_missi[i].SetLayer(0.907);
		m_missi[i].SwitchOff();

		m_missiW[i].Init(CFloatRect(), 25, font);
		m_missiW[i].SetInnerOn();
		m_missiW[i].SetLayer(0.906);
		m_missiW[i].SwitchOff();

		missions->AddOverlay(&m_missi[i]);
		m_missi[i].AddWriting(&m_missiW[i]);

	}
	stringForMissi = "baue: " + std::to_string(2) + " Bauroboter";
	//diese funktion muss am besten in der game cpp ausgeführt werden anstatt hier oder im clickmanager.
	makeAllMissions(4,&stringForMissi[0], "ich bin die zweite", "und ich die dritte missi");


	/*float anteil = 1;
	anteil = anteil / Anzahlmissions;
	std::string dummy;
	m_missi1.Init(&m_matStats, CFloatRect(0.02, 0.01, 0.8, anteil));
	m_missi1.SetInnerOn();
	m_missi1.SetLayer(0.907);
	dummy = std::to_string(1) + ")Baue " + std::to_string(1) + " Bauroboter";
	m_missi1W.Init(CFloatRect(0, 0.1, 1, 0.8), 25, font);
	m_missi1W.SetInnerOn();
	m_missi1W.SetLayer(0.906);
	m_missi1W.PrintString(&dummy[0]);

	m_missi2.Init(&m_matStats, CFloatRect(0.02, anteil, 0.8, anteil));
	m_missi2.SetInnerOn();
	m_missi2.SetLayer(0.907);
	dummy = std::to_string(2) + ")Baue " + std::to_string(1) + " landwirtroboter";
	m_missi2W.Init(CFloatRect(0, 0.1, 1, 0.8), 25, font);
	m_missi2W.SetInnerOn();
	m_missi2W.SetLayer(0.906);
	m_missi2W.PrintString(&dummy[0]);

	m_missi3.Init(&m_matStats, CFloatRect(0.02, anteil*2, 0.8, anteil));
	m_missi3.SetInnerOn();
	m_missi3.SetLayer(0.907);
	dummy = std::to_string(3) + ")Baue " + std::to_string(1) + " minenroboter";
	m_missi3W.Init(CFloatRect(0, 0.1, 1, 0.8), 25, font);
	m_missi3W.SetInnerOn();
	m_missi3W.SetLayer(0.906);
	m_missi3W.PrintString(&dummy[0]);

	missions->AddOverlay(&m_missi1);
	missions->AddOverlay(&m_missi2);
	missions->AddOverlay(&m_missi3);
	m_missi1.AddWriting(&m_missi1W);
	m_missi2.AddWriting(&m_missi2W);
	m_missi3.AddWriting(&m_missi3W);*/

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
//diese funktion wird am anfang an wenn man ein neues level ereicht ausgeführt 

void UI::makeAllMissions(float missionAnzahl,std::string m1, std::string m2 , std::string m3, std::string m4, std::string m5)
{
	float y_pos =0.05;
	std::string dummyArray[5] = { m1,m2,m3,m4,m5 };
	std::string dummystring;
	for (int i = 0; i < missionAnzahl; i++) {
		dummystring = dummyArray[i];
		m_missi[i].Init(&m_matStats, CFloatRect(0.05, y_pos, 0.8, 0.95 / missionAnzahl));
		y_pos += 0.95f / missionAnzahl;
		m_missi[i].SwitchOn();

		m_missiW[i].Init(CFloatRect(0,0.1,1,0.8), 25, &m_redFont);
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

	m_levelFortschritt.Init(&m_descMaterial, CFloatRect(0, 0, (1.0f / anzahlMissGesamt) * anzahlAbgeschlossenerMiss, 1));

	//dummy = std::to_string((anzahlAbgeschlossenerMiss / anzahlMissGesamt) * 100) + "%";
	dummyint = (anzahlAbgeschlossenerMiss / anzahlMissGesamt) * 100;
	dummy = std::to_string(dummyint) + "%";
	levelFortschrittW.PrintString(&dummy[0]);

	
}

