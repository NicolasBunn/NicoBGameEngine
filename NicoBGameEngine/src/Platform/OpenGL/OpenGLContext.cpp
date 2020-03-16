#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace NicoBGameEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: _windowHandle(windowHandle)
	{

	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(_windowHandle);
		glfwPollEvents();
	}
}