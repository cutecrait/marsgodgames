#include "BeispielForGameObject.h"

BeispielForGameObject::BeispielForGameObject()
{
	setModel("models\\Wassertank.obj");
	//this->setMaterial("textures\\green_image.jpg");
	this->getModel()->SetMaterial(this->getMaterial());
	
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
