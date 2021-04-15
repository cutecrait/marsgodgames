#include "Node.h"

#include "math.h"

namespace Pathfinding
{
	Node::Node(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	void Node::AddConnection(Connection*& connection)
	{
		_connections.push_back(connection);
	}

	std::vector<Connection*> Node::GetConnections()
	{
		return _connections;
	}
	float Node::GetX()
	{
		return _x;
	}
	float Node::GetY()
	{
		return _y;
	}
	float Node::GetZ()
	{
		return _z;
	}
}
