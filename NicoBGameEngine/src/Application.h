#pragma once

#include <memory>
#include "Core.h"
#include "Window.h"

namespace NicoBGameEngine
{
	class  Application
	{
		public:

			Application();
			virtual ~Application();

			void Run();

			std::unique_ptr<Window> _window;
			bool run = true;
	};

	Application* CreateApplication();
}