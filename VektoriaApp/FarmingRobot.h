#pragma once
#include "RobotBase.h"

class FarmingRobot : public RobotBase
{
public:

	FarmingRobot(Pathfinding::Node* startingnode = nullptr);
	~FarmingRobot();

};

