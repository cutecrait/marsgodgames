#pragma once
#include "Decision.h"
#include "PathController.h"
namespace AI
{
	class CheckPathDecision :
		public Decision
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="duration">Verbindung zum PathController</param>
		CheckPathDecision(Pathfinding::PathController* pathcontroller, bool haspathcomparer = true);

		/// <summary>
		/// Prüft anhand Comparer, ob Pfad exsistiert
		/// </summary>
		/// <returns>Ergebnis nach Vergleich</returns>
		virtual bool Decide() override;

	private:

		Pathfinding::PathController* _pathController;
		bool _hasPathComparer;

	};
}

