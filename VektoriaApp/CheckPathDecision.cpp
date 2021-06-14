#include "CheckPathDecision.h"

namespace AI
{
	CheckPathDecision::CheckPathDecision(Pathfinding::PathController* pathcontroller, bool haspathcomparer)
	{
		_pathController = pathcontroller;
		_hasPathComparer = haspathcomparer;
	}

	bool CheckPathDecision::Decide()
	{
		return _pathController->HasPath() == _hasPathComparer;
	}
}
