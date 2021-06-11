#pragma once
#include "popup.h"


class ApsPopup :
    public popup
{
public:
    ApsPopup();
    ~ApsPopup();
    void Init(CDeviceCursor* cursor, CMaterial*, CWritingFont*);

private:
   

 
    

    COverlay m_info1;
    CWriting m_info1W;

    COverlay m_infotext;
    CWriting m_infotextW;

    CWriting m_infotext1;
    CWriting m_infotext2;
    
};

