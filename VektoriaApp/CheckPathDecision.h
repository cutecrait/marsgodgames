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
		/// <param name="pathcontroller">Verbindung zum PathController</param>
		/// <param name="haspathcomparer">Comparer, ob Pfad exsistiert</param>
		CheckPathDecision(Pathfinding::PathController* pathcontroller, bool haspathcomparer = true);

		/// <summary>
		/// Prüft anhand Comparer, ob Pfad exsistiert
		/// </summary>
		/// <returns>Ergebnis nach Vergleich</returns>
		virtual bool Decide() override;

	private:

		/// <summary>
		/// Verbindung zu PfadController
		/// </summary>
		Pathfinding::PathController* _pathController;
		/// <summary>
		/// Comparer, ob Pfad exsistiert
		/// </summary>
		bool _hasPathComparer;

	};
}

