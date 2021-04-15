#pragma once

#include <vector>
#include "state.h"

namespace AI
{
	/// <summary>
	/// Klasse zu Verwaltung von Zuständen
	/// </summary>
	class StateManager
	{
	public:

		/// <summary>
		/// Konstruktor (kein Anfangszustand)
		/// </summary>
		StateManager();
		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="">Zustand, der aktiv sein soll</param>
		StateManager(State*);

		/// <summary>
		/// Ausführung und Aktualisierung von aktivem Zustand
		/// </summary>
		/// <param name="timeDelta">Zeitspanne seit letztem Aufruf der Funktion</param>
		void Update(float timeDelta);

		/// <summary>
		/// Setzt aktiven Zustand (Warnung: Überschreibt aktuellen Zustand)
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
