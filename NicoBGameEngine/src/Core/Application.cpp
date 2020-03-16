#pragma once

#include "Application.h"
#include "Input.h"

#include <GLFW/glfw3.h>

namespace NicoBGameEngine
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::_sInstance = nullptr;

	Application::Application()
	{
		_sInstance = this;

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		//dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose)); // A corriger
		//On peut envoyer les event d'ici ;
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