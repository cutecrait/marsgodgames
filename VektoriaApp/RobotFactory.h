#pragma once
#include "Building.h"
#include "roboPopUp.h"
#include "testRobo.h"
class RobotFactory :
    public Building
{
public:
    RobotFactory() {
        PowerUse = 5;
        WaterUse = 0;
        NutrientUse = 0;
        
        Category = BuildingCategory::Industry;
        setModel("models\\monkey.obj");
        // set model
        // set material
    }
    
   void OnClick() override {
     //  thepopup = (roboPopUp*) m_robopopup;
         robo1 = 0;
        robo2 = 0;
        robo3 = 0;
        steel_robo1 = 10;
        wood_robo1 = 5;
        stone_robo1 = 3;
        steel_robo2 = 20;
        wood_robo2 = 3;
        stone_robo2 = 0;
        steel_robo3 = 15;
        wood_robo3 = 5;
        stone_robo3 = 10;
        kostenWood = 0;
        kostenSteel = 0;
        kostenConcrete = 0;
        onlyOneTime = true;
      
       thepopup->m_main.SwitchOn();
      
    }
   bool decision() override {
         calculateCost();
       if (thepopup->m_robo1Add.IsClicked()) {
           robo1++;
           thepopup->m_robo1AddW.PrintInt(robo1);
           return true;
         }
       if (thepopup->m_robo2Add.IsClicked()) {
           robo2++;
           thepopup->m_robo2AddW.PrintInt(robo2);
           return true;
       }
       if (thepopup->m_robo3Add.IsClicked()) {
           robo3++;
           thepopup->m_robo3AddW.PrintInt(robo3);
           return true;
       }
    
       if (thepopup->confirm.IsClicked()) {
           if (onlyOneTime) {
               if (enoughResource()) {
                   thepopup->m_main.SwitchOff();
                   thepopup->confirm.SwitchOff();

               }
           }
           return false;
       }
       if (thepopup->cancel.IsClicked()) {
           thepopup->m_main.SwitchOff();
           return false;
       }
       return true;
   }
   void setPopup(popup* einPopup) override {
       thepopup = (roboPopUp*)einPopup;
   }
    Resources getBuildCost() {
        Resources cost;
        cost.Steel = 20;
        cost.Concrete = 5;
        cost.Wood = 0;
        return cost;
    }

   

    void calculateCost() {
      
        kostenSteel = Robo1.getRessources().Steel * robo1 + steel_robo2 * robo2 +steel_robo3 * robo3;
        thepopup->kosten1W.PrintInt(kostenSteel);
        kostenWood = Robo1.getRessources().Wood * robo1 + wood_robo2 * robo2 + wood_robo3 * robo3;
        thepopup->kosten2W.PrintInt(kostenWood);
        kostenConcrete = Robo1.getRessources().Concrete * robo1 + stone_robo2 * robo2 + stone_robo3 * robo3;
        thepopup->kosten3W.PrintInt(kostenConcrete);


    }
    bool enoughResource() {
        if (kostenConcrete <= Player::Instance().getConcrete() &&
            kostenSteel <= Player::Instance().getSteel() &&
            kostenWood <= Player::Instance().getWood()) {
            onlyOneTime = false;
            Player::Instance().gainConcrete(-kostenConcrete);
            Player::Instance().gainSteel(-kostenSteel);
            Player::Instance().gainWood(-kostenWood);
            return true;
        }
           
        else
            return false;

   }
private:
    testRobo Robo1;
    int robo1 = 0;
    int robo2 = 0;
    int robo3 = 0;
    int steel_robo1 = 10;
    int wood_robo1 = 5;
    int stone_robo1 = 3;
    int steel_robo2 = 20;
    int wood_robo2 = 3;
    int stone_robo2 = 0;
    int steel_robo3 = 15;
    int wood_robo3=5;
    int stone_robo3=10;
    int kostenWood = 0;
    int kostenSteel = 0;
    int kostenConcrete = 0;
    bool onlyOneTime = true;
    roboPopUp* thepopup;
    
};