#pragma once

#include "Action.h"

namespace AI
{
	class IdleAction :
		public Action
	{
		/// <summary>
		/// Tue nichts (?)
		/// </summary>
		virtual void Act() override;
	};
}

