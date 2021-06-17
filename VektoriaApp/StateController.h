#pragma once

#include <vector>
#include "state.h"

namespace AI
{
	/// <summary>
	/// Klasse zu Verwaltung von Zust�nden
	/// </summary>
	class StateController
	{
	public:

		/// <summary>
		/// Konstruktor (kein Anfangszustand)
		/// </summary>
		StateController();
		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="">Zustand, der aktiv sein soll</param>
		StateController(State*);

		/// <summary>
		/// Ausf�hrung und Aktualisierung von aktivem Zustand
		/// </summary>
		/// <param name="timeDelta">Zeitspanne seit letztem Aufruf der Funktion</param>
		void Update(float timeDelta);

		/// <summary>
		/// Setzt aktiven Zustand (Warnung: �berschreibt aktuellen Zustand)
		/// </summary>
		/// <param name="">Zustand, der aktiv sein soll</param>
		void SetState(State*);

	private:

		/// <summary>
		/// aktiver Zustand
		/// </summary>
		State* _State;

	};
}
