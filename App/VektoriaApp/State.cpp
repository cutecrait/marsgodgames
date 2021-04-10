#include "State.h"

namespace AI
{
	State::State()
	{
		_NextState = nullptr;
	}

	void State::Update(float timeDelta)
	{
		UpdateActions();
		UpdateTransitions();
	}

	void State::AddAction(Action* action)
	{
		_Actions.push_back(action);
	}

	void State::AddTransition(Transition* transition)
	{
		_Transitions.push_back(transition);
	}

	State* State::GetNextState()
	{
		State* state = _NextState;
		_NextState = nullptr;
		return state;
	}

	void State::UpdateActions()
	{
		for (Action*& action : _Actions)
			action->Act();
	}

	void State::UpdateTransitions()
	{
		for (Transition*& transition : _Transitions)
		{
			if (transition->Decide())
				_NextState = transition->GetNextState();
			return;
		}
	}
}
