#pragma once

#include "Vektoria\Root.h"

namespace Movement
{
	class SteeringManager
	{

	public:

		SteeringManager(Vektoria::CPlacement* placement, float maximumVelocity, float rotationSpeed);

		void Update(float timedelta);

		Vektoria::CHVector* GetPosition();
		void SetTarget(Vektoria::CHVector* target);

	private:

		Vektoria::CPlacement* _placement;
		Vektoria::CHVector* _target;

		float _maximumvelocity;
		float _maximumForce;

		Vektoria::CHVector* _currentvelocity;

	};
}

