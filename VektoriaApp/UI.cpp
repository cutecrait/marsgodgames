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
	
}

void UI::InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv,Player* player)
{
	m_viewport = zv;
	InitMaterial();
	m_playerStats = player;
	m_start.Init(cursor, font, CFloatRect(0.f, 0.9, 0.15, 0.1));
	m_start.SetLabel("bauen");
	
	
	m_resBack.Init(&m_matStats, CFloatRect(0.5,0,0.4,0.1));
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
	m_mainSelect.AddOption(" save");

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
	m_res1.SetLabel("Res1: " + std::to_string(m_playerStats->getRessource1()));
	
	m_res2.SetLabel("Res2: " + std::to_string(m_playerStats->getRessource2()));
	m_res2.SetInnerOn();
	m_res2.SetLayer(1);
	
	m_res3.SetLabel("Res3: " + std::to_string(m_playerStats->getRessource3()));
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
	m_res1Minus.SetLabel("Res1: " + std::to_string(m_playerStats->getRessource1() - res1));
	m_res2Minus.SwitchOn();
	m_res2Minus.SetLabel("Res2: " + std::to_string(m_playerStats->getRessource2() - res2));
	m_res3Minus.SwitchOn();
	m_res3Minus.SetLabel("Res3: " + std::to_string(m_playerStats->getRessource3() - res3));

}

void UI::updatePlayer() {

	m_res1.SetLabel("Res1: " + std::to_string(m_playerStats->getRessource1()));
	m_res2.SetLabel("Res2: " + std::to_string(m_playerStats->getRessource2()));
	m_res3.SetLabel("Res3: " + std::to_string(m_playerStats->getRessource3()));
	m_res3.SwitchOn();
	m_res1.SwitchOn();
	m_res2.SwitchOn();
	m_res1Minus.SwitchOff();
	m_res2Minus.SwitchOff();
	m_res3Minus.SwitchOff();
}
void UI::tooltip(std::string name, int res1, int res2, int res3, CFloatRect pos, CDeviceCursor* cursor) {
	m_tooltip.Init(cursor, &m_redFont, CFloatRect(0,0,1,0.7));
	m_tooltip.SetLabel(name);
	m_tooltip.SwitchOn();
	m_tooltip.SetInnerOn();
	m_tooltip.SetLayer(0.98);
	

	m_kosten.Init(cursor, &m_redFont, CFloatRect(0, 0.7, 1, 0.3));
	m_kosten.SetLabel(std::to_string(res1) +" "+ std::to_string(res2) +" "+ std::to_string(res3));
	m_kosten.SwitchOn();
	m_kosten.SetInnerOn();
	m_kosten.SetLayer(0.98);

	m_toolTipBackGround.Init(&m_matStats, pos);
	m_toolTipBackGround.SetLayer(0.97);

	m_viewport->AddOverlay(&m_toolTipBackGround);
	m_toolTipBackGround.AddOverlay(&m_tooltip);
	m_toolTipBackGround.AddOverlay(&m_kosten);

}