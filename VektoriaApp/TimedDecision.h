#pragma once

#include "Decision.h"

namespace AI
{
	/// <summary>
	/// Entscheidung nach Dauer
	/// </summary>
	class TimedDecision :
		public Decision
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="duration">Dauer, wann true erreicht wird</param>
		TimedDecision(float duration);

		/// <summary>
		/// True, wenn Dauer erreicht ist
		/// </summary>
		/// <returns>Erreichen der Dauer</returns>
		virtual bool Decide() override;

	protected:

		/// <summary>
		/// Zählt Zeit
		/// </summary>
		float _current;
		/// <summary>
		/// Zeit bis True
		/// </summary>
		float _duration;

	};
}
