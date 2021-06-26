#pragma once

#include "Action.h"

namespace AI
{
	/// <summary>
	/// Aktion f�r Idle
	/// </summary>
	class IdleAction :
		public Action
	{
		/// <summary>
		/// Tue nichts (?)
		/// </summary>
		virtual void Act() override;
	};
}

