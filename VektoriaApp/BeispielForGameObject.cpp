#include "BeispielForGameObject.h"

BeispielForGameObject::BeispielForGameObject()
{
	setModel("models\\kraftwerk.obj");
	this->setMaterial("textures\\green_image.jpg");
	this->getModel()->SetMaterial(this->getMaterial());
	ressources.Sauerstoff_per_Build = 100;
	ressources.Stein_per_Build = 100;
	ressources.Strom_per_Build = 100;
}

BeispielForGameObject::~BeispielForGameObject()
{
}

void BeispielForGameObject::Init()
{
	/*m_res1 = res1;
	m_res2 = res2;
	m_res3 = res3;
	*/
	
}
