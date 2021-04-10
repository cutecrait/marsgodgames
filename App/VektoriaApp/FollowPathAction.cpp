#include "FollowPathAction.h"

namespace AI
{
	FollowPathAction::FollowPathAction(std::vector<Vektoria::C2Vector*> path, float trigger, bool repeat) : Action()
	{
		HasReachedEnd = false;
		_path = path;
		_repeat = repeat;
		_trigger = trigger;
	}

	void FollowPathAction::Act()
	{
		//TODO Go to Node (Tell Agent to go to node)

		//TODO If (Distance CurrentVector to NodeVector < trigger)
		NextNode();
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
