#pragma once
#include "Vektoria\root.h"
#include "GuiSelect.h"

#include "RobotFactory.h"
#include "Apartment.h"
#include "ControlCenter.h"
#include "Well.h"
using namespace Vektoria;
class UI
{
public:
	UI();
	~UI();

	void InitMaterial();
	void InitMenu(CDeviceCursor* cursor, CWritingFont* font, CViewport*);
	void labelMaker(int,int, std::vector<std::string>);
	void initRessource(CWritingFont*);
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
	roboPopUp* getRobo(roboPopUp*);
	void InitToolTip();
	void levelOverlay(COverlay*, CWritingFont*, CDeviceCursor*);
	void tooltip(std::string headline, int res1, int res2, int res3, int anzahl, BuildingCategory);
	void updateWriting(std::string, CWriting*);
	void makeAMission(std::string, int);
	void makeAllMissions(float missionAnzahl,int currentLevel, std::string m1 = "", std::string m2= "", std::string m3 = "", std::string m4 = "", std::string m5 = "");
	void updateLevelUI(float anzahlMissGesamt, float anzahlAbgeschlossenerMiss, int welchesLevel);
	popup* getPopup(std::string );
private:
	CMaterial m_matsForSelectMain[5];

	//Tooltip-Mats
	CMaterial m_matsteel;
	CMaterial m_matconcrete;
	CMaterial m_matwood;


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


	CGuiElement m_Ressources;

	
	CWriting m_concreteW;
	CWriting m_concreteMinusW;

	
	CWriting m_steelW;
	CWriting m_steelMinusW;

	
	CWriting m_woodW;
	CWriting m_woodMinusW;

	
	CWriting m_levelW;
	CWriting m_missiW[5];
	COverlay m_missiStatus[5];
	COverlay m_wohnungen;
	CWriting m_wohnungenW;

	CGuiButton m_confirm;
	CGuiButton m_cancel;

	CWriting levelFortschrittW;


	roboPopUp m_roboPopUP;
	ApsPopup m_apsPopup;
	ControlCPopup m_CCpopup;
	wellPopup m_wellPopup;

	CGuiButton m_missionen;
	COverlay m_missionenBack;
	CViewport* m_viewport;
};

