#include "LightingManager.h"
#include <iostream>

void LightingManager::Init(CScene* scene, CPlacement* cameraPlacement)
{
	this->scene = scene;
	sun.Init(sunStartDirection, sunColor);
	scene->SetLightAmbient(CColor(0.6f, 0.3f, 1.0f));
	scene->SetLightAmbient(0.3f);
	scene->SetSkyOn(cameraPlacement);
	scene->SetSkyCardinalDirection()
	scene->m_psceneweather->m_azmSky->MakeTextureDiffuse("textures//marssky.png");
	// scene->AddLightParallel(&sun);
	sunPlacement.Translate(sunStartDirection);

	timeScale = 30.0f; // DEBUG - makes a day pass in 30 seconds instead of 15 minutes
}

void LightingManager::Tick(float fTimeDelta)
{
	scene->SetSkyTimeOfDay(time / dayLength);

	recalc = false;
	float lightDelta = fTimeDelta * timeScale;
	time += lightDelta;
	if (time > dayLength)
	{
		SetTime(time - dayLength);
	}

	if (recalc || fTimeDelta > 1) // heavy lag occurred. re-calculate sun properties
	{
		recalc = true;
	}

	if (time < duskTime)
	{
		if (time < dawnFade)
		{
			float dawnProgress = time / dawnFade;
			CColor morning;
			// fade from gold to warm white
			morning.Interpol(CColor(1.0f, 1.0f, 0.3f), sunColor, dawnProgress);
			// fade from black (completed at 
			morning.Interpol(CColor(), morning, dawnProgress * 2);
		}
		else if (time < duskTime - duskFade)
		{
			sun.SetColor(sunColor);
		}
		else if (time > duskTime - duskFade)
		{
			// ramp strength down, fade color to red
		}

		if (recalc)
		{
			sunPlacement.Translate(sunStartDirection);
			sunPlacement.RotateDelta(sunAxis, time * anglePerSecond);
		}
		else
		{
			sunPlacement.RotateDelta(sunAxis, lightDelta * anglePerSecond);
		}
		setSunDirection(&sunPlacement);
	}
	else
	{
		sun.SetColor(CColor(0.0f, 0.0f, 0.0f));
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
	recalc = true;
	return;
}

void LightingManager::setSunDirection(CPlacement* p)
{
	CHVector direction = p->GetPos();
	direction.w = 0.f;
	sun.SetDirection(direction);
}
