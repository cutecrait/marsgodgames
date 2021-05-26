#include "Level.h"

namespace LevelSystem
{
	Level::Level(std::string text, int maximumexperience)
	{
		_text = text;
		_currentExperience = 0;
		_maxExperience = maximumexperience;
	}

	void Level::AddMission(Mission* mission)
	{
		_missions.insert(mission);
	}

	void Level::UpdateMissions(std::string type, int count = 1)
	{
		std::set<Mission*>::iterator it;
		for (it = _missions.begin(); it != _missions.end(); it++)
			if ((*it)->GetType() == type)
				(*it)->Add(count);
	}

	bool Level::IsCompleted()
	{
		std::set<Mission*>::iterator it;
		for (it = _missions.begin(); it != _missions.end(); it++)
			if (!((*it)->IsCompleted()))
				return false;
		return true;
	}

	int Level::AddExperience(int experience)
	{
		_currentExperience += experience;
		return _currentExperience - _maxExperience;
	}

	void Level::AddLockedObject(std::string typeinfo)
	{
		_lockedObjects.insert(typeinfo);
	}

	std::unordered_set<std::string> Level::GetLockedObjects()
	{
		return _lockedObjects;
	}

	std::string Level::GetText()
	{
		return _text;
	}
}
