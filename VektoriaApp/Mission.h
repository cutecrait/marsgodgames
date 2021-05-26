#pragma once
#include <string>

namespace LevelSystem
{
	class Mission
	{
	public:

		Mission(std::string text, std::string type, int value, int goal);
		Mission(std::string text, std::string type, int goal);

		void Add(int count = 1);
		bool IsCompleted();

		std::string GetText();
		std::string GetType();
		int GetValue();
		int GetGoal();

	private:

		std::string _text;
		std::string _type;
		int _value;
		int _goal;

	};
}
