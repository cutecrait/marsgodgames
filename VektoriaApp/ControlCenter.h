#pragma once
#include "Building.h"
#include "ControlCPopup.h"
class ControlCenter :
    public Building
{
public:
    ControlCenter() {
        PowerUse = 0;
        WaterUse = 0;
        NutrientUse = 0;

        Category = BuildingCategory::None;

        setModel(AssetManager::Models::ControlCenter);
        //setModel("models\\controlcenter.obj");
        this->setMaterial("textures\\controlcenter\\base_color.png");
        this->getModel()->SetMaterial(this->getMaterial());
        // set material
        
        setAudio(&CAudioManager::Instance().Local_ControlCenter);

    }
    void OnClick() override {
        erstesMal = false;
        thepopup->updatePopup();
        thepopup->m_main.SwitchOn();

    }
    void setPopup(popup* einPopup) override {
        thepopup = (ControlCPopup*)einPopup;
    }

    bool hasPopup()override {
        return true;
    }
    int decision() override {
        if (thepopup->m_abort.IsClicked()) {
            if (erstesMal) {
                thepopup->m_main.SwitchOff();
                return 2;
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
  

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 0;
        cost.Concrete = 0;
        cost.Wood = 0;
        return cost;
    }
private:
    ControlCPopup* thepopup = NULL;
};