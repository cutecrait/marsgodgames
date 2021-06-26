#pragma once

class Player
{
public:

	/// <summary>
	/// Singleton - gibt Instanz zurück
	/// </summary>
	/// <returns>Instanz</returns>
	static Player& Instance()
	{
		static Player _instance;
		return _instance;
	};

	void initPlayer(int, int, int);

	void gainConcrete(int i) {concrete += i;}
	void gainSteel(int i) { steel += i; }
	void gainWood(int i) { wood += i; }
	int getConcrete() { return concrete; }
	int getSteel() { return steel; }
	int getWood() { return wood; }

	
	void setConcrete(int x) {
		concrete = 0;
		
	}
	void setSteel(int x) { steel = 0; }
	void setWood(int x) { wood = 0; }

	void setConcretePM(int i) { concretePMinute += i;}
	void setSteelPM(int i) { steelPMinute += i; }
	void setWoodPM(int i) { woodPMinute += i; }
	int getConcretePM() { return concretePMinute; }
	int getSteelPM() { return steelPMinute; }
	int getWoodPM() { return woodPMinute; }

	void useWater(int x) { usedWater += x; }
	void usePower(int x) { usedPower += x; }
	void useFood(int x) { usedFood += x; }

	int getUseWater() { return usedWater; }
	int getUsePower() { return usedPower; }
	int getUseFood() { return usedFood; }

	void setWater(int x) { water += x; }
	void setPower(int x) { power += x; }
	void setFood(int x) { food += x; }

	int getWater() { return water; }
	int getPower() { return power; }
	int getFood() { return food; }

	void setZufriedenheit1(int);
	void setZufriedenheit2(int);
	void setZufriedenheit3(int);
	int getZufriedenheit1();
	int getZufriedenheit2();
	int getZufriedenheit3();

	void setRobots(int x) { robots += x; }
	int getRobots() { return robots; }

	void AddConcreteRobot(int count = 1);
	void AddStoneRobot(int count = 1);
	void AddSteelRobot(int count = 1);
	int GetConcreteRobot();
	int GetStoneRobot();
	int GetSteelRobot();

	int getWohnung() { return WohnungKapa; }
	void setWohnung(int i) { WohnungKapa += i; }
	void setUsedWohnungen(int i) { usedWohnungen += i; }
	int getUsedWohnungen() { return usedWohnungen; }

private:

	Player();

	int concrete;
	int steel;
	int wood;
	int concretePMinute;
	int steelPMinute;
	int woodPMinute;

	int water;
	int power;
	int food;

	int usedWater;
	int usedPower;
	int usedFood;

	int zufriedenheit1;
	int zufriedenheit2;
	int zufriedenheit3;

	int robots;
	int _concreteRobots = 0;
	int _stoneRobots = 0;
	int _steelRobots = 0;

	int WohnungKapa = 0;
	int usedWohnungen;


};

