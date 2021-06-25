#include "AssetManager.h"

ManagedGeo AssetManager::geos[18];
string AssetManager::baseModelPath = "";
CFileWavefront AssetManager::fileWavefront;
bool AssetManager::ready = false;

bool AssetManager::Init(string baseAssetPath)
{
	baseModelPath = baseAssetPath + "models";

	geos[(int)Models::Apartment].objPath = "\\Apartment.obj";
	geos[(int)Models::ControlCenter].objPath = "\\controlcenter.obj";
	geos[(int)Models::FoodFarm].objPath = "\\FoodFarm.obj";
	geos[(int)Models::FoodPlant].objPath = "\\Factory.obj";
	geos[(int)Models::Foundry].objPath = "\\Foundry.obj";
	geos[(int)Models::GravelPlant].objPath = "\\foerderband+stein.obj";
	geos[(int)Models::Hospital].objPath = "\\Hospital.obj";
	geos[(int)Models::Launchpad].objPath = "\\launchpad.obj";
	geos[(int)Models::Mine].objPath = "\\felshaufen.obj";
	geos[(int)Models::NuclearPowerPlant].objPath = "\\Kraftwerk.obj";
	geos[(int)Models::RobotFactory].objPath = "\\RobotFactory.obj";
	geos[(int)Models::SolarPowerPlant].objPath = "\\monkey.obj";
	geos[(int)Models::TreeFarm].objPath = "\\TreeFarm.obj";
	geos[(int)Models::Well].objPath = "\\Wassertank.obj";
	geos[(int)Models::Robot].objPath = "\\roboter.obj";
	geos[(int)Models::Barrack].objPath = "\\Baracke.obj";
	geos[(int)Models::Laboratory].objPath = "\\Laboratory.obj";

	ready = true;
	return true;
}

CGeo* AssetManager::getModel(Models m)
{
	if (!ready) AssetManager::Init("");

	ManagedGeo* mGeo = &geos[(int)m];
	if (!mGeo->loaded)
	{
		string loadPath = baseModelPath + mGeo->objPath;
		mGeo->geo = fileWavefront.LoadGeo(&loadPath[0], true);
		mGeo->loaded = true;
	}
	return mGeo->geo;
}
