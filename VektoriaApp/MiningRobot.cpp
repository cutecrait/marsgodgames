#include "MiningRobot.h"

MiningRobot::MiningRobot(Pathfinding::Node* startingnode)
	: RobotBase(startingnode, 2.f, 1.f, "models\\Rover.obj", 0.01)
{
}

MiningRobot::~MiningRobot()
{
}
