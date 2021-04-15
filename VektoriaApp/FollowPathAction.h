#pragma once

#include "Action.h"
#include "Vektoria\Root.h"
#include <vector>

namespace AI
{
	/// <summary>
	/// Aktion zur Pfadverfolgung
	/// </summary>
	class FollowPathAction :
		public Action
	{
	public:

		/// <summary>
		/// True, wenn Ende des Pfads erreicht, ansonsten False (Immer False, wenn Pfad ohne Ende)
		/// </summary>
		bool HasReachedEnd;

		/// <summary>
		/// Konstruktor
		/// </summary>
		/// <param name="path">Referenz auf Pfad</param>
		/// <param name="trigger">TODO ?</param>
		/// <param name="repeat">Optional - True: wiederhole Pfad, wenn Ende erreicht</param>
		FollowPathAction(std::vector<Vektoria::C2Vector*> path, float trigger, bool repeat = false);

		/// <summary>
		/// Gibt an, welcher Knoten besucht werden soll und wertet Distanz aus
		/// </summary>
		virtual void Act() override;

		/// <summary>
		/// Setzt nächsten Knoten (Bei Wiederholung: Setzt bei Erreichen des letzten Knoten auf ersten Knoten)
		/// </summary>
		void NextNode();

	protected:
		/// <summary>
		/// Zu besuchender Knoten
		/// </summary>
		Vektoria::C2Vector* _node;
		/// <summary>
		/// Knotenliste des Pfads
		/// </summary>
		std::vector<Vektoria::C2Vector*> _path;

		/// <summary>
		/// Index aktueller Knoten
		/// </summary>
		int _i;

		/// <summary>
		/// TODO *
		/// </summary>
		float _trigger;
		/// <summary>
		/// Gibt an, ob Pfad wiederholt werden soll
		/// </summary>
		bool _repeat;

	};
}
