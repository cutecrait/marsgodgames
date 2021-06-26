#pragma once
#include <vector>
#include "ConcreteRobot.h"
#include "WoodRobot.h"
#include "SteelRobot.h"
#include "Vektoria\Root.h"

namespace JobSystem
{
	/// <summary>
	/// Klasse für JobSystem der Roboter
	/// </summary>
	class JobController
	{
	public:

		/// <summary>
		/// Singleton - gibt Instanz zurück
		/// </summary>
		/// <returns>Instanz</returns>
		static JobController& Instance()
		{
			static JobController _instance;
			return _instance;
		};

		/// <summary>
		/// Initialisiert Roboter
		/// </summary>
		/// <param name="root">Root-Placement der Roboter</param>
		/// <param name="count">Anzahl Roboter</param>
		void InitRobots(Vektoria::CPlacement* root, int count);

		/// <summary>
		/// Aktualisiert aktive Roboter
		/// </summary>
		/// <param name="deltatime">Deltatime</param>
		void Update(float deltatime);

		/// <summary>
		/// Aktiviert Roboter von Typ Concrete
		/// </summary>
		/// <param name="count">Anzahl - Default: 1</param>
		void ActivateConcreteRobot(int count = 1);
		/// <summary>
		/// Aktiviert Roboter von Typ Wood
		/// </summary>
		/// <param name="count">Anzahl - Default: 1</param>
		void ActivateWoodRobot(int count = 1);
		/// <summary>
		/// Aktiviert Roboter von Typ Steel
		/// </summary>
		/// <param name="count">Anzahl - Default: 1</param>
		void ActivateSteelRobot(int count = 1);

		/// <summary>
		/// Fügt Fabrik als Startknoten hinzu (Spawn)
		/// </summary>
		/// <param name="node">Knoten</param>
		void AddFactory(Pathfinding::Node* node);
		/// <summary>
		/// Fügt Ziel als Zielknoten hinzu (Target)
		/// </summary>
		/// <param name="node">Knoten</param>
		void AddTargetNode(Pathfinding::Node* node);

	private:

		/// <summary>
		/// Konstruktor
		/// </summary>
		JobController();

		/// <summary>
		/// Gebe zufälligen Startknoten zurück
		/// </summary>
		/// <returns>Startknoten</returns>
		Pathfinding::Node* GetRandomFactory();
		/// <summary>
		/// Gebe zufälligen Zielknoten zurück
		/// </summary>
		/// <returns>Zielknoten</returns>
		Pathfinding::Node* GetRandomTarget();

		/// <summary>
		/// Liste mit Startknoten
		/// </summary>
		std::vector<Pathfinding::Node*> _factoryNodes;
		/// <summary>
		/// Liste mit Zielknoten
		/// </summary>
		std::vector<Pathfinding::Node*> _targetNodes;

		/// <summary>
		/// Anzahl aktive Roboter von Typ Concrete
		/// </summary>
		int _activeConcreteRobots;
		/// <summary>
		/// Liste aller Roboter von Typ Concrete
		/// </summary>
		std::vector<ConcreteRobot*> _concreteRobots;
		/// <summary>
		/// Anzahl aktive Roboter von Typ Wood
		/// </summary>
		int _activeWoodRobots;
		/// <summary>
		/// Liste aller Roboter von Typ Wood
		/// </summary>
		std::vector<WoodRobot*> _woodRobots;
		/// <summary>
		/// Anzahl aktive Roboter von Typ Steel
		/// </summary>
		int _activeSteelRobots;
		/// <summary>
		/// Liste aller Roboter von Typ Steel
		/// </summary>
		std::vector<SteelRobot*> _steelRobots;
	};

}