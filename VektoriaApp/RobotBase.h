#pragma once

#include "Vektoria\Root.h"
#include "StateController.h"
#include "SteeringController.h"
#include "GameObject.h"
#include "PathController.h"
#include "IPathSearchAlgorithm.h"

class RobotBase : GameObject
{
public:

	RobotBase(Pathfinding::Node* startingnode, float maximumvelocity, float maximumforce, float maximumrotation);
	~RobotBase();

	void Update(float timeDelta);

	Vektoria::CPlacement* GetPlacement();

	/// <summary>
	/// Gehe zu Knoten
	/// </summary>
	/// <param name="node">zu besuchender Knoten</param>
	/// <param name="repeat">Schleife</param>
	void SetPath(Pathfinding::Node* node, bool repeat = false);

protected:

	Vektoria::CPlacement* _placementRoot;
	Vektoria::CPlacement* _rotationPlacement;
	AI::StateController* _stateController;
	Movement::SteeringController* _steeringController;
	Pathfinding::PathController* _pathController;

	//TODO test only
	void CreateMesh();

};

