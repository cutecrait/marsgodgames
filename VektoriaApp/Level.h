#pragma once
#include <set>
#include <unordered_set>
#include <string>
#include "Mission.h"
#include "UI.h"

namespace LevelSystem
{
	/// <summary>
	/// Klasse f�r Missionen
	/// </summary>
	class Level
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="text">Anzuzeigender Text</param>
		/// <param name="maximumexperience">Erfahrung f�r n�chsten Aufstieg</param>
		/// <param name="currentLevel">aktueller Levelwert</param>
		Level(std::string text, int maximumexperience, int currentLevel);

		/// <summary>
		/// F�gt Mission hinzu
		/// </summary>
		/// <param name="mission">Mission</param>
		void AddMission(Mission* mission);
		/// <summary>
		/// Aktualisiert Missionen von Typ
		/// </summary>
		/// <param name="type">Typ</param>
		/// <param name="count">Anzahl</param>
		/// <param name="ui">Verbindung zu UI</param>
		void UpdateMissions(std::string type, int count, UI* ui);
		/// <summary>
		/// Pr�ft, ob alle Missionen abgeschlossen sind
		/// </summary>
		/// <returns>Ergebnis</returns>
		bool IsCompleted();
		/// <summary>
		/// Initialisiert Missionen im UI
		/// </summary>
		/// <param name="">Verbindung zu UI</param>
		void initLevel(UI* ui);
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

		/// <summary>
		/// Gibt Text zur�ck
		/// </summary>
		/// <returns>Text</returns>
		std::string GetText();

	private:

		/// <summary>
		/// Struct f�r Sortierung der Missionen
		/// </summary>
		struct MissionComparer final
		{
			/// <summary>
			/// Sortiert Missionen
			/// </summary>
			/// <param name="left">erste Mission</param>
			/// <param name="right">zweite Mission</param>
			/// <returns>Ergebnis</returns>
			bool operator() (Mission* left, Mission* right) const
			{
				int value1 = left->GetOrder();
				int value2 = right->GetOrder();
				return value1 < value2;
			}
		};

		/// <summary>
		/// Liste aller Missionen
		/// </summary>
		std::set<Mission*, MissionComparer> _missions;
		/// <summary>
		/// Liste gesperrter Objekte
		/// </summary>
		std::unordered_set<std::string> _lockedObjects;

		/// <summary>
		/// Text
		/// </summary>
		std::string _text;
		/// <summary>
		/// Aktuelle Erfahrung
		/// </summary>
		int _currentExperience;
		/// <summary>
		/// Maximale Erfahrung
		/// </summary>
		int _maxExperience;
		/// <summary>
		/// Anzahl abgeschlossener Missionen
		/// </summary>
		int _missionsCompleted = 0;
		/// <summary>
		/// aktueller Levelwert
		/// </summary>
		int _currentLevel;
	};
}
