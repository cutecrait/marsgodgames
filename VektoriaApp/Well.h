#pragma once
#include "Building.h"
#include "wellPopup.h"
class Well :
    public Building
{
public:
    Well() {
        PowerUse = 10;
        WaterUse = 0; // vorher -60
        NutrientUse = 0;
        howMuch = 60;
        Category = BuildingCategory::Farming;

        setModel("models\\monkey.obj");
        // set material

        //setAudio(&CAudioManager::Instance().Local_Well);
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 50;
        cost.Concrete = 10;
        cost.Wood = 0;
        return cost;
    }
    void OnClick() override {
        erstesMal = false;
        //ersten 
        thepopup->setInfo(PowerUse, WaterUse, NutrientUse, howMuch);
        thepopup->m_main.SwitchOn();
    }
    void updatePlayer() override {

        Player::Instance().setWater(howMuch);

    }
    void setPopup(popup* einPopup) override {
        thepopup = (wellPopup*)einPopup;
    }
    bool hasPopup()override {
        return true;
    }
    int decision() override {
        if (thepopup->m_abort.IsClicked()) {
            if (erstesMal) {
                thepopup->m_main.SwitchOff();
            }
            return 2;
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


private:
    wellPopup* thepopup = NULL;
};
