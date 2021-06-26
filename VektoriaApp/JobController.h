#pragma once
#include <vector>
#include "ConcreteRobot.h"
#include "StoneRobot.h"
#include "SteelRobot.h"
#include "Vektoria\Root.h"

namespace JobSystem
{
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
		void InitRobots(Vektoria::CPlacement* root, int count);

		void Update(float deltatime);

		void ActivateConcreteRobot(int count = 1);
		void ActivateStoneRobot(int count = 1);
		void ActivateSteelRobot(int count = 1);

		void AddFactory(Pathfinding::Node* node);
		void AddTargetNode(Pathfinding::Node* node);

	private:

		/// <summary>
		/// Konstruktor
		/// </summary>
		JobController();

		Pathfinding::Node* GetRandomFactory();
		Pathfinding::Node* GetRandomTarget();

		std::vector<Pathfinding::Node*> _factoryNodes;
		std::vector<Pathfinding::Node*> _targetNodes;

		int _activeConcreteRobots;
		std::vector<ConcreteRobot*> _concreteRobots;
		int _activeStoneRobots;
		std::vector<StoneRobot*> _stoneRobots;
		int _activeSteelRobots;
		std::vector<SteelRobot*> _steelRobots;
	};

}