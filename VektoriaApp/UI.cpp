#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::InitMaterial()
{
	
	m_matsForSelectMain[0].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelectMain[1].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelectMain[2].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelectMain[3].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelectMain[4].MakeTextureSprite("textures\\ENV.jpg");

	m_matsForSelect1[0].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect1[1].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect1[2].MakeTextureSprite("textures\\ENV.jpg");

	m_matsForSelect2[0].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect2[1].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect2[2].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect2[3].MakeTextureSprite("textures\\ENV.jpg");

	m_matsForSelect2[0].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect2[1].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect2[2].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect2[3].MakeTextureSprite("textures\\ENV.jpg");

	m_matsForSelect4[0].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect4[1].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect4[2].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect4[3].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect4[4].MakeTextureSprite("textures\\ENV.jpg");

	m_matsForSelect5[0].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect5[1].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect5[2].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect5[3].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect5[4].MakeTextureSprite("textures\\ENV.jpg");
	m_matsForSelect5[5].MakeTextureSprite("textures\\ENV.jpg");

	m_matStats.MakeTextureSprite("textures\\blue_image.jpg");
	
}

void UI::InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv,Player* player)
{
	InitMaterial();
	m_playerStats = player;
	m_start.Init(cursor, font, CFloatRect(0.f, 0.9, 0.15, 0.1));
	m_start.SetLabel("bauen");

	m_mainSelect.makeInactiveMats(m_matsForSelectMain);

	m_mainSelect.Init(cursor, font, 5, CFloatRect(0.0f, 0.0f, 0.15, 0.9));

	m_mainSelect.AddOption("Roboter");
	m_mainSelect.AddOption("Wohnen");
	m_mainSelect.AddOption("Verpflegung");
	m_mainSelect.AddOption("Was anderes");
	m_mainSelect.AddOption("noch was anderes");

	std::vector <std::string> selectLabel;

	selectLabel.push_back("Bauroboter"); selectLabel.push_back("Minenroboter"); selectLabel.push_back("Landwirtroboter");
	m_specificSelect[0].makeInactiveMats(m_matsForSelect1);
	m_specificSelect[0].Init(cursor, font, 3, CFloatRect(0.15, 0.f, 0.15, 0.9));

	labelMaker(0, 3, selectLabel);

	selectLabel.clear();
	selectLabel.push_back("hotel"); selectLabel.push_back("Einfamilienhaus"); selectLabel.push_back("Mehrfamilienhaus"); selectLabel.push_back("Villa");
	m_specificSelect[1].makeInactiveMats(m_matsForSelect2);
	m_specificSelect[1].Init(cursor, font, 4, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(1, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back("Gemüsegarten"); selectLabel.push_back("Insektenzucht"); selectLabel.push_back("Abwasserreinigung"); selectLabel.push_back("Strom");
	m_specificSelect[2].makeInactiveMats(m_matsForSelect3);
	m_specificSelect[2].Init(cursor, font, 4, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(2, 4, selectLabel);

	selectLabel.clear();
	selectLabel.push_back("anderes1"); selectLabel.push_back("anderes2"); selectLabel.push_back("anderes3"); selectLabel.push_back("anderes4"); selectLabel.push_back("anderes5");
	m_specificSelect[3].makeInactiveMats(m_matsForSelect4);
	m_specificSelect[3].Init(cursor, font, 5, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(3, 5, selectLabel);

	selectLabel.clear();
	selectLabel.push_back("anderes1"); selectLabel.push_back("anderes2"); selectLabel.push_back("anderes3"); selectLabel.push_back("anderes4"); selectLabel.push_back("anderes5"); selectLabel.push_back("anderes6");
	m_specificSelect[4].makeInactiveMats(m_matsForSelect5);
	m_specificSelect[4].Init(cursor, font, 6, CFloatRect(0.15, 0.f, 0.15, 0.9)); labelMaker(4, 6, selectLabel);

	m_mainSelect.SwitchOff();
	m_specificSelect[0].SwitchOff(); m_specificSelect[1].SwitchOff(); m_specificSelect[2].SwitchOff(); m_specificSelect[3].SwitchOff(); m_specificSelect[4].SwitchOff();

	initPlayer(cursor, font, zv);

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
	zv->AddOverlay(&m_specificSelect[4]);
	zv->AddOverlay(&m_confirm);
	zv->AddOverlay(&m_cancel);


}

void UI::labelMaker(int a,int b,std::vector<std::string> label)
{
	for (int i = 0; i < b; i++) {
		m_specificSelect[a].AddOption(label.at(i));
	}
}

void UI::initPlayer(CDeviceCursor* cursor, CWritingFont* font, CViewport* zv) {
	std::string derString;
	
	m_statistic.Init(cursor, font, CFloatRect(0.9,0, 0.1,0.1));
	m_statistic.SetLabel("Player");

	m_statsBack.Init(&m_matStats, CFloatRect(0.8,0.1,0.2,0.8));
	m_statsBack.SetLayer(0.98);
	m_statsBack.SwitchOff();

	m_res1.Init(cursor,font, CFloatRect(0,0,1,0.05));
	m_res1.SetInnerOn();
	m_res1.SetLayer(1);
	m_res1.SetLabel("Res1: " + std::to_string(m_playerStats->getRessource1()));

	m_res2.Init(cursor, font, CFloatRect(0, 0.1, 1, 0.05));
	m_res2.SetLabel("Res2: " + std::to_string(m_playerStats->getRessource2()));
	m_res2.SetInnerOn();
	m_res2.SetLayer(1);

	m_res3.Init(cursor, font, CFloatRect(0, 0.2, 1, 0.05));
	m_res3.SetLabel("Res3: " + std::to_string(m_playerStats->getRessource3()));
	m_res3.SetInnerOn();
	m_res3.SetLayer(1);

	m_wohnungen.Init(cursor, font, CFloatRect(0, 0.3, 1, 0.05));
	m_wohnungen.SetLabel("Wohnungen: " + std::to_string(m_playerStats->getWohnung()));
	m_wohnungen.SetInnerOn();
	m_wohnungen.SetLayer(1);


	m_statsBack.AddOverlay(&m_res1);
	m_statsBack.AddOverlay(&m_res2);
	m_statsBack.AddOverlay(&m_res3);
	m_statsBack.AddOverlay(&m_wohnungen);

	zv->AddOverlay(&m_statistic);
	zv->AddOverlay(&m_statsBack);

}
