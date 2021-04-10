#pragma once

#include <vector>
#include "Action.h"
#include "Decision.h"
#include "Transition.h"

namespace AI
{
	//Deklaration, da gegenseitige Refenzierung in C++
	class Transition;

	/// <summary>
	/// Klasse für Zustände
	/// </summary>
	class State
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		State();

		/// <summary>
		/// Ausführung und Aktualisierung von Aktionen und Entscheidungen
		/// </summary>
		/// <param name="timeDelta">Zeitspanne seit letztem Aufruf der Funktion</param>
		void Update(float timeDelta);

		/// <summary>
		/// Fügt Aktion an (Reihenfolge bestimmt Abfolge)
		/// </summary>
		/// <param name="">Aktion, die angefügt werden soll</param>
		void AddAction(Action*);
		/// <summary>
		/// Fügt Übergang an (Reihenfolge bestimmt Priorität, wenn mehrere Entscheidungen gleichzeitig zutreffen)
		/// </summary>
		/// <param name="">Übergang, der angefügt werden soll</param>
		void AddTransition(Transition*);

		/// <summary>
		/// Gebe nächsten Zustand anhand zutreffender Entscheidungen aus (nullptr, wenn keine Entscheidung)
		/// </summary>
		/// <returns>Nächster Zustand</returns>
		State* GetNextState();

	private:

		/// <summary>
		/// Liste aller Aktionen
		/// </summary>
		std::vector<Action*> _Actions;
		/// <summary>
		/// Liste aller Übergänge
		/// </summary>
		std::vector<Transition*> _Transitions;

		/// <summary>
		/// Nächster Zustand (wird gesetzt, wenn Entscheidung zutrifft, ansonsten nullptr)
		/// </summary>
		State* _NextState;

		/// <summary>
		/// Ausführung und Aktualisierung von Aktionen
		/// </summary>
		void UpdateActions();
		/// <summary>
		/// Ausführung und Aktualisierung von Übergängen
		/// </summary>
		void UpdateTransitions();

	};

	/// <summary>
	/// Klasse für Übergänge
	/// </summary>
	class Transition
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="">Entscheidung, die zutreffen soll</param>
		/// <param name="">Zustand, der auf Entscheidung folgen soll</param>
		Transition(Decision*, State*);

		/// <summary>
		/// Werte Entscheidung aus
		/// </summary>
		/// <returns>Entscheidungsergebnis</returns>
		bool Decide();

		/// <summary>
		/// Gibt Zustand aus
		/// </summary>
		/// <returns>Zustand</returns>
		State* GetNextState();

	private:

		/// <summary>
		/// Entscheidung, die ausgewertet wird
		/// </summary>
		Decision* _Decision;
		/// <summary>
		/// Zustand, der eintreffen soll
		/// </summary>
		State* _State;

	};
}
