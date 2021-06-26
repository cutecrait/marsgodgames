#include "SteeringController.h"
#include <algorithm>

namespace Movement
{
	SteeringController::SteeringController(
		Vektoria::CPlacement* placement,
		Vektoria::CPlacement* rotationplacement,
		float maximumvelocity,
		float maximumforce,
		float scale)
	{
		_placement = placement;
		_rotationPlacement = rotationplacement;
		_current = nullptr;
		_target = nullptr;
		_maximumVelocity = maximumvelocity;
		_maximumForce = maximumforce;
		_scale = scale;
		_velocity = new Vektoria::CHVector(0.f, 0.f, 0.f);
	}

	void SteeringController::Update(float timedelta)
	{
		if (!_target)
			return;

		Vektoria::CHVector currentPos = _placement->GetPos();

		//Kraft
		Vektoria::CHVector force = _target->GetPosVector() - currentPos;
		force = force.Normal() * _maximumForce;

		//Geschwindigkeit
		*_velocity += force;
		*_velocity *= timedelta;
		if (_velocity->Length() > _maximumVelocity)
			*_velocity = _velocity->Normal() * _maximumVelocity;

		float angleY = _velocity->AngleXZ();

		//Anwenden
		_placement->TranslateDelta(*_velocity);

		//TODO Funktioniert nur wenn in X Richtung bewegt? (1,0,0)
		_rotationPlacement->RotateY(angleY);
		//Drehe 180 wenn in Z Richtung
		if (Abs(_velocity->z) < Abs(_velocity->x))
			_rotationPlacement->RotateYDelta(PI);
		_rotationPlacement->RotateYDelta(HALFPI);
		_rotationPlacement->ScaleDelta(_scale);
	}

	Vektoria::CHVector SteeringController::GetPosition()
	{
		return _placement->GetPos();
	}

	Pathfinding::Node* SteeringController::GetNodePosition()
	{
		return _current;
	}

	void SteeringController::SetCurrent(Pathfinding::Node* current)
	{
		_current = current;
	}
	void SteeringController::SetTarget(Pathfinding::Node* target)
	{
		if (_target && _current != _target)
			_current = _target;

		_target = target;
	}

	float SteeringController::Abs(float value)
	{
		if (value > 0)
			return value;
		return -value;
	}
}
