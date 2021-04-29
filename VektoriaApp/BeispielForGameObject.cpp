#include "BeispielForGameObject.h"

BeispielForGameObject::BeispielForGameObject()
{
	setModel("textures\\monkey.obj");
	getPlacement()->Translate(0, 0, 0);
	getPlacement()->AddGeo(getModel());
}

BeispielForGameObject::~BeispielForGameObject()
{
}

void BeispielForGameObject::Init()
{
	
	
	
}
