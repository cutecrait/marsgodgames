#include "StoneRobot.h"

StoneRobot::StoneRobot(Pathfinding::Node* startingnode)
	: RobotBase(startingnode, 2.f, 1.f, "models\\roboter.obj", "textures\\roboter\\base_color.png", 1)
{
}

StoneRobot::~StoneRobot()
{
}
