#include "RobotBase.h"
#include "FollowPathAction.h"

RobotBase::RobotBase(float maximumVelocity, float maximumforce)
{
	_stateManager = new AI::StateManager();
	_placementRoot = new Vektoria::CPlacement();
	_steeringManager = new Movement::SteeringManager(_placementRoot, maximumVelocity, maximumforce);

	//TODO test only
	std::vector<Pathfinding::Node*> path;
	Pathfinding::Node* n1 = new Pathfinding::Node(new Vektoria::CHVector(10, 0, 0));
	Pathfinding::Node* n2 = new Pathfinding::Node(new Vektoria::CHVector(0, 0, 0));
	Pathfinding::Node* n3 = new Pathfinding::Node(new Vektoria::CHVector(0, 5, 10));
	path.push_back(n1);
	path.push_back(n2);
	path.push_back(n3);
	AI::State* s1 = new AI::State();
	AI::Action* a1 = new AI::FollowPathAction(_steeringManager, path, 0.1, true);
	s1->AddAction(a1);
	_stateManager->SetState(s1);
	//CreateMesh();
	_model = _modelPath.LoadGeo("textures\\Rover.obj");
	_placementRoot->AddGeo(_model);
	_placementRoot->ScaleDelta(0.01);
}

RobotBase::~RobotBase()
{

}

void RobotBase::Update(float timeDelta)
{
	//Update AI
	_stateManager->Update(timeDelta);
	//Update Movement
	_steeringManager->Update(timeDelta);

	//TODO Wann/Wie bekommt Robot seinen "Auftrag" für Pathfinding -> Neue Methode SetPath(vector<Node*>) in FollowPathAction? 
	//-> Wann wird diese Aufgerufen -> JobSystem?
}

Vektoria::CPlacement* RobotBase::GetPlacement()
{
	return _placementRoot;
}

void RobotBase::SetStates()
{
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
