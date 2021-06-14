#pragma once
#include <vector>
#include "Node.h"

namespace Pathfinding
{
	/// <summary>
	/// Klasse zur Verwaltung eines Pfads
	/// </summary>
	class PathController
	{
	public:

		/// <summary>
		/// Konstruktor
		/// </summary>
		PathController();
		~PathController();

		/// <summary>
		/// Setzt nächsten Knoten (Bei Wiederholung: Setzt bei Erreichen des letzten Knoten auf ersten Knoten)
		/// </summary>
		void NextNode();

		/// <summary>
		/// Gibt aktuellen Knoten zurück
		/// </summary>
		/// <returns>aktueller Knoten</returns>
		Node* GetCurrentNode();

		/// <summary>
		/// Gibt zurück, ob ein Pfad existiert
		/// </summary>
		/// <returns>Ergebnis</returns>
		bool HasPath();

		/// <summary>
		/// Setzt Pfad
		/// </summary>
		/// <param name="path">Pfad</param>
		/// <param name="repeat">Optional - True: wiederhole Pfad von Anfang, wenn Ende erreicht</param>
		void SetPath(std::vector<Node*> path, bool repeat = false);

		/// <summary>
		/// Setzt Pfad zurück
		/// </summary>
		void ClearPath();

	private:

		/// <summary>
		/// Index aktueller Knoten
		/// </summary>
		int _i;

		/// <summary>
		/// Knotenliste des Pfads
		/// </summary>
		std::vector<Pathfinding::Node*> _path;

		/// <summary>
		/// aktueller Knoten
		/// </summary>
		Pathfinding::Node* _node;

		/// <summary>
		/// Gibt an, ob Pfad wiederholt werden soll
		/// </summary>
		bool _repeat;

	};
}

