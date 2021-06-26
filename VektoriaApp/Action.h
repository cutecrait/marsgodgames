#pragma once

namespace AI
{
	/// <summary>
	/// Basis-Klassen für Aktion
	/// </summary>
	class Action
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		Action();

		/// <summary>
		/// Abstrakte Methode zum Ausführen einer Aktion
		/// </summary>
		virtual void Act() = 0;

	};
}
