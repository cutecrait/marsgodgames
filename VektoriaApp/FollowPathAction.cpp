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
		_i = -1;
		_node = nullptr;
		NextNode();
	}

	void FollowPathAction::Act()
	{
		Vektoria::CHVector _current = *_steeringManager->GetPosition();
		Vektoria::CHVector _target = *_path[_i]->GetPosVector();
		Vektoria::CHVector v_dist = _target - _current;
		float _dist = v_dist.Length();
		if (_dist < _stopDistance)
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
		else
		{
			_node = nullptr;
		}
	}
}
