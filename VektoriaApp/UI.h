#pragma once
#include "Vektoria\root.h"
#include "GuiSelect.h"
#include "Player.h"
using namespace Vektoria;
class UI
{
public:
	UI();
	~UI();

	void InitMaterial();
	void InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport*,Player*);
	void labelMaker(int,int, std::vector<std::string>);
	void initRessource();
	void initPlayer(CDeviceCursor*,CWritingFont*);
	CGuiButton* getStart() { return &m_start; }
	CGuiSelect* getMainSelect() { return &m_mainSelect; }
	CGuiSelect* getSpecificSelect(int i) { return &m_specificSelect[i]; }
	CGuiButton* getPlayer() {return &m_statistic; }
	COverlay* getStatistic() { return &m_statsBack; }
	CGuiElement* getWohnung() { return &m_wohnungen; }
	CGuiButton* getConfirm() { return &m_confirm; }
	void switchOnBuy(int,int,int);

	void updatePlayer();

	void InitToolTip();

	void tooltip(std::string headline, int res1, int res2, int res3, int anzahl, std::string whatHappens);

	

private:
	CMaterial m_matsForSelectMain[5];

	CMaterial m_matsForSelect1[3];
	CMaterial m_matsForSelect2[4];
	CMaterial m_matsForSelect3[4];
	CMaterial m_matsForSelect4[5];
	CMaterial m_matsForSelect5[6];
	CMaterial m_material;
	CWritingFont m_redFont;
	CMaterial m_matStats;
	CGuiButton m_start;
	CGuiSelect m_mainSelect;
	CGuiSelect m_specificSelect[4];
	CGuiButton m_statistic;
	CViewport* m_viewport;
	

	COverlay m_headline;
	CWriting m_headlineW;
	
	COverlay m_kosten1;
	CWriting m_kosten1W;

	COverlay m_kosten2;
	CWriting m_kosten2W;

	COverlay m_kosten3;
	CWriting m_kosten3W;

	CMaterial m_descMaterial;
	COverlay m_description;
	CWriting m_descriptionW1;
	CWriting m_descriptionW2;
	CWriting m_descriptionW3;
	CMaterial m_resMaterial;
public:
	COverlay m_statsBack;
	COverlay m_resBack;
	COverlay m_toolTipBackGround;
	CGuiElement m_res1;
	CGuiElement m_res1Minus;
	CGuiElement m_res2;
	CGuiElement m_res2Minus;
	CGuiElement m_res3;
	CGuiElement m_res3Minus;
	CGuiElement m_wohnungen;
	CGuiButton m_confirm;
	CGuiButton m_cancel;

	Player* m_playerStats;
	
};

