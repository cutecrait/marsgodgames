#include "PathController.h"

namespace Pathfinding
{
	PathController::PathController()
	{
		_i = -1;
		_node = nullptr;
		_repeat = false;
	}

	PathController::~PathController()
	{
	}

	void PathController::NextNode()
	{
		_i++;
		if (_i < _path.size())
			_node = _path[_i];
		else if (_repeat)
		{
			_i = 0;
			_node = _path[_i];
		}
		else
			_node = nullptr;
	}
	Node* PathController::GetCurrentNode()
	{
		return _node;
	}
	bool PathController::HasPath()
	{
		return _path.size() > 0;
	}

	void PathController::SetPath(std::vector<Node*> path, bool repeat)
	{
		if (path.size() == 0)
			return;

		if (repeat)
		{
			//Laufe Pfad auf gleichen Knoten zurück
			//(Ohne Start und Ziel)
			int size = path.size();
			for (int i = size - 1; i > 1;)
			{
				i--;
				path.push_back(path[i]);
			}
		}

		_path = path;
		_repeat = repeat;
		NextNode();
	}

	void PathController::ClearPath()
	{
		_i = -1;
		_node = nullptr;
		_path.clear();
	}
}
