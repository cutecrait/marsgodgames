#pragma once
#include "Vektoria\root.h"
#include <string>

using namespace Vektoria;
using namespace std;

struct ManagedGeo {
	CGeo* geo = nullptr;
	bool loaded = false;
	string objPath;
};

class AssetManager
{
public:
	static AssetManager& Instance()
	{
		static AssetManager _instance;
		return _instance;
	};

	static enum class Models {
		None = 0,
		Apartment,
		ControlCenter,
		FoodFarm,
		Foundry,
		GravelPlant = 5,
		Hospital,
		Launchpad,
		Mine,
		NuclearPowerPlant,
		RobotFactory = 10,
		SolarPowerPlant,
		TreeFarm,
		Well,
		Robot = 14,
		Barrack = 15,
		Laboratory = 16,
		FoodPlant = 17,
		OxygenTank = 18
	};

	// string: folder path containing textures/, models/, ect. with trailing '\\'
	static bool Init(string);
	static CGeo* getModel(Models);

	static bool ready;
	static ManagedGeo geos[18];
	static string baseModelPath;
	static CFileWavefront fileWavefront;

private:
	// static class
	AssetManager() {};
};

