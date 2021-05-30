#pragma once
#include "Vektoria\root.h"
#include "GuiSelect.h"

using namespace Vektoria;
class UI
{
public:
	UI();
	~UI();

	void InitMaterial();
	void InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport*);
	void labelMaker(int,int, std::vector<std::string>);
	void initRessource();
	void initPlayer(CDeviceCursor*,CWritingFont*);
	CGuiButton* getStart() { return &m_start; }
	CGuiSelect* getMainSelect() { return &m_mainSelect; }
	CGuiSelect* getSpecificSelect(int i) { return &m_specificSelect[i]; }
	CGuiButton* getPlayer() {return &m_statistic; }
	COverlay* getStatistic() { return &m_statsBack; }
	CWriting* getWohnung() { return &m_wohnungenW; }
	CGuiButton* getConfirm() { return &m_confirm; }
	void switchOnBuy(int,int,int);
	void buildMission(COverlay*, CWritingFont*);
	void updatePlayer();

	void InitToolTip();
	void levelOverlay(COverlay*, CWritingFont*, CDeviceCursor*);
	void tooltip(std::string headline, int res1, int res2, int res3, int anzahl, std::string whatHappens);
	void updateWriting(std::string, CWriting*);
	void makeAMission(std::string, int);
	void makeAllMissions(float missionAnzahl, std::string m1 = "", std::string m2= "", std::string m3 = "", std::string m4 = "", std::string m5 = "");
	void updateLevelUI(float anzahlMissGesamt, float anzahlAbgeschlossenerMiss, int welchesLevel);
private:
	CMaterial m_matsForSelectMain[5];

	//Tooltip-Mats
	CMaterial m_matstein;
	CMaterial m_matchrom;
	CMaterial m_matstahl;


	CMaterial m_matsForSelect1[3];
	CMaterial m_matsForSelect2[4];
	CMaterial m_matsForSelect3[4];
	CMaterial m_matsForSelect4[5];
	CMaterial m_matsForSelect5[6];
	CMaterial m_material;
	CWritingFont m_redFont;
	CMaterial m_matStats;
	CMaterial m_matRes;
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

	COverlay m_level;

	COverlay levelFortschritt;
	COverlay m_levelFortschritt;


	float laenge = 0.5;

	COverlay m_missi[5];
public:
	COverlay m_statsBack;
	COverlay m_resBack;
	COverlay m_toolTipBackGround;
	CGuiElement m_concrete;
	CGuiElement m_concreteMinus;
	CGuiElement m_steel;
	CGuiElement m_steelMinus;
	CGuiElement m_wood;
	CGuiElement m_woodMinus;

	CWriting m_levelW;
	CWriting m_missiW[5];
	COverlay m_missiStatus[5];
	COverlay m_wohnungen;
	CWriting m_wohnungenW;

	CGuiButton m_confirm;
	CGuiButton m_cancel;

	CWriting levelFortschrittW;
	
	CGuiButton m_missionen;
	COverlay m_missionenBack;
	
};

