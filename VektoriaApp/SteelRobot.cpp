#include "SteelRobot.h"

SteelRobot::SteelRobot(Pathfinding::Node* startingnode)
	: RobotBase(startingnode, 2.f, 1.f, "models\\roboter.obj", "textures\\roboter\\base_color.png", 0.4)
{
}

SteelRobot::~SteelRobot()
{
}
