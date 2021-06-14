#include "StateController.h"
#include "State.h"

namespace AI
{
	StateController::StateController() : StateController(nullptr)
	{
	}

	StateController::StateController(State* state)
	{
		_State = state;
	}

	void StateController::Update(float timeDelta)
	{
		if (!_State)
			return;

		_State->Update(timeDelta);
		State* s = _State->GetNextState();
		if (s)
			SetState(s);
	}

	void StateController::SetState(State* state)
	{
		_State = state;
	}
}
