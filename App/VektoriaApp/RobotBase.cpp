#include "RobotBase.h"

RobotBase::RobotBase()
{
	_stateManager = new AI::StateManager();
	_placementRoot = new Vektoria::CPlacement();
	
	CreateMesh();
}

RobotBase::~RobotBase()
{
}

void RobotBase::Update(float timeDelta)
{
	//Update AI
	_stateManager->Update(timeDelta);
}

Vektoria::CPlacement* RobotBase::GetPlacement()
{
	return _placementRoot;
}

void RobotBase::CreateMesh()
{
	//Init
	float body_radius = 1.0f;
	float nose_radius = 0.4f;

	Vektoria::CGeoSphere* body = new Vektoria::CGeoSphere();
	Vektoria::CGeoSphere* nose = new Vektoria::CGeoSphere();
	Vektoria::CPlacement* body_placement = new Vektoria::CPlacement;
	Vektoria::CPlacement* nose_placement = new Vektoria::CPlacement;

	Vektoria::CMaterial* body_material = new Vektoria::CMaterial();
	Vektoria::CMaterial* nose_material = new Vektoria::CMaterial();

	body->Init(body_radius, NULL);
	nose->Init(nose_radius, NULL);

	//Materials
	body_material->MakeTextureDiffuse("textures\\black_image.jpg");
	nose_material->MakeTextureDiffuse("textures\\black_image.jpg");
	body_material->Translate(Vektoria::CColor(0.1f, 0.9f, 0.f));
	nose_material->Translate(Vektoria::CColor(0.9f, 0.f, 0.f));
	body->SetMaterial(body_material);
	nose->SetMaterial(nose_material);

	//Geo
	body_placement->AddGeo(body);
	nose_placement->AddGeo(nose);

	//Placement
	nose_placement->TranslateY(body_radius);
	body_placement->AddPlacement(nose_placement);
	body_placement->TranslateY(body_radius);
	_placementRoot->AddPlacement(body_placement);
}
