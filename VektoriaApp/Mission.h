#pragma once
#include <string>

namespace LevelSystem
{
	class Mission
	{
	public:

		Mission(std::string text, const int& stat, int goal);

		std::string GetText();
		const int GetStat();
		int GetGoal();

	private:

		std::string _text;
		int _value;
		int _goal;

	};
}
