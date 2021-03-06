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

        setModel(AssetManager::Models::Laboratory);

        char* base = "textures\\LaboratoryTex\\Base_ani.png";
        char* glow = "textures\\LaboratoryTex\\Emissive_ani.png";
        char* spec = "textures\\LaboratoryTex\\Metallic_ani.png";
        char* bump = "textures\\LaboratoryTex\\Roughness_ani.png";


        this->setMaterial(base, bump, glow, spec, 3, 5, 6);
        this->getModel()->SetMaterial(this->getMaterial());

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
            if (thepopup->m_forschung1B.IsClicked()) {
                thepopup->m_buyOverlay.SwitchOn();
                thepopup->buyOverlay(1);
                thepopup->deaktivate();
            }
            else if (thepopup->m_forschung2B.IsClicked()) {
                thepopup->m_buyOverlay.SwitchOn();
                thepopup->buyOverlay(2);
                thepopup->deaktivate();
            }
            else if (thepopup->m_forschung3B.IsClicked()) {
                thepopup->m_buyOverlay.SwitchOn();
                thepopup->buyOverlay(3);
                thepopup->deaktivate();
            }
            if (thepopup->m_buyOverlay.IsOn()) {
                if (erstesmal1) {
                    if (erstesMal2) {
                        if (thepopup->m_cancelB.IsClicked()) {
                            thepopup->m_buyOverlay.SwitchOff();
                            thepopup->activate();
                            thepopup->m_main.SwitchOff();
                            }
                        else if (thepopup->m_confirmB.IsClicked()) {
                            thepopup->m_buyOverlay.SwitchOff();     
                            thepopup->activate();
                            thepopup->m_main.SwitchOff();
                            }                       
                        }
                        erstesMal2 = true;
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