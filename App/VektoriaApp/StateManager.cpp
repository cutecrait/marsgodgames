#include "StateManager.h"
#include "State.h"

namespace AI
{
	StateManager::StateManager() : StateManager(nullptr)
	{
	}

	StateManager::StateManager(State* state)
	{
		_State = state;
	}

	void StateManager::Update(float timeDelta)
	{
		if (!_State)
			return;

		_State->Update(timeDelta);
		State* s = _State->GetNextState();
		if (s)
			SetState(s);
	}

	void StateManager::SetState(State* state)
	{
		_State = state;
	}
}
