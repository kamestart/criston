#pragma once


#include "Core.h"

namespace Criston {
	class CRISTON_API Application
	{
	public:
		Application();
		virtual ~Application();

		// voids

		void Run();
	};

	Application* CreateApplication();

}

