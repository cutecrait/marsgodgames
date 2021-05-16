#pragma once

#include "Action.h"
#include "Vektoria\Root.h"
#include <vector>
#include "SteeringManager.h"
#include "Node.h"

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
		/// <param name="steeringManager">Verbindung zur Steuerung der Bewegung</param>
		/// <param name="path">Referenz auf Pfad</param>
		/// <param name="stopDistance">Haltedistanz zum Ziel</param>
		/// <param name="repeat">Optional - True: wiederhole Pfad, wenn Ende erreicht</param>
		FollowPathAction(Movement::SteeringManager* steeringManager, std::vector<Pathfinding::Node*> path, float stopDistance,  bool repeat = false);

		/// <summary>
		/// Gibt an, welcher Knoten besucht werden soll und wertet Distanz aus
		/// </summary>
		virtual void Act() override;

		/// <summary>
		/// Setzt nächsten Knoten (Bei Wiederholung: Setzt bei Erreichen des letzten Knoten auf ersten Knoten)
		/// </summary>
		void NextNode();

	protected:
		/// <summary>
		/// Verbindung zur Steuerung der Bewegung
		/// </summary>
		Movement::SteeringManager* _steeringManager;
		/// <summary>
		/// Zu besuchender Knoten
		/// </summary>
		Pathfinding::Node* _node;
		/// <summary>
		/// Knotenliste des Pfads
		/// </summary>
		std::vector<Pathfinding::Node*> _path;

		/// <summary>
		/// Index aktueller Knoten
		/// </summary>
		int _i;

		/// <summary>
		/// Haltedistanz zum Ziel
		/// </summary>
		float _stopDistance;
		/// <summary>
		/// Gibt an, ob Pfad wiederholt werden soll
		/// </summary>
		bool _repeat;

	};
}
