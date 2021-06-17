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
		/// <param name="vector">Vektor der Position</param>
		Node(Vektoria::CHVector* vector);
		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="position">Position</param>
		Node(Vektoria::CPlacement* position);

		void AddConnection(Connection* connection);
		void RemoveConnection(Node* node);
		void RemoveConnection(Connection* connection);
		std::vector<Connection*> GetConnections();

		Vektoria::CHVector* GetPosVector();

	private:

		Vektoria::CHVector* _posVector;
		std::vector<Connection*> _connections;

	};

	class Connection
	{
	public:

		Connection(Node*& node, int cost = 1);

		Node* GetNode();
		int GetCost();

	private:

		Node* _node;
		int _cost;

	};

}
