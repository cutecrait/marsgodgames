#include "Mission.h"

namespace LevelSystem
{
	Mission::Mission(std::string text, std::string type, int goal) : Mission(text, type, 0, goal)
	{
	}

	void Mission::Add(int count = 1)
	{
		_value += count;
	}

	bool Mission::IsCompleted()
	{
		return _value >= _goal;
	}

	Mission::Mission(std::string text, std::string type, int value, int goal)
	{
		_text = text;
		_value = value;
		_goal = goal;
		_type = type;
	}

	std::string Mission::GetText()
	{
		return _text;
	}
	std::string Mission::GetType()
	{
		return _type;
	}
	int Mission::GetValue()
	{
		return _value;
	}
	int Mission::GetGoal()
	{
		return _goal;
	}
}
