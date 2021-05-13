#include "BeispielForGameObject.h"

BeispielForGameObject::BeispielForGameObject()
{
	setModel("models\\monkey.obj");
	getPlacement()->Translate(0, 0, 0);
	getPlacement()->AddGeo(getModel());
	
}

BeispielForGameObject::~BeispielForGameObject()
{
}

void BeispielForGameObject::Init(int res1, int res2, int res3)
{
	m_res1 = res1;
	m_res2 = res2;
	m_res3 = res3;
	
	
}
