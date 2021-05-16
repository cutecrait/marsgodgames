#include "SteeringManager.h"

namespace Movement
{
	SteeringManager::SteeringManager(Vektoria::CPlacement* placement, float maximumVelocity, float maximumForce)
	{
		_placement = placement;
		_target = nullptr;
		_maximumvelocity = maximumVelocity;
		_maximumForce = maximumForce;
		_currentvelocity = new Vektoria::CHVector(0.f, 0.f, 0.f);
	}

	void SteeringManager::Update(float timedelta)
	{
		if (!_target)
			return;

		//TODO Richtige Allocation?
		Vektoria::CHVector force = *_target;
		force = force.Normal() * _maximumForce;

		*_currentvelocity += force;
		if (_currentvelocity->Length() > _maximumvelocity)
			*_currentvelocity = _currentvelocity->Normal() * _maximumvelocity;

		_placement->TranslateDelta(*_currentvelocity * timedelta);

	}

	Vektoria::CHVector* SteeringManager::GetPosition()
	{
		return &(_placement->GetPos());
	}

	void SteeringManager::SetTarget(Vektoria::CHVector* target)
	{
		_target = target;
	}
}
