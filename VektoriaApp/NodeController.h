#pragma once
#include <vector>
#include "Node.h"
#include "IPathSearchAlgorithm.h"

namespace Pathfinding
{
	class NodeController
	{
	public:

		static inline NodeController& Instance()
		{
			static NodeController _instance;
			return _instance;
		};

		std::vector<Node*> GetPath(Node* start, Node* end);

		void AddNode(Node* node);
		void RemoveNode(Node* node);

	private:

		NodeController();
		NodeController(const NodeController&);

		std::vector<Node*> _nodes;
		IPathSearchAlgorithm* _pathSearchAlgorithm;

		NodeController& operator = (const NodeController&);
	};
}

