#pragma once

#include "Vektoria\Root.h"
#include "Connection.h"

namespace Pathfinding
{
	class Connection;

	/// <summary>
	/// Klasse f�r Knoten
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
		/// F�gt Verbindung zu Knoten hinzu
		/// </summary>
		/// <param name="node">Nachbarknoten</param>
		/// <param name="cost">Kosten - Default = 1</param>
		void AddConnection(Node* node, int cost = 1);
		/// <summary>
		/// F�gt Verbindung zu/von Knoten hinzu
		/// </summary>
		/// <param name="node">Nachbarknoten</param>
		/// <param name="cost">Kosten - Default = 1</param>
		void AddTwoWayConnection(Node* node, int cost = 1);
		/// <summary>
		/// F�gt Verbindung zu Knoten hinzu
		/// </summary>
		/// <param name="connection">Verbindung</param>
		void AddConnection(Connection* connection);
		/// <summary>
		/// L�scht alle Verbindungen zu Knoten
		/// </summary>
		/// <param name="node">Knoten</param>
		void RemoveConnection(Node* node);
		/// <summary>
		/// L�scht Verbindung (delete)
		/// </summary>
		/// <param name="connection">Verbindung</param>
		void RemoveConnection(Connection* connection);
		/// <summary>
		/// Gibt alle Verbindungen zur�ck
		/// </summary>
		/// <returns>Verbindungen</returns>
		std::vector<Connection*> GetConnections();

		/// <summary>
		/// Gibt Pos-Vektor zur�ck
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
	/// Klasse f�r Verbindung zu Knoten
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
		/// Gibt Nachbarknoten zur�ck
		/// </summary>
		/// <returns>Nachbarknoten</returns>
		Node* GetNode();
		/// <summary>
		/// Gibt Kosten zur�ck
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
