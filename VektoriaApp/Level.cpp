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

	void Level::UpdateMissions()
	{
		//TODO Mit Hendrick klären wie Missionen und UI updaten
		// 
		//std::set<Mission*>::iterator it;
		//for (it = _missions.begin(); it != _missions.end(); it++)
		//	(*it);
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
