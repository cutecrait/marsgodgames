#include "Node.h"

#include "math.h"

namespace Pathfinding
{
	Node::Node(Vektoria::CHVector* vector)
	{
		_posVector = vector;
	}

	Node::Node(Vektoria::CPlacement* position) : Node(&(position->GetPos()))
	{
	}

	void Node::AddConnection(Connection*& connection)
	{
		_connections.push_back(connection);
	}

	void Node::RemoveConnection(Connection* connection)
	{
		std::vector<Connection*>::iterator pos = std::find(_connections.begin(), _connections.end(), connection);
		if (pos != _connections.end()) // pos == .end() => element not found
		{
			delete *pos;
			_connections.erase(pos);
		}
	}

	std::vector<Connection*> Node::GetConnections()
	{
		return _connections;
	}
	Vektoria::CHVector* Node::GetPosVector()
	{
		return _posVector;
	}
}
