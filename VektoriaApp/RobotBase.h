#pragma once

#include "Vektoria\Root.h"
#include "StateManager.h"
#include "SteeringManager.h"

class RobotBase
{
public:

	RobotBase(Vektoria::CPlacement* placement, float maximumVelocity, float rotationSpeed);
	~RobotBase();

	void Update(float timeDelta);

	Vektoria::CPlacement* GetPlacement();

	virtual void SetStates() = 0;

protected:

	Vektoria::CPlacement* _placementRoot;
	AI::StateManager* _stateManager;
	Movement::SteeringManager* _steeringManager;

	void CreateMesh(); //TODO nur Test

};

