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

	void gainConcrete(int i) { concrete += i; }
	void gainSteel(int i) { steel += i; }
	void gainWood(int i) { wood += i; }
	int getConcrete() { return concrete; }
	int getSteel() { return steel; }
	int getWood() { return wood; }


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

	int getWohnung() { return WohnungKapa; }
	void setWohnung(int i) { WohnungKapa += i; }
	void setUsedWohnungen(int i) { usedWohnungen += i; }
	int getUsedWohnungen() { return usedWohnungen; }

private:

	Player();

	int concrete;
	int steel;
	int wood;
	

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

	int WohnungKapa = 0;
	int usedWohnungen;

};

