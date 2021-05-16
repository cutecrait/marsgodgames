#include "AStarAlgorithm.h"

namespace Pathfinding
{
	AStarAlgorithm::AStarAlgorithm()
	{
		_startnode = nullptr;
		_goalnode = nullptr;
	}

	void AStarAlgorithm::Compute(Node* startnode, Node* goalnode)
	{
		//Node-Values:
		//g = geringste Kosten Start zu Knoten
		//h = berechnete Kosten Knoten zu Ziel
		//f = g + h

		_startnode = startnode;
		_goalnode = goalnode;

		AddClosedNode(_startnode, _startnode);

		if (_startnode = _goalnode)
			return;

		AddOpenNode(_startnode);

		while (!_open.empty())
		{
			std::pair<float, Node*> pair = *(_open.begin());
			Node*& current = pair.second;
			float fcost = pair.first;

			_open.erase(_open.begin());

			for (Connection*& connection : current->GetConnections())
			{
				float predicted = _open.begin()->first + connection->GetCost();
				if (predicted < Distance(_startnode, connection->GetNode()))
				{
					AddClosedNode(connection->GetNode(), current);
					//TODO -If (connection->GetNode() == _goalnode)- for early cancel of computation -> faster?
					TryAddOpenNode(connection->GetNode());
				}
			}
		}
	}

	std::vector<Node*> AStarAlgorithm::GetPath()
	{
		std::vector<Node*> path;

		Node* node = _goalnode;

		while (node != _startnode)
		{
			Node* next = _closed[node];
			path.insert(path.begin(), next);
			node = next;
		};

		return path;
	}

	void AStarAlgorithm::AddOpenNode(Node* const& node)
	{
		_open.insert(std::pair<float, Node*>(Distance(_startnode, node) + Distance(node, _goalnode), node));
	}

	void AStarAlgorithm::TryAddOpenNode(Node* const& node)
	{
		for (std::pair<float, Node*> pair : _open)
			if (pair.second == node)
				return;

		AddOpenNode(node);
	}

	void AStarAlgorithm::AddClosedNode(Node* const& node, Node* const& child)
	{
		_closed.insert(std::pair<Node*, Node*>(node, child));
	}

	float AStarAlgorithm::Distance(Node* const& node1, Node* const& node2)
	{
		Vektoria::CHVector* vec1 = node1->GetPosVector();
		Vektoria::CHVector* vec2 = node1->GetPosVector();
		return vec1->Dist(*vec2);
	}
}
