#include "Apartment.h"

Apartment::Apartment()
{

	setModel("models\\Barrack.obj");
	this->getModel()->m_pmaterial->LoadPreset("Concrete");
}

GameObject::Resources Apartment::getBuildCost()
{
	Resources cost;
	cost.Steel = 180;
	cost.Concrete = 300;
	return cost;
}
