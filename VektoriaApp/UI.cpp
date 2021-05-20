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

	m_descMaterial.MakeTextureSprite("textures\\blue_image.jpg");
	
}

void UI::InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv,Player* player)
{
	m_viewport = zv;
	InitMaterial();
	InitToolTip();
	m_playerStats = player;
	m_start.Init(cursor, font, CFloatRect(0.f, 0.9, 0.15, 0.1));
	m_start.SetLabel("bauen");
	
	
	m_resBack.Init(&m_matRes, CFloatRect(0.5,0,0.4,0.1));
	m_resBack.SetLayer(0.98);
	m_redFont.LoadPreset("LucidaConsoleRed");
	m_redFont.SetChromaKeyingOn();
	m_res1.Init(cursor, font, CFloatRect(0, 0.1, 0.3, 0.75));
	m_res2.Init(cursor, font, CFloatRect(0.33, 0.1, 0.3, 0.75));
	m_res3.Init(cursor, font, CFloatRect(0.66, 0.1, 0.3, 0.75));
	
	m_res1Minus.Init(cursor, &m_redFont, CFloatRect(0, 0.1, 0.3, 0.75));
	m_res2Minus.Init(cursor, &m_redFont, CFloatRect(0.33, 0.1, 0.3, 0.75));
	m_res3Minus.Init(cursor, &m_redFont, CFloatRect(0.66, 0.1, 0.3, 0.75));
	initRessource();
	
	//m_mainSelect.makeInactiveMats(m_matsForSelectMain);

	m_mainSelect.Init(cursor, font, 5, CFloatRect(0.0f, 0.0f, 0.15, 0.9));

	m_mainSelect.AddOption(" Roboter");
	m_mainSelect.AddOption(" Wohnen");
	m_mainSelect.AddOption(" Verpflegung");
	m_mainSelect.AddOption(" Was anderes");
	m_mainSelect.AddOption(" Save");

	std::vector <std::string> selectLabel;

	selectLabel.push_back(" Bauroboter"); selectLabel.push_back(" Minenroboter"); selectLabel.push_back(" Landwirtroboter");
	//m_specificSelect[0].makeInactiveMats(m_matsForSelect1);
	m_specificSelect[0].Init(cursor, font, 3, CFloatRect(0.15, 0.f, 0.15, 0.9));

	labelMaker(0, 3, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" Hotel"); selectLabel.push_back(" Einfamilienhaus"); selectLabel.push_back(" Mehrfamilienhaus"); selectLabel.push_back(" Villa");
	//m_specificSelect[1].makeInactiveMats(m_matsForSelect2);
	m_specificSelect[1].Init(cursor, font, 4, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(1, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" Gemüsegarten"); selectLabel.push_back(" Insektenzucht"); selectLabel.push_back(" Abwasserreinigung"); selectLabel.push_back("Strom");
	//m_specificSelect[2].makeInactiveMats(m_matsForSelect3);
	m_specificSelect[2].Init(cursor, font, 4, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(2, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back(" anderes1"); selectLabel.push_back(" anderes2"); selectLabel.push_back(" anderes3"); selectLabel.push_back(" anderes4"); selectLabel.push_back(" anderes5");
	//m_specificSelect[3].makeInactiveMats(m_matsForSelect4);
	m_specificSelect[3].Init(cursor, font, 5, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(3, 5, selectLabel);

	/*selectLabel.clear();
	selectLabel.push_back("anderes1"); selectLabel.push_back(" anderes2"); selectLabel.push_back(" anderes3"); selectLabel.push_back(" anderes4"); selectLabel.push_back(" anderes5"); selectLabel.push_back(" anderes6");
	//m_specificSelect[4].makeInactiveMats(m_matsForSelect5);
	m_specificSelect[4].Init(cursor, font, 6, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(4, 6, selectLabel);*/

	m_mainSelect.SwitchOff();
	m_specificSelect[0].SwitchOff(); m_specificSelect[1].SwitchOff(); m_specificSelect[2].SwitchOff(); m_specificSelect[3].SwitchOff();

	initPlayer(cursor, font);

	m_confirm.Init(cursor, font, CFloatRect(0.9, 0.9, 0.05, 0.1));
	m_cancel.Init(cursor, font, CFloatRect(0.95, 0.9, 0.05, 0.1));

	m_confirm.SetLabel("confirm");
	m_cancel.SetLabel("cancel");
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

void UI::labelMaker(int a,int b,std::vector<std::string> label)
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
}
void UI::initPlayer(CDeviceCursor* cursor, CWritingFont* font) {

	std::string derString;
	
	m_statistic.Init(cursor, font, CFloatRect(0.9,0, 0.1,0.1));
	m_statistic.SetLabel("Player");
	

	m_statsBack.Init(&m_matStats, CFloatRect(0.8,0.1,0.2,0.8)); // hintergrund
	m_statsBack.SetLayer(0.98);
	m_statsBack.SwitchOff();

	
	
	
	m_res1Minus.SetInnerOn();
	m_res1Minus.SetLayer(1);
	m_res1Minus.SwitchOff();

	

	
	m_res2Minus.SetInnerOn();
	m_res2Minus.SetLayer(1);
	m_res2Minus.SwitchOff();

	

	m_res3Minus.SetInnerOn();
	m_res3Minus.SetLayer(1);
	m_res3Minus.SwitchOff();

	m_wohnungen.Init(cursor, font, CFloatRect(0, 0.3, 1, 0.05));
	m_wohnungen.SetLabel("Wohnungen: " + std::to_string(m_playerStats->getWohnung()));
	m_wohnungen.SetInnerOn();
	m_wohnungen.SetLayer(1);


	
	
	m_statsBack.AddOverlay(&m_wohnungen);

	

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
