#pragma once

#include "Action.h"
#include "Vektoria\Root.h"
#include <vector>
#include "SteeringController.h"
#include "Node.h"
#include "PathController.h"

namespace AI
{
	/// <summary>
	/// Aktion zur Pfadverfolgung
	/// </summary>
	class FollowPathAction :
		public Action
	{
	public:

		/// <summary>
		/// True, wenn Ende des Pfads erreicht, ansonsten False (Immer False, wenn Pfad ohne Ende)
		/// </summary>
		bool HasReachedEnd;

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="steeringcontroller">Verbindung zur Steuerung der Bewegung</param>
		/// <param name="pathcontroller">Verbindung zum PathController</param>
		/// <param name="stopDistance">Haltedistanz zum Ziel</param>
		FollowPathAction(Movement::SteeringController* steeringcontroller, Pathfinding::PathController* pathcontroller, float stopDistance);

		/// <summary>
		/// Bewegt zu Knoten
		/// </summary>
		virtual void Act() override;

	protected:
		/// <summary>
		/// Verbindung zur Steuerung der Bewegung
		/// </summary>
		Movement::SteeringController* _steeringController;

		/// <summary>
		/// Verbindung zum PathController
		/// </summary>
		Pathfinding::PathController* _pathController;

		/// <summary>
		/// Haltedistanz zum Ziel
		/// </summary>
		float _stopDistance;
	};
}
