#pragma once
#include "Building.h"
#include "ApsPopup.h"

class Apartment :
    public Building
{
public:
    Apartment() {
        PowerUse = 1;
        WaterUse = 1;
        NutrientUse = 4;
       
        Category = BuildingCategory::Living;

        setModel("models\\Kraftwerk.obj");
        this->setMaterial("textures\\KraftwerkTex.png");
        this->getModel()->SetMaterial(this->getMaterial());
      
    }
   
    void OnClick() override {
        erstesMal = false;
        thepopup->m_main.SwitchOn();
    }
    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 10;
        cost.Concrete = 10;
        cost.Wood = 20;
        return cost;
    }
    void setPopup(popup* einPopup) override {
        thepopup = (ApsPopup*)einPopup;
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
    ApsPopup* thepopup = NULL;
};

