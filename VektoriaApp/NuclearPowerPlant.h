#pragma once
#include "Building.h"
#include "NuclearPopup.h"
class NuclearPowerPlant :
    public Building
{
public:
    NuclearPowerPlant() {
        PowerUse = 0;
        WaterUse = 5;
        NutrientUse = 0;
        howMuch = 240;
        Category = BuildingCategory::Industry;

        setModel(AssetManager::Models::NuclearPowerPlant);

        char* base = "textures\\KraftwerkTex\\Base_ani.png";
        char* glow = "textures\\KraftwerkTex\\Emissive_ani.png";
        char* spec = "textures\\KraftwerkTex\\Ani\\Metallic_ani.tif";
        char* height = "textures\\KraftwerkTex\\Ani\\Height_ani.tif";
        char* bump = "textures\\KraftwerkTex\\Ani\\Roughness_ani.tif";


        this->setMaterial(bump, base, glow, spec, height, 3, 5, 5);
        this->getModel()->SetMaterial(this->getMaterial());

        this->setAudio(&CAudioManager::Instance().Local_NuclearPowerPlant);
    }

    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 120;
        cost.Concrete = 180;
        cost.Wood = 40;
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
        thepopup = (NuclearPopup*)einPopup;
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
    NuclearPopup* thepopup = NULL;
};