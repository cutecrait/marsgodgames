#pragma once
#include "IPathSearchAlgorithm.h"

namespace Pathfinding
{
	class AStarAlgorithm :
		public IPathSearchAlgorithm
	{
	public:

		virtual void Compute(Node* startnode, Node* goalnode) override;

	private:

		/// <summary>
		/// Liste offener Knoten
		/// <para>Key: f-Value (Kosten für Weg über Value: aktuelle Kosten zum Knoten + berechnete Kosten von Knoten zum Ziel)</para>
		/// <para>Value: Knoten</para>
		/// </summary>
		std::multimap<float, Node*> _open;
		/// <summary>
		/// Liste abgelaufener Knoten
		/// <para>Key: aktueller Knoten</para>
		/// <para>Value: Vorläufer von Key</para>
		/// </summary>
		std::multimap<Node*, Node*> _closed;

		Node*& _startnode;
		Node*& _goalnode;

		void AddOpenNode(Node* const& node);
		void TryAddOpenNode(Node* const& node);
		void AddClosedNode(Node* const& node, Node* const& child);
		float Distance(Node* const& node1, Node* const& node2);

	};
}
