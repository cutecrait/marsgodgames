#include "RobotBase.h"
#include "FollowPathAction.h"
#include "IdleAction.h"
#include "CheckPathDecision.h"
#include "NodeController.h"

RobotBase::RobotBase(Pathfinding::Node* startingnode, float maximumvelocity, float maximumforce, float maximumrotation)
{
	//Init
	_placementRoot = new Vektoria::CPlacement();
	_placementRoot->Translate(*(startingnode->GetPosVector()));
	_rotationPlacement = new Vektoria::CPlacement();
	_placementRoot->AddPlacement(_rotationPlacement);

	//Init SteeringController
	_steeringController =
		new Movement::SteeringController(_placementRoot, _rotationPlacement, maximumvelocity, maximumforce, maximumrotation);
	_steeringController->SetCurrent(startingnode);

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

	//TODO Enable
	//Model
	setModel("models\\Rover.obj");
	_rotationPlacement->AddGeo(getModel());
	_rotationPlacement->ScaleDelta(0.01);

	//test only - used cause loadtime while debug
	//CreateMesh();
}

RobotBase::~RobotBase()
{

}

void RobotBase::Update(float timeDelta)
{
	//Update AI
	_stateController->Update(timeDelta);
	//Update Movement
	_steeringController->Update(timeDelta);

	//TODO Wann/Wie bekommt Robot seinen "Auftrag" für Pathfinding -> Neue Methode SetPath(vector<Node*>) in FollowPathAction? 
	//-> Wann wird diese Aufgerufen -> JobSystem?
}

Vektoria::CPlacement* RobotBase::GetPlacement()
{
	return _placementRoot;
}

void RobotBase::SetPath(Pathfinding::Node* node, bool repeat)
{
	std::vector<Pathfinding::Node*> path =
		Pathfinding::NodeController::Instance().GetPath(_steeringController->GetNodePosition(), node);
	_pathController->SetPath(path, repeat);
}

void RobotBase::CreateMesh()
{
	//Init
	float body_radius = 1.0f;

	Vektoria::CGeoSphere* body = new Vektoria::CGeoSphere();
	Vektoria::CPlacement* body_placement = new Vektoria::CPlacement;

	Vektoria::CMaterial* body_material = new Vektoria::CMaterial();

	body->Init(body_radius, NULL);

	//Materials
	body_material->MakeTextureDiffuse("textures\\black_image.jpg");
	body_material->Translate(Vektoria::CColor(0.1f, 0.9f, 0.f));
	body->SetMaterial(body_material);

	//Geo
	body_placement->AddGeo(body);

	//Placement
	body_placement->TranslateY(body_radius);
	_placementRoot->AddPlacement(body_placement);
}
