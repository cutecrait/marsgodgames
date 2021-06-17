#pragma once
#include "Node.h"

namespace Pathfinding
{
	/// <summary>
	/// Basisklasse zur Pfadfindung
	/// </summary>
	class IPathSearchAlgorithm
	{
	public:

		/// <summary>
		/// Berechnet (kürzesten) Weg
		/// <para>(danach GetPath() aufgerufen, sonst Berechnung falsch)</para>
		/// </summary>
		/// <param name="startnode">Startknoten</param>
		/// <param name="goalnode">Zielknoten</param>
		virtual void Compute(Node* startnode, Node* goalnode) = 0;
		/// <summary>
		/// Gibt berechneten Weg zurück
		/// <para>(direkt nach Compute aufrufen)</para>
		/// </summary>
		/// <returns>berechneter Weg</returns>
		virtual std::vector<Node*> GetPath() = 0;

	};
}
