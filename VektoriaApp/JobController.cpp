#include "JobController.h"
#include <stdlib.h>
#include <time.h> 

namespace JobSystem
{
	JobController::JobController()
	{
		srand(time(NULL));

		_activeConcreteRobots = 0;
		_activeStoneRobots = 0;
		_activeSteelRobots = 0;
	}

	void JobController::InitRobots(Vektoria::CPlacement* root, int count)
	{
		Vektoria::CPlacement* p;
		for (int i = 0; i < count; i++)
		{
			ConcreteRobot* concrete = new ConcreteRobot();
			_concreteRobots.push_back(concrete);
			p = concrete->GetPlacement();
			p->Translate(0, 5 + i, 0);
			root->AddPlacement(p);

			StoneRobot* stone = new StoneRobot();
			_stoneRobots.push_back(stone);
			p = stone->GetPlacement();
			p->Translate(2, 5 + i, 0);
			root->AddPlacement(p);

			SteelRobot* steel = new SteelRobot();
			_steelRobots.push_back(steel);
			p = steel->GetPlacement();
			p->Translate(4, 5 + i, 0);
			root->AddPlacement(p);
		}
	}

	void JobController::Update(float deltatime)
	{
		for (int i = 0; i < _activeConcreteRobots; i++)
			_concreteRobots[i]->Update(deltatime);
		for (int i = 0; i < _activeStoneRobots; i++)
			_stoneRobots[i]->Update(deltatime);
		for (int i = 0; i < _activeSteelRobots; i++)
			_steelRobots[i]->Update(deltatime);
	}

	void JobController::ActivateConcreteRobot(int count)
	{
		for (int i = 0; i < count; i++)
		{
			RobotBase* robot = _concreteRobots[_activeConcreteRobots + i];
			robot->SetNode(GetRandomFactory());
			robot->SetPath(GetRandomTarget(), true);
		}
		_activeConcreteRobots += count;
	}

	void JobController::ActivateStoneRobot(int count)
	{
		for (int i = 0; i < count; i++)
		{
			RobotBase* robot = _stoneRobots[_activeStoneRobots + i];
			robot->SetNode(GetRandomFactory());
			robot->SetPath(GetRandomTarget(), true);
		}
		_activeStoneRobots += count;
	}

	void JobController::ActivateSteelRobot(int count)
	{
		for (int i = 0; i < count; i++)
		{
			RobotBase* robot = _steelRobots[_activeSteelRobots + i];
			robot->SetNode(GetRandomFactory());
			robot->SetPath(GetRandomTarget(), true);
		}
		_activeSteelRobots += count;
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
		//TODO suspect to change
		int i = rand() % (_factoryNodes.size()); //Bei 1: immer 0; Bei 2: rand % 2 = 0 oder 1
		return _factoryNodes[i];
	}

	Pathfinding::Node* JobController::GetRandomTarget()
	{
		//TODO suspect to change
		int i = rand() % (_targetNodes.size()); //Bei 1: immer 0; Bei 2: rand % 2 = 0 oder 1
		return _targetNodes[i];
	}
}
