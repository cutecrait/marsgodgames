#include "FollowPathAction.h"

namespace AI
{
	FollowPathAction::FollowPathAction(Movement::SteeringManager* steeringManager, std::vector<Pathfinding::Node*> path, float stopDistance, bool repeat) : Action()
	{
		_steeringManager = steeringManager;
		HasReachedEnd = false;
		_path = path;
		_stopDistance = stopDistance;
		_repeat = repeat;
	}

	void FollowPathAction::Act()
	{
		//TODO Logik?
		if (_steeringManager->GetPosition()->Dist(*(_path[_i]->GetPosVector())) < _stopDistance)
		{
			NextNode();
		}
		if (_node)
		{
			_steeringManager->SetTarget(_node->GetPosVector());
		}
	}

	void FollowPathAction::NextNode()
	{
		_i++;
		if (_i < _path.size())
		{
			_node = _path[_i];
		}
		else if (_repeat)
		{
			_i = 0;
			_node = _path[_i];
		}
	}
}
