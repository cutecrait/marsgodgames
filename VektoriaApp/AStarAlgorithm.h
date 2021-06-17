#pragma once
#include <map>
#include <unordered_map>
#include "IPathSearchAlgorithm.h"

namespace Pathfinding
{
	/// <summary>
	/// Klasse zur Pfadfindung mit A*-Algorithmus
	/// </summary>
	class AStarAlgorithm :
		public IPathSearchAlgorithm
	{
	public:
		/// <summary>
		/// Konstruktor
		/// </summary>
		AStarAlgorithm();
		/// <summary>
		/// Berechnet k�rzesten Weg
		/// <para>(danach GetPath() aufrufen, sonst Berechnung falsch)</para>
		/// </summary>
		/// <param name="startnode">Start-Knoten</param>
		/// <param name="goalnode">Ziel-Knoten</param>
		void Compute(Node* startnode, Node* goalnode) override;
		/// <summary>
		/// Gibt berechneten Weg zur�ck
		/// <para>(Direkt nach Compute aufrufen)</para>
		/// </summary>
		/// <returns>berechneter Weg</returns>
		std::vector<Node*> GetPath() override;

	private:

		/// <summary>
		/// Liste offener Knoten nach f-Value sortiert
		/// <para>Key: f-Value</para>
		/// <para>Value: Knoten</para>
		/// </summary>
		std::multimap<float, Node*> _open;
		/// <summary>
		/// Liste abgelaufener Knoten
		/// <para>Key: Knoten</para>
		/// <para>Value: Vorg�nger</para>
		/// <para>(Wird r�ckwarts in GetPath() durchlaufen -> Schleifenstart ist Zielknoten)</para>
		/// </summary>
		std::unordered_map<Node*, Node*> _closed;

		/// <summary>
		/// Liste g-Value von abgelaufenen Knoten
		/// <para>Key: Knoten</para>
		/// <para>Value: g-Value</para>
		/// </summary>
		std::unordered_map<Node*, float> _g;

		/// <summary>
		/// Start-Knoten
		/// </summary>
		Node* _startnode;
		/// <summary>
		/// Ziel-Knoten
		/// </summary>
		Node* _goalnode;

		/// <summary>
		/// L�uft Nachbarn des Knoten f�r Berechnung ab
		/// </summary>
		/// <param name="node">Knoten</param>
		void Expand(Node* node);
		/// <summary>
		/// Setzt Algorithmus zur�ck
		/// </summary>
		void Clear();

		//bool OpenContainsNode(Node* node);		
		/// <summary>
		/// Pr�ft, ob Nachbar bereits besucht wurde
		/// <para>(Keine Schleifen)</para>
		/// </summary>
		/// <param name="node">Knoten</param>
		/// <returns>Knoten existiert</returns>
		bool ClosedContainsNode(Node* node);

		/// <summary>
		/// F�gt f-Value und Knoten zu offenen Knoten hinzu
		/// </summary>
		/// <param name="value">f-Value</param>
		/// <param name="node">Knoten</param>
		void AddOpenNode(float value, Node* node);
		/// <summary>
		/// F�gt Knoten und g-Value einer Liste hinzu
		/// </summary>
		/// <param name="node">Knoten</param>
		/// <param name="value">g-Value</param>
		void AddGNode(Node* node, float value);
		/// <summary>
		/// F�gt Knoten und Vorg�nger der geschlossenen Knoten hinzu
		/// </summary>
		/// <param name="node">Knoten</param>
		/// <param name="child">Vorg�nger</param>
		void AddClosedNode(Node* node, Node* child);
		/// <summary>
		/// Distanz von Knoten
		/// </summary>
		/// <param name="node1">Knoten 1</param>
		/// <param name="node2">Knoten 2</param>
		/// <returns>Distanz</returns>
		float Distance(Node* node1, Node* node2);

	};
}
