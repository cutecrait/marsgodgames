#include "Level.h"

namespace LevelSystem
{
	Level::Level(int maximumexperience)
	{
		_currentExperience = 0;
		_maxExperience = maximumexperience;
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

}
