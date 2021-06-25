#pragma once
#include "popup.h"
class LabPopup :
    public popup
{
public:
    LabPopup();
    ~LabPopup();
    void Init(CDeviceCursor*, CMaterial*, CWritingFont*, CMaterial*);

    void deaktivate();
    void activate();
    void buyOverlay(int);
    
    CGuiButton m_forschung1B;
    CGuiButton m_forschung2B;
    CGuiButton m_forschung3B;

    COverlay m_buyOverlay;
    CGuiButton m_confirmB;
    CGuiButton m_cancelB;
    

private:
   
   CWriting m_forschung1W;

   COverlay m_forschung1;
   COverlay m_forschung2;
   COverlay m_forschung3;
   CWriting m_forschung2W;

   
   CWriting m_forschung3W;

   COverlay m_resOverlay;
   CWriting m_steelW;
   CWriting m_woodW;
   CWriting m_concreteW;
  
   CWriting m_forschungenW1;
   CWriting m_forschungenW2;

 
   
  
};

