#pragma once
#include <map>
#include "Node.h"

namespace Pathfinding
{
	class IPathSearchAlgorithm
	{
	public:

		virtual void Compute(Node* startnode, Node* goalnode) = 0;

	protected:



	};
}
