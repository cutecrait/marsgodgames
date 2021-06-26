#pragma once
#include "RobotBase.h"

class StoneRobot : public RobotBase
{
public:

	StoneRobot(Pathfinding::Node* startingnode = nullptr);
	~StoneRobot();

};

