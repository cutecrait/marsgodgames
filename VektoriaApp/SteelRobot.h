#pragma once
#include "RobotBase.h"

/// <summary>
/// Klasse von Roboter Typ Steel
/// </summary>
class SteelRobot : public RobotBase
{
public:

	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="startingnode">Startknoten</param>
	SteelRobot(Pathfinding::Node* startingnode = nullptr);

};

