#pragma once
#include "Building.h"
#include "BarrackPopUp.h"

class Barrack :
    public Building
{
public:
    Barrack() {
        PowerUse = 1;
        WaterUse = 1;
        NutrientUse = 4;
        howMuch = 10;
        Category = BuildingCategory::Living;

        setModel("models\\Baracke.obj");
        this->setMaterial("textures\\BarackeTex.png");
        this->getModel()->SetMaterial(this->getMaterial());

    }

    void OnClick() override {
        erstesMal = false;
        //ersten 
        thepopup->setInfo(PowerUse, WaterUse, NutrientUse, howMuch);
        thepopup->m_main.SwitchOn();
    }
    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 10;
        cost.Concrete = 10;
        cost.Wood = 20;
        return cost;
    }
    void updatePlayer() override {

        Player::Instance().setWohnung(howMuch);

    }
    void setPopup(popup* einPopup) override {
        thepopup = (BarrackPopUp*)einPopup;
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
    BarrackPopUp* thepopup = NULL;

};

