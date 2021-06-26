#include "RobotBase.h"
#include "FollowPathAction.h"
#include "IdleAction.h"
#include "CheckPathDecision.h"
#include "NodeController.h"

RobotBase::RobotBase(Pathfinding::Node* startingnode, float maximumvelocity, float maximumforce, char* model, char* texture, float scale)
{
	//Init
	_placementRoot = new Vektoria::CPlacement();
	_rotationPlacement = new Vektoria::CPlacement();
	_placementRoot->AddPlacement(_rotationPlacement);

	//Init SteeringController
	_steeringController =
		new Movement::SteeringController(_placementRoot, _rotationPlacement, maximumvelocity, maximumforce, scale);

	SetNode(startingnode);

	//Init PathController
	_pathController = new Pathfinding::PathController();

	// Init StateController
	_stateController = new AI::StateController();
	//States
	AI::State* followPathState = new AI::State();
	AI::State* idleState = new AI::State();
	//Actions
	AI::Action* followPath = new AI::FollowPathAction(_steeringController, _pathController, 0.1);
	AI::Action* idle = new AI::IdleAction();
	//Decisions
	AI::Decision* hasPath = new AI::CheckPathDecision(_pathController);
	AI::Decision* noPath = new AI::CheckPathDecision(_pathController, false);
	//Transitions
	AI::Transition* toAction = new AI::Transition(hasPath, followPathState);
	AI::Transition* toIdle = new AI::Transition(noPath, idleState);
	//setup states
	followPathState->AddAction(followPath);
	followPathState->AddTransition(toIdle);
	idleState->AddAction(idle);
	idleState->AddTransition(toAction);
	_stateController->SetState(idleState);

	//Model
	setModel(model);
	setMaterial(texture);
	getModel()->SetMaterial(getMaterial());

	_rotationPlacement->AddGeo(getModel());
	_rotationPlacement->ScaleDelta(scale);

}

void RobotBase::Update(float timeDelta)
{
	//Update AI
	_stateController->Update(timeDelta);
	//Update Movement
	_steeringController->Update(timeDelta);
}

Vektoria::CPlacement* RobotBase::GetPlacement()
{
	return _placementRoot;
}

void RobotBase::SetNode(Pathfinding::Node* node)
{
	if (node)
		_placementRoot->Translate(node->GetPosVector());

	_steeringController->SetCurrent(node);
}

void RobotBase::SetPath(Pathfinding::Node* node, bool repeat)
{
	std::vector<Pathfinding::Node*> path =
		Pathfinding::NodeController::Instance().GetPath(_steeringController->GetNodePosition(), node);
	_pathController->SetPath(path, repeat);
}
