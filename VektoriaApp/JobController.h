#pragma once
#include <vector>
#include "FarmingRobot.h"
#include "MiningRobot.h"
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

		void ActivateFarmingRobot(int count = 1);
		void ActivateMiningRobot(int count = 1);

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

		int _activeFarmingRobots;
		std::vector<FarmingRobot*> _farmingRobots;
		int _activeMiningRobots;
		std::vector<MiningRobot*> _miningRobots;
	};

}