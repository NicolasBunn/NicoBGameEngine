#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.h"



namespace NicoBGameEngine
{
	class WindowsWindow : public Window
	{
		public:
			WindowsWindow(const WindowProps& props);
			virtual ~WindowsWindow();

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return _data.width; }
			inline unsigned int GetHeight() const override { return _data.height; }

		private:

			virtual void Init(const WindowProps& props);
			virtual void Shutdown();

			GLFWwindow* _window;

			struct WindowData
			{
				std::string title;
				unsigned int width;
				unsigned int height;
				bool VSync;
			};

			WindowData _data;

			unsigned int VBO;
			unsigned int VAO;
			unsigned int EBO;
	};
}