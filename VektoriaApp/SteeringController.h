#pragma once

#include "Vektoria\Root.h"
#include "Node.h"

namespace Movement
{
	class SteeringController
	{

	public:

		SteeringController(
			Vektoria::CPlacement* placement,
			Vektoria::CPlacement* rotationplacement,
			float maximumVelocity,
			float maximumforce);

		void Update(float timedelta);

		Vektoria::CHVector GetPosition();
		Pathfinding::Node* GetNodePosition();
		void SetCurrent(Pathfinding::Node* current);
		void SetTarget(Pathfinding::Node* target);

	private:

		Vektoria::CPlacement* _placement;
		Vektoria::CPlacement* _rotationPlacement;
		Pathfinding::Node* _current;
		Pathfinding::Node* _target;

		float _maximumVelocity;
		float _maximumForce;

		Vektoria::CHVector* _velocity;

		float Abs(float value);
		float MapPI(float value);

	};
}

