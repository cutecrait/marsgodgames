#include "JobController.h"
#include <stdlib.h>
#include <time.h> 

namespace JobSystem
{
	JobController::JobController()
	{
		srand(time(NULL));

		_activeFarmingRobots = 0;
		_activeMiningRobots = 0;
	}

	void JobController::InitRobots(Vektoria::CPlacement* root, int count)
	{
		for (int i = 0; i < count; i++)
		{
			FarmingRobot* farming = new FarmingRobot();
			_farmingRobots.push_back(farming);
			root->AddPlacement(farming->GetPlacement());

			MiningRobot* mining = new MiningRobot();
			_miningRobots.push_back(new MiningRobot());
			root->AddPlacement(mining->GetPlacement());
		}
	}

	void JobController::ActivateFarmingRobot(int count)
	{
		for (int i = 0; i < count; i++)
		{
			RobotBase* robot = _farmingRobots[_activeFarmingRobots + i];
			robot->SetNode(GetRandomFactory());
			robot->SetPath(GetRandomTarget(), true);
		}
		_activeFarmingRobots += count;
	}

	void JobController::ActivateMiningRobot(int count)
	{
		for (int i = 0; i < count; i++)
		{
			RobotBase* robot = _miningRobots[_activeMiningRobots + i];
			robot->SetNode(GetRandomFactory());
			robot->SetPath(GetRandomTarget(), true);
		}
		_activeMiningRobots += count;
	}

	void JobController::AddFactory(Pathfinding::Node* node)
	{
		_factoryNodes.push_back(node);
	}

	void JobController::AddTargetNode(Pathfinding::Node* node)
	{
		_targetNodes.push_back(node);
	}

	Pathfinding::Node* JobController::GetRandomFactory()
	{
		int i = rand() % (_factoryNodes.size()); //Bei 2: rand % 2 = 0 oder 1
		return _factoryNodes[i];
	}

	Pathfinding::Node* JobController::GetRandomTarget()
	{
		//TODO suspect to change
		int i = rand() % (_targetNodes.size() + 1); //Bei einem Ziel: rand % 2 = 0 oder 1
		return _targetNodes[i];
	}
}
