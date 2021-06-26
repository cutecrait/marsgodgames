#pragma once
#include <set>
#include <unordered_set>
#include <string>
#include "Mission.h"
#include "UI.h"

namespace LevelSystem
{
	class Level
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="maximumexperience">Erfahrung f�r n�chsten Aufstieg</param>
		Level(std::string text, int maximumexperience, int currentLevel);

		void AddMission(Mission* mission);
		void UpdateMissions(std::string type, int count, UI*);
		bool IsCompleted();
		void initLevel(UI*);
		/// <summary>
		/// F�gt Erfahrung hinzu - Gibt �berfluss der Erfahrung zur�ck zur�ck
		/// </summary>
		/// <param name="experience">Erfahrung</param>
		/// <returns>�berfluss</returns>
		int AddExperience(int experience);

		/// <summary>
		/// F�gt zu entsperrendes Objekt hinzu
		/// </summary>
		/// <param name="typeinfo">Typ (typeid(Object).name)</param>
		void AddLockedObject(std::string typeinfo);

		/// <summary>
		/// Gibt alle zu entsperrende Objekte zur�ck
		/// </summary>
		/// <returns>zu entsperrende Objekte</returns>
		std::unordered_set<std::string> GetLockedObjects();


		std::string GetText();

	private:

		struct MissionComparer final
		{
			bool operator() (Mission* left, Mission* right) const
			{
				int value1 = left->GetOrder();
				int value2 = right->GetOrder();
				return value1 < value2;
			}
		};

		std::set<Mission*, MissionComparer> _missions;
		std::unordered_set<std::string> _lockedObjects;

		std::string _text;
		int _currentExperience;
		int _maxExperience;
		int _missionsCompleted = 0;
		int _currentLevel;
	};
}
