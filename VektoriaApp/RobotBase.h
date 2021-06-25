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

	//Konstuktor in protected -> Klasse abstrakt
	~RobotBase();

	void Update(float timeDelta);

	Vektoria::CPlacement* GetPlacement();

	/// <summary>
	/// Setze zu Knoten
	/// </summary>
	/// <param name="node">Knoten</param>
	void SetNode(Pathfinding::Node* node);
	/// <summary>
	/// Gehe zu Knoten
	/// </summary>
	/// <param name="node">zu besuchender Knoten</param>
	/// <param name="repeat">Schleife</param>
	void SetPath(Pathfinding::Node* node, bool repeat = false);

protected:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="startingnode">Startknoten für Pfadfindung</param>
	/// <param name="maximumvelocity">maximale Geschwindigkeit</param>
	/// <param name="maximumforce">maximale Kraft</param>
	/// <param name="model">Model</param>
	/// <param name="scale">Modelgröße - Default = 1</param>
	RobotBase(Pathfinding::Node* startingnode, float maximumvelocity, float maximumforce, char* model, float scale = 1);

	Vektoria::CPlacement* _placementRoot;
	Vektoria::CPlacement* _rotationPlacement;
	AI::StateController* _stateController;
	Movement::SteeringController* _steeringController;
	Pathfinding::PathController* _pathController;

};

