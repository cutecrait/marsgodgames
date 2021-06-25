#include "LightingManager.h"
#include <cmath>
//#include <iostream>

void LightingManager::Init(CScene* scene, CPlacement* cameraPlacement, CViewport* v)
{
	viewport = v;
	this->scene = scene;
	nightLight.Init(CHVector(-0.5f, 1.0f, 0.0f), nightColor);
	scene->SetSkyOn(cameraPlacement);
	scene->SetSkyCardinalDirection(-THREEQUARTERPI); // south is -X-Z, which is behind the camera
	scene->m_psceneweather->m_azmSky->MakeTextureDiffuse("textures//marssky.png");
	scene->SetSkyTimeOfDay(0.3f);
	//scene->SetLightAmbientBySky();

	scene->SetSkyShadowResolution(10000, 10000);

	viewport->SetBloomOn();
	viewport->SetBloomDepthDecay(1.0f);
	viewport->SetBloomOff();
	
	timeScale = 20.0f; // DEBUG - makes a day pass in 30 seconds instead of 15 minutes
}

void LightingManager::Tick(float fTimeDelta)
{
	float lightDelta = fTimeDelta * timeScale;
	time += lightDelta;
	
	//ULDebug(std::to_string(time).c_str());

	if (time > dayLength)
	{
		SetTime(time - dayLength);
	}

	auto skyTime = 0.0f + time / (dayLength); // skytime is from 0.75(dawn) to 1.25(dusk)
	scene->SetSkyTimeOfDay(skyTime);

	if (time < duskStart || time > dawnEnd) // daytime
	{
		viewport->SetBloomOff();
	}
	else if (time >= dawnStart && time <= dawnEnd) // dawn
	{
		float dawnProgress = (time - dawnStart) / (dawnEnd - dawnStart);

		CColor fadeColor;
		// see https://www.wolframalpha.com/input/?i=y%28x%29+%3D+1+-+%28abs%28%28x-0.5%29*2%29%29%5E2 for a graphical representation
		fadeColor.Interpol(CColor(), dawnAmbientColor, 1.f - pow(abs((dawnProgress - 0.5f)*2), 2));
		scene->SetLightAmbient(fadeColor);
	}
	else if (time > duskEnd && time < dawnStart) // night
	{
		//viewport->SetBloomOn();
	}
	else if (time >= duskStart && time <= duskEnd) // dusk
	{
		float dawnProgress = (time - duskStart) / (duskEnd - duskStart);

		CColor fadeColor;
		fadeColor.Interpol(CColor(), duskAmbientColor, 1.f - pow(abs((dawnProgress - 0.5f) * 2), 2));
		scene->SetLightAmbient(fadeColor);
	}
}

float LightingManager::GetTime()
{
	return time;
}

void LightingManager::SetTime(float newTime)
{
	while (newTime > 900.f)
	{
		newTime -= 900.f;
	}
	time = newTime;
	return;
}
