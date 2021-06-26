#include "AStarAlgorithm.h"
//#include <cmath>

namespace Pathfinding
{
	AStarAlgorithm::AStarAlgorithm()
	{
		Clear();
	}

	void AStarAlgorithm::Compute(Node* startnode, Node* goalnode)
	{
		//Node-Values:
		//g = geringste Kosten Start zu Knoten
		//h = berechnete Kosten Knoten zu Ziel
		//f = g + h

		//Init
		Clear();
		_startnode = startnode;
		_goalnode = goalnode;
		AddClosedNode(_startnode, _startnode);
		if (_startnode == _goalnode)
			return;
		AddOpenNode(0, _startnode);

		//Durch alle offenen (zu ablaufenden) Knoten
		while (!_open.empty())
		{
			//Knoten mit gerinstem Bewegungswert nehmen
			std::pair<float, Node*> pair = *(_open.begin());
			Node* current = pair.second; //aktueller Knoten
			_open.erase(_open.begin());

			//ziel erreicht => kürzester weg gefunden
			if (current == _goalnode)
				return;

			//Nachbarn prüfen
			Expand(current);
		}
	}

	std::vector<Node*> AStarAlgorithm::GetPath()
	{
		std::vector<Node*> path;

		if (_closed.size() == 0)
			return path;

		//Starte an Zielknoten
		Node* node = _goalnode;
		path.push_back(node);

		//Hole Vorgänger von Knoten
		while (node != _startnode)
		{
			Node* next = _closed[node];
			path.insert(path.begin(), next);
			node = next;
			//bei fehlendem Knoten kein Pfad
			if (!next)
			{
				path.clear();
				return path;
			}
		};

		return path;
	}

	void AStarAlgorithm::Expand(Node* node)
	{
		for (Connection* connection : node->GetConnections())
		{
			Node* neighbor = connection->GetNode();

			//Nachbar bereits abgelaufen?
			if (ClosedContainsNode(neighbor))
				continue;

			//predicted g = g(current) + edge
			float predicted_g = _g[node] + connection->GetCost();

			//besserer Weg zu Nachbar?
			bool better = true;

			std::multimap<float, Node*>::iterator it;
			for (it = _open.begin(); it != _open.end(); it++)
			{
				std::pair<float, Node*> pair = *it;
				if (node == pair.second)
					if (predicted_g >= _g[pair.second])
					{
						better = false;
						break;
					}
			}
			//wenn nicht, nächster
			if (!better)
				continue;

			//f = g + h
			float f = predicted_g + Distance(neighbor, _goalnode);

			if (it != _open.end())
				_open.erase(it);
			AddOpenNode(f, neighbor);
			AddGNode(neighbor, predicted_g);
			AddClosedNode(neighbor, node);
		}
	}

	void AStarAlgorithm::Clear()
	{
		_startnode = nullptr;
		_goalnode = nullptr;
		_open.clear();
		_closed.clear();
		_g.clear();
	}

	//bool AStarAlgorithm::OpenContainsNode(Node* node)
	//{
	//	std::multimap<float, Node*>::iterator it;
	//	for (it = _open.begin(); it != _open.end(); it++)
	//	{
	//		std::pair<float, Node*> pair = *it;
	//		if (node == pair.second)
	//			return true;
	//	}
	//	return false;
	//}

	bool AStarAlgorithm::ClosedContainsNode(Node* node)
	{
		//for each (std::pair<Node*, Node*> pair in _closed)
		//	if (pair.first == node)
		//		return true;
		//return false;
		return _closed[node];
	}

	void AStarAlgorithm::AddOpenNode(float value, Node* node)
	{
		_open.insert(std::pair<float, Node*>(value, node));
	}
	void AStarAlgorithm::AddGNode(Node* node, float value)
	{
		auto v = _g.insert(std::pair<Node*, float>(node, value));
		if (!v.second)
			v.first->second = value;
	}
	void AStarAlgorithm::AddClosedNode(Node* node, Node* child)
	{
		auto v = _closed.insert(std::pair<Node*, Node*>(node, child));
		if (!v.second)
			v.first->second = child;
	}

	float AStarAlgorithm::Distance(Node* node1, Node* node2)
	{
		Vektoria::CHVector vec1 = node1->GetPosVector();
		Vektoria::CHVector vec2 = node2->GetPosVector();
		float dist = vec1.Dist(vec2);
		return dist;
		//return std::abs(dist);
	}
}
