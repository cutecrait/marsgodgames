#pragma once
#include "RobotBase.h"

class ConcreteRobot : public RobotBase
{
public:

	ConcreteRobot(Pathfinding::Node* startingnode = nullptr);
	~ConcreteRobot();

};
