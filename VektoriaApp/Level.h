#pragma once
#include <set>
#include <unordered_set>
#include <string>
#include "Mission.h"

namespace LevelSystem
{
	class Level
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="maximumexperience">Erfahrung für nächsten Aufstieg</param>
		Level(std::string text, int maximumexperience);

		void AddMission(Mission* mission);
		void UpdateMissions(std::string type, int count = 1);
		bool IsCompleted();

		/// <summary>
		/// Fügt Erfahrung hinzu - Gibt Überfluss der Erfahrung zurück zurück
		/// </summary>
		/// <param name="experience">Erfahrung</param>
		/// <returns>Überfluss</returns>
		int AddExperience(int experience);

		/// <summary>
		/// Fügt zu entsperrendes Objekt hinzu
		/// </summary>
		/// <param name="typeinfo">Typ (typeid(Object).name)</param>
		void AddLockedObject(std::string typeinfo);

		/// <summary>
		/// Gibt alle zu entsperrende Objekte zurück
		/// </summary>
		/// <returns>zu entsperrende Objekte</returns>
		std::unordered_set<std::string> GetLockedObjects();


		std::string GetText();

	private:

		std::set<Mission*> _missions;
		std::unordered_set<std::string> _lockedObjects;

		std::string _text;
		int _currentExperience;
		int _maxExperience;

	};
}
