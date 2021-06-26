#pragma once
#include "RobotBase.h"

class SteelRobot : public RobotBase
{
public:

	SteelRobot(Pathfinding::Node* startingnode = nullptr);
	~SteelRobot();

};

