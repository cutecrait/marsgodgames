#include "LevelManager.h"

namespace LevelSystem
{
	LevelManager::LevelManager()
	{
		_currentLevel = 0;
	}

	void LevelManager::GainXp(int experience)
	{
		int overflow = GetCurrentLevel()->AddExperience(experience);
		if (overflow >= 0 && _currentLevel < _levels.size())
		{
			LevelUp();
			GainXp(overflow);
		}
	}

	bool LevelManager::IsUnlocked(const type_info& typeinfo)
	{
		return IsUnlocked(typeinfo.name());
	}
	bool LevelManager::IsUnlocked(std::string type)
	{
		std::unordered_set<std::string>::iterator it;
		it = _unlockedObjects.find(type);
		return it != _unlockedObjects.end();
	}

	Level* LevelManager::GetCurrentLevel()
	{
		if (_currentLevel == _levels.size())
			return _levels[_currentLevel - 1];
		return _levels[_currentLevel];
	}

	std::vector<Level*> LevelManager::GetAllLevels()
	{
		return _levels;
	}

	void LevelManager::AddLevel(Level* level)
	{
		_levels.push_back(level);
	}

	void LevelManager::LevelUp()
	{
		std::unordered_set<std::string> objects = GetCurrentLevel()->GetLockedObjects();
		std::unordered_set<std::string>::iterator it;
		for (it = objects.begin(); it != objects.end(); it++)
			_unlockedObjects.insert(*it);
		_currentLevel++;
		
	}
}
