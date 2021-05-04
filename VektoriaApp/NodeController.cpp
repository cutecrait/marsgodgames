#include "NodeController.h"
#include "AStarAlgorithm.h"

namespace Pathfinding
{
	NodeController::NodeController()
	{
		_nodes = std::vector<Node*>();
		_pathSearchAlgorithm = new AStarAlgorithm();
	}

	std::vector<Node*> Pathfinding::NodeController::GetPath(Node* start, Node* end)
	{
		_pathSearchAlgorithm->Compute(start, end);
		return _pathSearchAlgorithm->GetPath();
	}

	void NodeController::AddNode(Node* node)
	{
		_nodes.push_back(node);
	}

	void NodeController::RemoveNode(Node* node)
	{
		for (auto i = _nodes.begin(); i != _nodes.end(); i++)
		{
			Node* n = *i;
			std::vector<Connection*> con = n->GetConnections();
			for (auto j = con.begin(); j != con.end(); j++)
			{
				Connection* c = *j;
				if (c->GetNode() == node)
				{
					node->RemoveConnection(c);
					j--;
				}
			}
			_nodes.erase(i--);
		}

	}
}
