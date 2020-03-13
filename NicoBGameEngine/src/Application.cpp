#pragma once

#include "Application.h"

#include <GLFW/glfw3.h>

namespace NicoBGameEngine
{
	Application::Application()
	{
		_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (run)
		{
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->OnUpdate();
		}
	}

}