#pragma once
#include <unordered_set>
#include <string>
#include <vector>
#include "Level.h"
#include "GameObject.h"

namespace LevelSystem
{
	/// <summary>
	/// Klasse zur Verwaltung von Missionen und Leveln
	/// </summary>
	class LevelManager
	{
	public:

		/// <summary>
		/// Singleton - gibt Instanz zur�ck
		/// </summary>
		/// <returns>Instanz</returns>
		static LevelManager& Instance()
		{
			static LevelManager _instance;
			return _instance;
		};

		/// <summary>
		/// Erfahrung f�r das aktuelle Level
		/// </summary>
		/// <param name="xp">Erfahrung</param>
		void GainXp(int experience);
		/// <summary>
		/// Gibt zur�ck, ob Objekt entsperrt ist (typeid(Typ))
		/// </summary>
		/// <param name="type">Typ</param>
		/// <returns>Ensperrt</returns>
		bool IsUnlocked(const type_info& typeinfo);
		/// <summary>
		/// Gibt zur�ck, ob Objekt entsperrt ist (typeid(Typ).name)
		/// </summary>
		/// <param name="type">Typname</param>
		/// <returns>Ensperrt</returns>
		bool IsUnlocked(std::string type);
		/// <summary>
		/// H�ngt Level an
		/// </summary>
		/// <param name="level">anzuf�gendes Level</param>
		void AddLevel(Level* level);
		/// <summary>
		/// Gibt aktuelles Level zur�ck
		/// </summary>
		/// <returns>aktuelles Level</returns>
		Level* GetCurrentLevel();
		/// <summary>
		/// Gibt alle Level zur�ck
		/// </summary>
		/// <returns>Alle Level</returns>
		std::vector<Level*> GetAllLevels();

	private:

		/// <summary>
		/// Konstruktor
		/// </summary>
		LevelManager();

		/// <summary>
		/// Iterator des aktuellen Levels
		/// </summary>
		int _currentLevel;
		/// <summary>
		/// alle Level
		/// </summary>
		std::vector<Level*> _levels;
		/// <summary>
		/// alle entsperrten Objekte (type_info.name)
		/// </summary>
		std::unordered_set<std::string> _unlockedObjects;

		/// <summary>
		/// Steigt auf das n�chste Level
		/// </summary>
		void LevelUp();
		
	};
}
