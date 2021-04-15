#include "TimedDecision.h"

namespace AI
{
	TimedDecision::TimedDecision(float duration)
	{
		_current = 0;
		_duration = duration;
	}

	bool TimedDecision::Decide()
	{
		//TODO current + timeDelta
		if (_duration < _current)
			return true;
		return false;
	}
}
