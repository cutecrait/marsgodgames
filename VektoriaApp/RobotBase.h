#pragma once

#include "Vektoria\Root.h"
#include "StateManager.h"

class RobotBase
{
public:

	RobotBase();
	~RobotBase();

	void Update(float timeDelta);

	Vektoria::CPlacement* GetPlacement();

	virtual void SetStates() = 0;

protected:

	Vektoria::CPlacement* _placementRoot;
	AI::StateManager* _stateManager;

	void CreateMesh(); //TODO Rename?

};

