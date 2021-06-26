#pragma once
#include <vector>
#include "Node.h"
#include "IPathSearchAlgorithm.h"

namespace Pathfinding
{
	/// <summary>
	/// Klasse zur Verwaltung der Knoten
	/// </summary>
	class NodeController
	{
	public:

		/// <summary>
		/// Singleton - gibt Instanz zur�ck
		/// </summary>
		/// <returns>Instanz</returns>
		static inline NodeController& Instance()
		{
			static NodeController _instance;
			return _instance;
		};

		/// <summary>
		/// Berechnet Pfad und gibt ihn zur�ck
		/// </summary>
		/// <param name="start">Startknoten</param>
		/// <param name="end">Zielknoten</param>
		/// <returns>Pfad</returns>
		std::vector<Node*> GetPath(Node* start, Node* end);

		/// <summary>
		/// F�gt Knoten hinzu
		/// </summary>
		/// <param name="node">Knoten</param>
		void AddNode(Node* node);
		/// <summary>
		/// L�scht Knoten mit Verbindungen
		/// </summary>
		/// <param name="node">Knoten</param>
		void RemoveNode(Node* node);

	private:

		/// <summary>
		/// Konstruktor
		/// </summary>
		NodeController();

		/// <summary>
		/// Liste aller Knoten
		/// </summary>
		std::vector<Node*> _nodes;
		/// <summary>
		/// Klasse zur Berechnung des Pfads
		/// </summary>
		IPathSearchAlgorithm* _pathSearchAlgorithm;
	};
}

