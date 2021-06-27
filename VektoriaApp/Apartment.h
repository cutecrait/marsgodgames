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
        howMuch = 20;
        Category = BuildingCategory::Living;

        //setModel("models\\Apartment.obj");
        setModel(AssetManager::Models::Apartment);

        char* base = "textures\\ApartmentTex\\ApartmentTex_Base_Color.png";
        char* glow = "textures\\ApartmentTex\\ApartmentTex_Emissive.png";
        char* spec = "textures\\ApartmentTex\\ApartmentTex_Metallic.png";
        char* height = "textures\\ApartmentTex\\ApartmentTex_Height.png";
        char* bump = "textures\\ApartmentTex\\ApartmentTex_Roughness.png";


        this->setMaterial(bump, base, glow, spec, height);
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

