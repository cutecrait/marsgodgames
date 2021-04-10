#pragma once

namespace AI
{
	/// <summary>
	/// Basis-Klasse für Entscheidung
	/// </summary>
	class Decision
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		Decision();

		/// <summary>
		/// Abstrakte Methode zur Entscheidung
		/// True, wenn Entscheidungsauswertung zutrifft
		/// </summary>
		/// <returns>Entscheidungsauswertung</returns>
		virtual bool Decide() = 0;

	};
}
