#pragma once
#include <map>
#include "Node.h"

namespace Pathfinding
{
	class IPathSearchAlgorithm
	{
	public:

		virtual void Compute(Node* startnode, Node* goalnode) = 0;
		virtual std::vector<Node*> GetPath() = 0;

	protected:



	};
}
