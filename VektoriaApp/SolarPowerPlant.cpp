#include "SolarPowerPlant.h"

SolarPowerPlant::SolarPowerPlant()
{
	power = 30000;
}

GameObject::Resources SolarPowerPlant::getBuildCost()
{
	Resources cost;
	cost.Steel = 80;
	cost.Concrete = 40;
	return cost;
}
