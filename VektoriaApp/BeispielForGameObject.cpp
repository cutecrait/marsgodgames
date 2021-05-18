#include "BeispielForGameObject.h"

BeispielForGameObject::BeispielForGameObject()
{
	setModel("models\\monkey.obj");
	setMaterial("");
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
