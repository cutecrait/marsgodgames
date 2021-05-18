#pragma once

#include "Vektoria\Root.h"
#include "StateManager.h"
#include "SteeringManager.h"

class RobotBase
{
public:

	RobotBase(float maximumVelocity, float rotationSpeed);
	~RobotBase();

	void Update(float timeDelta);

	Vektoria::CPlacement* GetPlacement();

	void SetStates(); //TODO abstract? (wanted to be used to set state runtime - with parameters)

protected:

	Vektoria::CPlacement* _placementRoot;
	AI::StateManager* _stateManager;
	Movement::SteeringManager* _steeringManager;

	//TODO test only --> von GameObject erben
	Vektoria::CGeo* _model;
	Vektoria::CFileWavefront _modelPath;
	void CreateMesh();

};

