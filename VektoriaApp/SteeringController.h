#pragma once

#include "Vektoria\Root.h"
#include "Node.h"

namespace Movement
{
	/// <summary>
	/// Klasse für Steuerung
	/// </summary>
	class SteeringController
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="placement">Placement zum Steuern</param>
		/// <param name="rotationplacement">Placement zum Rotieren</param>
		/// <param name="maximumVelocity">Maximale Geschwindigkeit</param>
		/// <param name="maximumforce">Maximale Kraft</param>
		/// <param name="scale">Skalierung des Rotationsplacement</param>
		SteeringController(
			Vektoria::CPlacement* placement,
			Vektoria::CPlacement* rotationplacement,
			float maximumVelocity,
			float maximumforce,
			float scale = 1);

		/// <summary>
		/// Aktualisiere Steuerung
		/// </summary>
		/// <param name="timedelta">TimeDelta</param>
		void Update(float timedelta);

		/// <summary>
		/// Gibt Pos-Vektor zurück
		/// </summary>
		/// <returns>Pos-Vektor</returns>
		Vektoria::CHVector GetPosition();
		/// <summary>
		/// Gibt aktuellen Knoten zurück
		/// </summary>
		/// <returns>Knoten</returns>
		Pathfinding::Node* GetNodePosition();
		/// <summary>
		/// Setzt Placement zu Knoten
		/// </summary>
		/// <param name="current">Knoten</param>
		void SetCurrent(Pathfinding::Node* current);
		/// <summary>
		/// Setzt Zielknoten
		/// </summary>
		/// <param name="target">Knoten</param>
		void SetTarget(Pathfinding::Node* target);

	private:

		/// <summary>
		/// Steuerungsplacement
		/// </summary>
		Vektoria::CPlacement* _placement;
		/// <summary>
		/// Roationsplacement
		/// </summary>
		Vektoria::CPlacement* _rotationPlacement;
		/// <summary>
		/// Aktueller Knoten
		/// </summary>
		Pathfinding::Node* _current;
		/// <summary>
		/// Zielknoten
		/// </summary>
		Pathfinding::Node* _target;

		/// <summary>
		/// Maximale Geschwindigkeit
		/// </summary>
		float _maximumVelocity;
		/// <summary>
		/// Maximale Kraft
		/// </summary>
		float _maximumForce;
		/// <summary>
		/// Skalierung
		/// </summary>
		float _scale;

		/// <summary>
		/// Aktueller Geschwindigkeitvektor
		/// </summary>
		Vektoria::CHVector* _velocity;

		/// <summary>
		/// Gibt absoluten Wert zurück
		/// </summary>
		/// <param name="value">Wert</param>
		/// <returns>Absoluter Wert</returns>
		float Abs(float value);

	};
}

