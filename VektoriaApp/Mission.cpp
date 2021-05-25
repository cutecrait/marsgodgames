#include "Mission.h"

namespace LevelSystem
{
	Mission::Mission(std::string text, const int& stat, int goal)
	{
		_text = text;
		_value = stat;
		_goal = goal;
	}

	std::string Mission::GetText()
	{
		return _text;
	}
	const int Mission::GetStat()
	{
		return _value;
	}
	int Mission::GetGoal()
	{
		return _goal;
	}
}
