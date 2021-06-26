#pragma once
#include <string>

namespace LevelSystem
{
	/// <summary>
	/// Klasse f�r Aufgabe
	/// </summary>
	class Mission
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="order">Sortierwert</param>
		/// <param name="text">Anzeigender Text</param>
		/// <param name="type">zu pr�fender Typ</param>
		/// <param name="value">Startwert</param>
		/// <param name="goal">Zielwert</param>
		Mission(int order, std::string text, std::string type, int value, int goal);
		/// <summary>
		/// Konstruktor - Startwert: 0
		/// </summary>
		/// <param name="order">Sortierwert</param>
		/// <param name="text">Anzeigender Text</param>
		/// <param name="type">zu pr�fender Typ</param>
		/// <param name="goal">Zielwert</param>
		Mission(int order, std::string text, std::string type, int goal);

		/// <summary>
		/// Erh�he Wert
		/// </summary>
		/// <param name="count">Anzahl - Default: 1</param>
		void Add(int count = 1);
		/// <summary>
		/// Pr�ft, ob Zielwert erreicht ist
		/// </summary>
		/// <returns>Ergebnis</returns>
		bool IsCompleted();

		/// <summary>
		/// Gibt Sortierwert zur�ck
		/// </summary>
		/// <returns>Sortierwert</returns>
		int GetOrder();
		/// <summary>
		/// Gibt Text zur�ck
		/// </summary>
		/// <returns>Text</returns>
		std::string GetText();
		/// <summary>
		/// Gibt Typ zur�ck
		/// </summary>
		/// <returns>Typ</returns>
		std::string GetType();
		/// <summary>
		/// Gibt aktuellen Wert zur�ck
		/// </summary>
		/// <returns>aktueller Wert</returns>
		int GetValue();
		/// <summary>
		/// Gibt Zielwert zur�ck
		/// </summary>
		/// <returns>Zielwert</returns>
		int GetGoal();

	private:

		/// <summary>
		/// Sortierwert
		/// </summary>
		int _order;
		/// <summary>
		/// Text
		/// </summary>
		std::string _text;
		/// <summary>
		/// Typ
		/// </summary>
		std::string _type;
		/// <summary>
		/// aktueller Wert
		/// </summary>
		int _value;
		/// <summary>
		/// Zielwert
		/// </summary>
		int _goal;

	};
}
