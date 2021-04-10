#include "Transition.h"
#include "Decision.h"
#include "State.h"

namespace AI
{
	Transition::Transition(Decision* decision, State* state)
	{
		_Decision = decision;
		_State = state;
	}

	bool Transition::Decide()
	{
		return _Decision->Decide();
	}

	State* Transition::GetNextState()
	{
		return _State;
	}
}
