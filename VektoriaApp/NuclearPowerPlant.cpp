#include "NuclearPowerPlant.h"

NuclearPowerPlant::NuclearPowerPlant()
{
	power = 80000;
	setModel("models\\kraftwerk1.obj");
	this->getModel()->m_pmaterial->LoadPreset("Concrete");
}

GameObject::Resources NuclearPowerPlant::getBuildCost()
{
	Resources cost;
	cost.Steel = 180;
	cost.Concrete = 300;
	return cost;
}
