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
		/// <param name="x">X-Koordinate</param>
		/// <param name="y">Y-Koordinate</param>
		/// <param name="z">Z-Koordinate</param>
		Node(float x, float y, float z);

		void AddConnection(Connection*& connection);
		std::vector<Connection*> GetConnections();

		float GetX();
		float GetY();
		float GetZ();

	private:

		float _x, _y, _z;
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
