#pragma once

#include <string>
#include <functional>

#include "Core/Core.h"
#include "Events/Event.h"

namespace NicoBGameEngine
{
	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title_ = "Nico Engine",
			unsigned int width_ = 1280,
			unsigned int height_ = 720)
			: title(title_), width(width_), height(height_)
		{

		}
	};

	class NB_API Window
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			virtual void* GetNativeWindow() const = 0;

			static Window* Create(const WindowProps& props = WindowProps());
	};
}
