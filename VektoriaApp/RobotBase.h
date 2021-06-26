#pragma once

#include "Vektoria\Root.h"
#include "StateController.h"
#include "SteeringController.h"
#include "GameObject.h"
#include "PathController.h"
#include "IPathSearchAlgorithm.h"

/// <summary>
/// Basis-Klasse für Roboter
/// </summary>
class RobotBase : GameObject
{
public:

	//Konstuktor in protected -> Klasse abstrakt

	/// <summary>
	/// Aktualisiert Roboter
	/// </summary>
	/// <param name="timeDelta">TimeDelta</param>
	void Update(float timeDelta);

	/// <summary>
	/// Gibt Placement zurück
	/// </summary>
	/// <returns>Placement</returns>
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
	/// <param name="texture">Modeltextur</param>
	/// <param name="scale">Modelgröße - Default = 1</param>
	RobotBase(Pathfinding::Node* startingnode, float maximumvelocity, float maximumforce, char* model, char* texture, float scale = 1);

	/// <summary>
	/// Placement
	/// </summary>
	Vektoria::CPlacement* _placementRoot;
	/// <summary>
	/// Rotationsplacement für Model
	/// </summary>
	Vektoria::CPlacement* _rotationPlacement;
	/// <summary>
	/// AI-Klasse
	/// </summary>
	AI::StateController* _stateController;
	/// <summary>
	/// Steuerungsklasse
	/// </summary>
	Movement::SteeringController* _steeringController;
	/// <summary>
	/// Pfadfindungsklasse
	/// </summary>
	Pathfinding::PathController* _pathController;

};

