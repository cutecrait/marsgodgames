#pragma once
#include "Building.h"
#include "FoodFarmPopup.h"

class FoodFarm :
    public Building
{
public:
    FoodFarm() {
        PowerUse = 5;
        WaterUse = 5;
        NutrientUse = 1;
        howMuch = 30;

        Category = BuildingCategory::Farming;

        setModel("models\\monkey.obj");
        // set material
    }
   

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 30;
        cost.Concrete = 40;
        cost.Wood = 10;
        return cost;
    }

    void OnClick() override {
        erstesMal = false;
        //ersten 
        thepopup->setInfo(PowerUse, WaterUse, NutrientUse, howMuch);
        thepopup->m_main.SwitchOn();
    }

    void updatePlayer() override {

        Player::Instance().setFood(howMuch);

    }
    void setPopup(popup* einPopup) override {
        thepopup = (FoodFarmPopup*)einPopup;
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
    FoodFarmPopup* thepopup = NULL;
};
