#pragma once
#include "RobotBase.h"

class MiningRobot : public RobotBase
{
public:

	MiningRobot(Pathfinding::Node* startingnode = nullptr);
	~MiningRobot();

};

