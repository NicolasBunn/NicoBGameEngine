#include <glad/glad.h>

#include "WindowsWindow.h"

namespace NicoBGameEngine
{
	static bool s_GLFWInitialized = false;
	static void GLFWErrorCallback(int error, const char* description)
	{
		std::cout << "Hello Error " << std::endl;
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		float vertices[] = {
			// positions         // colors
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,

		};
		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};

		_data.title = props.title;
		_data.width = props.width;
		_data.height = props.height;

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)props.width, (int)props.height, _data.title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(_window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glfwSetWindowUserPointer(_window, &_data);

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glBindVertexArray(0);

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(_window);
	}

	void WindowsWindow::OnUpdate()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glfwSwapBuffers(_window);
		glfwPollEvents();

	}
}

