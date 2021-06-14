#include "FollowPathAction.h"

namespace AI
{
	FollowPathAction::FollowPathAction(Movement::SteeringController* steeringcontroller, Pathfinding::PathController* pathcontroller, float stopDistance)
	{
		_steeringController = steeringcontroller;
		_pathController = pathcontroller;
		_stopDistance = stopDistance;
		HasReachedEnd = false;
	}

	void FollowPathAction::Act()
	{
		Vektoria::CHVector _current = *_steeringController->GetPosition();
		Vektoria::CHVector _target = *_pathController->GetCurrentNode()->GetPosVector();
		Vektoria::CHVector v_dist = _target - _current;
		float _dist = v_dist.Length();

		if (_dist < _stopDistance)
			_pathController->NextNode();

		if (_pathController->GetCurrentNode())
			_steeringController->SetTarget(_pathController->GetCurrentNode());
	}
}
