#include "Mission.h"

namespace LevelSystem
{
	Mission::Mission(int order, std::string text, std::string type, int goal) : Mission(order, text, type, 0, goal)
	{
	}

	Mission::Mission(int order, std::string text, std::string type, int value, int goal)
	{
		_order = order;
		_text = text;
		_value = value;
		_goal = goal;
		_type = type;
	}

	void Mission::Add(int count)
	{
		_value += count;
	}

	bool Mission::IsCompleted()
	{
		return _value >= _goal;
	}

	int Mission::GetOrder()
	{
		return _order;
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
