#pragma once
#include "Building.h"
#include "LabPopup.h"
class Laboratory :
    public Building
{
public:
    Laboratory() {
        PowerUse = 20;
        WaterUse = 2;
        NutrientUse = 0;

        Category = BuildingCategory::Living;

        setModel("models\\monkey.obj");
        // set material

        setAudio(&CAudioManager::Instance().Local_Laboratory);
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 40;
        cost.Concrete = 20;
        cost.Wood = 20;
        return cost;
    }
    
    void setPopup(popup* einPopup) override {
        thepopup = (LabPopup*)einPopup;
    }
    bool hasPopup()override {
        return true;
    }
    int decision() override {
        if (erstesMal) {
            if (thepopup->m_forschung1B.IsClicked() || thepopup->m_forschung2.IsClicked()) {
                thepopup->m_mineUpgrade.SwitchOn();
            }
            
            if (thepopup->m_mineUpgrade.IsOn()) {
                if (erstesmal1) {
                    if (thepopup->m_mineUpgrade1B.IsClicked()) {
                        thepopup->m_buyOverlay.SwitchOn();
                    }
                    if (thepopup->m_buyOverlay.IsOn()) {
                        if (erstesMal2) {
                            if (thepopup->m_cancelB.IsClicked()) {
                                thepopup->m_buyOverlay.SwitchOff();
                                 thepopup->m_mineUpgrade.SwitchOff();
                            }
                            else if (thepopup->m_confirmB.IsClicked()) {
                                thepopup->m_buyOverlay.SwitchOff();
                                thepopup->m_mineUpgrade.SwitchOff();
                            }
                        }
                        erstesMal2 = true;
                    }
                }
                erstesmal1 = true;
            }
            if (thepopup->m_abort.IsClicked()) {
                thepopup->m_main.SwitchOff();
            }
        }
        erstesMal = true;
       
        return 4;

    }

    bool isPopupOpen() override {

        if (thepopup != NULL) {
            if (thepopup->m_main.IsOn()) {
                return true;
            }
            else
                return false;

        }
        else
            return false;

    }
    void OnClick() override {
        erstesMal = false;
        erstesmal1 = false;
        erstesMal2 = false;
        //ersten 
       // thepopup->setInfo(PowerUse, WaterUse, NutrientUse, howMuch);
        thepopup->m_main.SwitchOn();
    }

private:
    LabPopup* thepopup = NULL;
    bool erstesmal1 = false;
    bool erstesMal2 = false;
};