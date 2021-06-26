#pragma once
#include "RobotBase.h"

/// <summary>
/// Klasse von Roboter Typ Wood
/// </summary>
class WoodRobot : public RobotBase
{
public:

	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="startingnode">Startknoten</param>
	WoodRobot(Pathfinding::Node* startingnode = nullptr);

};

