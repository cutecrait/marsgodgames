#pragma once
#include "popup.h"


class BarrackPopUp :
    public popup
{
public:
    BarrackPopUp();
    ~BarrackPopUp();
    void Init(CDeviceCursor* cursor, CMaterial*, CWritingFont*);
    void setInfo(int powerUse, int waterUse, int NutrientUse, int howMuch) override;
private:





    COverlay m_info1;
    CWriting m_info1W;

    COverlay m_infotext;
    CWriting m_infotextW;

    CWriting m_infotext1;
    CWriting m_infotext2;

};


