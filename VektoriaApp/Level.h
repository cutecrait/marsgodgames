#pragma once
#include <unordered_set>
#include <string>

namespace LevelSystem
{
	class Level
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="maximumexperience">Erfahrung für nächsten Aufstieg</param>
		Level(int maximumexperience);

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

	private:

		std::unordered_set<std::string> _lockedObjects;

		int _currentExperience;
		int _maxExperience;

	};
}
