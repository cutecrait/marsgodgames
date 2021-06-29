#pragma once
#include "popup.h"

class ControlCPopup :
    public popup
{
public:
    ControlCPopup();
    ~ControlCPopup();
    void Init(CDeviceCursor* cursor, CMaterial* mat1, CWritingFont* font1,CWritingFont*);
    void updatePopup();

private:
    COverlay m_wohnungen;
    CGuiElement m_wohnungenW; //evtl elemet dann kann man hovern
    CWriting m_wohnungenInsgesamt;
    CWriting m_usedWohnungen;
    CWriting m_usedWohnungenInt;

    COverlay m_strom;
    CGuiElement m_StromW;
    CWriting m_stromInsgesamt;
    CWriting m_usedStrom;
    CWriting m_usedStromInt;

    COverlay m_roboter;
    CGuiElement m_roboterW;
    CWriting m_roboterInsgesamt;
    CWritingFont* m_redFont;
    CWritingFont font;
    COverlay m_wasser;
    CGuiElement m_wasserW;
    CWriting m_wasserInsgesamt;
    CWriting m_usedWasser;
    CWriting m_usedWasserInt;
    
    COverlay m_food;
    CGuiElement m_foodW;
    CWriting m_foodInsgesamt;
    CWriting m_usedFood;
    CWriting m_usedFoodInt;

    //ich brauche Wohungsanzahl mit belegent plätzen
    //ich brauche strom / verbrauchter strom
    // ich brauche roboter (3verschiedene arten) Ressourcen?
    //foodfarm?
    // wasser-und verbrauch
    //

};

