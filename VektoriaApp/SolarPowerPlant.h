#pragma once
#include "Building.h"
#include "SolarPopup.h"
class SolarPowerPlant :
    public Building
{
public:
    SolarPowerPlant() {
        PowerUse = -0;
        WaterUse = 0;
        NutrientUse = 0;
        howMuch = 80;
        Category = BuildingCategory::Industry;

        setModel(AssetManager::Models::SolarPowerPlant);
        //this->getModel()->m_pmaterial->LoadPreset("Concrete");
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
        //kann man auch in addnewbuilding reinbringen
        Player::Instance().setPower(howMuch);

    }
    void setPopup(popup* einPopup) override {
        thepopup = (SolarPopup*)einPopup;
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
    SolarPopup* thepopup = NULL;
};