#pragma once
#include "popup.h"
class LabPopup :
    public popup
{
public:
    LabPopup();
    ~LabPopup();
    void Init(CDeviceCursor*, CMaterial*, CWritingFont*, CMaterial*);

    
    CGuiElement m_forschung2;
    CGuiButton m_forschung1B;
    COverlay m_mineUpgrade;
    CGuiButton m_mineUpgrade1B;
    CGuiButton m_mineUpgrade2B;
    CGuiButton m_mineUpgrade3B;

    COverlay m_buyOverlay;
    CGuiButton m_confirmB;
    CGuiButton m_cancelB;

private:
    COverlay m_forschung1;
   CWriting m_forschung1W;

   COverlay m_resOverlay;
   CWriting m_steelW;
   CWriting m_woodW;
   CWriting m_concreteW;
  
   CWriting m_forschung2W;

 
   COverlay m_mineUpgrade1;
   CWriting m_mineUpgrade1W;
   COverlay m_mineUpgrade2;
   CWriting m_mineUpgrade2W;
   COverlay m_mineUpgrade3;
   CWriting m_mineUpgrade3W;
  
};

