#pragma once
#include "Building.h"
#include "roboPopUp.h"
#include "Player.h"
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

		setModel(AssetManager::Models::RobotFactory);

		char* base = "textures\\RobotFactoryTex\\RobotFactoryTex_Base_Color.png";
		char* glow = "textures\\RobotFactoryTex\\RobotFactoryTex_Emissive.png";
		char* spec = "textures\\RobotFactoryTex\\RobotFactoryTex_Metallic.png";
		char* height = "textures\\RobotFactoryTex\\RobotFactoryTex_Height.png";
		char* bump = "textures\\RobotFactoryTex\\RobotFactoryTex_Roughness.png";

		this->setMaterial(bump, base, glow, spec, height);
		this->getModel()->SetMaterial(this->getMaterial());

		setAudio(&CAudioManager::Instance().Local_RobotFactory);
	}

	void OnClick() override {

		_steelRobotCount = 0;
		_concreteRobotCount = 0;
		_woodRobotCount = 0;
		_woodCost = 0;
		_steelCost = 0;
		_concreteCost = 0;
		onlyOneTime = true;
		erstesMal = false;
		thepopup->m_main.SwitchOn();
		thepopup->m_robo1AddW.PrintInt(_steelRobotCount);
		thepopup->m_robo2AddW.PrintInt(_concreteRobotCount);
		thepopup->m_robo3AddW.PrintInt(_woodRobotCount);
		resultArray[0] = 0;
		resultArray[1] = 0;
		resultArray[2] = 0;
	}
	int decision() override {
		calculateCost();
		if (thepopup->m_robo1Add.IsClicked()) {
			_steelRobotCount++;
			thepopup->m_robo1AddW.PrintInt(_steelRobotCount);
			resultArray[0] = _steelRobotCount;
			return 4;
		}
		if (thepopup->m_robo2Add.IsClicked()) {
			_concreteRobotCount++;
			thepopup->m_robo2AddW.PrintInt(_concreteRobotCount);
			resultArray[1] = _concreteRobotCount;
			return 4;
		}
		if (thepopup->m_robo3Add.IsClicked()) {
			_woodRobotCount++;
			thepopup->m_robo3AddW.PrintInt(_woodRobotCount);
			resultArray[2] = _woodRobotCount;
			return 4;
		}

		if (thepopup->confirm.IsClicked()) {
			if (erstesMal) {
				if (onlyOneTime) {
					if (enoughResource()) {
						thepopup->m_main.SwitchOff();

						Player::Instance().AddSteelRobot(resultArray[0]);
						Player::Instance().AddConcreteRobot(resultArray[1]);
						Player::Instance().AddWoodRobot(resultArray[2]);

						return 2;
					}
				}
			}

		}
		if (thepopup->cancel.IsClicked()) {
			if (erstesMal) {
				thepopup->m_main.SwitchOff();
				return 3;
			}
		}
		erstesMal = true;
		return 4;

	}
	bool isPopupFunctional() override {
		return true;
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



	void calculateCost()
	{
		//TODO robot buildcost als static in RobotBase (funktioniert nicht? -> RobotBase::getBuildCost())
		Resources res{ 15,15,15 };
		int count = _steelRobotCount + _concreteRobotCount + _woodRobotCount;

		_steelCost = res.Steel * count;
		_concreteCost = res.Concrete * count;
		_woodCost = res.Wood * count;

		thepopup->kosten1W.PrintInt(_steelCost);
		thepopup->kosten2W.PrintInt(_concreteCost);
		thepopup->kosten3W.PrintInt(_woodCost);
	}

	bool enoughResource() {
		if (_concreteCost <= Player::Instance().getConcrete() &&
			_steelCost <= Player::Instance().getSteel() &&
			_woodCost <= Player::Instance().getWood()) {
			onlyOneTime = false;
			Player::Instance().gainConcrete(-_concreteCost);
			Player::Instance().gainSteel(-_steelCost);
			Player::Instance().gainWood(-_woodCost);
			return true;
		}

		else
			return false;

	}
	int RobotFactory::getResult(int i) override {

		return resultArray[i];

	}
	bool hasPopup()override {
		return true;
	}

private:

	int _steelRobotCount = 0;
	int _concreteRobotCount = 0;
	int _woodRobotCount = 0;
	int _woodCost = 0;
	int _steelCost = 0;
	int _concreteCost = 0;
	bool onlyOneTime = true;
	roboPopUp* thepopup = NULL;

	int resultArray[3];

};