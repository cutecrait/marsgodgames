#include "Level.h"

namespace LevelSystem
{
	Level::Level(std::string text, int maximumexperience, int currentLevel)
	{
		_text = text;
		_currentExperience = 0;
		_maxExperience = maximumexperience;
		
		_currentLevel = currentLevel;
	
	}

	void Level::AddMission(Mission* mission)
	{
		_missions.insert(mission);
	}

	void Level::UpdateMissions(std::string type, int count, UI* uiUpdate)
	{
		_missionsCompleted = 0;
		std::set<Mission*>::iterator it;

		for (it = _missions.begin(); it != _missions.end(); it++) {
			if ((*it)->GetType() == type) {
				(*it)->Add(count);
			}

			if ((*it)->IsCompleted()) {
				_missionsCompleted++; 
			}
			
		}
		uiUpdate->updateLevelUI(_missions.size(), _missionsCompleted, 0);
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

	void Level::initLevel(UI* uiinit)
	{

		std::string dummyar[5] = { "","","","","" };
		int i = 0;
		std::set<Mission*>::iterator it;
		for (it = _missions.begin(); it != _missions.end(); it++) {
			dummyar[i] = (*it)->GetText();
			i++;
		}
		uiinit->makeAllMissions(_missions.size(), _currentLevel, dummyar[0], dummyar[1], dummyar[2], dummyar[3], dummyar[4]);
	}
}