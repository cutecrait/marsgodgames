#pragma once

namespace AI
{
	/// <summary>
	/// Basis-Klassen f�r Aktion
	/// </summary>
	class Action
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		Action();

		/// <summary>
		/// Abstrakte Methode zum Ausf�hren einer Aktion
		/// </summary>
		virtual void Act() = 0;

	};
}
