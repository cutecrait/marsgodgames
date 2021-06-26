#pragma once

#include "Vektoria\Root.h"
#include "Connection.h"

namespace Pathfinding
{
	class Connection;

	/// <summary>
	/// Klasse für Knoten
	/// </summary>
	class Node
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="position">Position</param>
		Node(Vektoria::CPlacement* position);

		/// <summary>
		/// Fügt Verbindung zu Knoten hinzu
		/// </summary>
		/// <param name="node">Nachbarknoten</param>
		/// <param name="cost">Kosten - Default = 1</param>
		void AddConnection(Node* node, int cost = 1);
		/// <summary>
		/// Fügt Verbindung zu/von Knoten hinzu
		/// </summary>
		/// <param name="node">Nachbarknoten</param>
		/// <param name="cost">Kosten - Default = 1</param>
		void AddTwoWayConnection(Node* node, int cost = 1);
		/// <summary>
		/// Fügt Verbindung zu Knoten hinzu
		/// </summary>
		/// <param name="connection">Verbindung</param>
		void AddConnection(Connection* connection);
		/// <summary>
		/// Löscht alle Verbindungen zu Knoten
		/// </summary>
		/// <param name="node">Knoten</param>
		void RemoveConnection(Node* node);
		/// <summary>
		/// Löscht Verbindung (delete)
		/// </summary>
		/// <param name="connection">Verbindung</param>
		void RemoveConnection(Connection* connection);
		/// <summary>
		/// Gibt alle Verbindungen zurück
		/// </summary>
		/// <returns>Verbindungen</returns>
		std::vector<Connection*> GetConnections();

		/// <summary>
		/// Gibt Pos-Vektor zurück
		/// </summary>
		/// <returns>Pos-Vektor</returns>
		Vektoria::CHVector GetPosVector();

	private:

		/// <summary>
		/// Knotenplacment
		/// </summary>
		Vektoria::CPlacement* _pos;
		/// <summary>
		/// Liste der Verbindungen
		/// </summary>
		std::vector<Connection*> _connections;

	};

	/// <summary>
	/// Klasse für Verbindung zu Knoten
	/// </summary>
	class Connection
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="node">Nachbarknoten</param>
		/// <param name="cost">Wegkosten - Default: 1</param>
		Connection(Node*& node, int cost = 1);

		/// <summary>
		/// Gibt Nachbarknoten zurück
		/// </summary>
		/// <returns>Nachbarknoten</returns>
		Node* GetNode();
		/// <summary>
		/// Gibt Kosten zurück
		/// </summary>
		/// <returns>Kosten</returns>
		int GetCost();

	private:

		/// <summary>
		/// Nachbarknoten
		/// </summary>
		Node* _node;
		/// <summary>
		/// Kosten
		/// </summary>
		int _cost;

	};

}
