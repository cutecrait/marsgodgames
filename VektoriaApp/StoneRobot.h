#pragma once
#include "RobotBase.h"

/// <summary>
/// Klasse von Roboter Typ Stone
/// </summary>
class StoneRobot : public RobotBase
{
public:

	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="startingnode">Startknoten</param>
	StoneRobot(Pathfinding::Node* startingnode = nullptr);

};

