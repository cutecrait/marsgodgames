#pragma once
#include "Building.h"
#include "FoodFarmPopup.h"

class FoodFarm :
    public Building
{
public:
    GameObject* linkedPlant = nullptr;

    FoodFarm() {
        PowerUse = 5;
        WaterUse = 5;
        NutrientUse = 1;
        howMuch = 30;

        Category = BuildingCategory::Farming;

        setModel(AssetManager::Models::FoodFarm);
        // set material
        char* base = "textures\\FoodFarmTex\\FoodFarmTex_Base_Color.png";
        char* glow = "textures\\FoodFarmTex\\FoodFarmTex_Emissive.png";
        char* spec = "textures\\FoodFarmTex\\FoodFarmTex_Metallic.png";
        char* height = "textures\\FoodFarmTex\\FoodFarmTex_Height.png";
        char* bump = "textures\\FoodFarmTex\\FoodFarmTex_Roughness.png";


        this->setMaterial(bump, base, glow, spec, height);
        this->getModel()->SetMaterial(this->getMaterial());
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
