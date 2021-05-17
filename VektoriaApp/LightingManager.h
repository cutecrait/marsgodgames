#pragma once

#include "Vektoria\root.h"
using namespace Vektoria;

class LightingManager
{
public:
	void Init(CScene* scene, CPlacement* cameraPlacement);
	void Tick(float fTimeDelta);
	// gets the time of day from 0 - 900
	// 0 = break of dawn
	// 600 = sundown
	// 899 = just before morning
	// a day lasts for about 15 mins = 900s
	float GetTime();
	void SetTime(float time);

private:
	const bool debug = true;
	bool recalc = false;
	float time = 0.0f;
	float timeScale = 1.0f;
	const float duskTime = 600.f;
	const float dayLength = 900.f;
	const float dawnFade = 20.f;
	const float duskFade = dawnFade;
	const float anglePerSecond = -PI / duskTime;

	CScene* scene;
	CLightParallel nightLight;
	CLightParallel sun;
	CPlacement sunPlacement;
	CHVector sunStartDirection = CHVector(-1.0f, 0.0f, 1.0f);
	CHVector sunAxis = CHVector(1.0f, 0.0f, 1.0f, 0.0f);
	CColor sunColor = CColor(1.0f, 0.9f, 0.9f);
	CColor nightColor = CColor(0.5f, 0.3f, 0.8f);

	void setSunDirection(CPlacement* p);
};

