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

			void OnEvent(Event& e);

			void Run();

			inline static Application& GetApplication() { return *_sInstance; }
			inline Window& GetWindow() { return *_window; }
			std::unique_ptr<Window> _window;

			bool run = true;

			static Application* _sInstance;
	};

	Application* CreateApplication();
}