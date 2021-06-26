#pragma once
#include "RobotBase.h"

/// <summary>
/// Klasse von Roboter Typ Concrete
/// </summary>
class ConcreteRobot : public RobotBase
{
public:

	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="startingnode">Startknoten</param>
	ConcreteRobot(Pathfinding::Node* startingnode = nullptr);

};
