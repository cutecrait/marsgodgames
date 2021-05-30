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

	void setZufriedenheit1(int);
	void setZufriedenheit2(int);
	void setZufriedenheit3(int);
	int getZufriedenheit1();
	int getZufriedenheit2();
	int getZufriedenheit3();

	int getWohnung() { return WohnungKapa; }
	void setWohnung(int i) { WohnungKapa += i; }

private:

	Player();

	int concrete;
	int steel;
	int wood;

	int zufriedenheit1;
	int zufriedenheit2;
	int zufriedenheit3;

	int WohnungKapa = 0;
};

