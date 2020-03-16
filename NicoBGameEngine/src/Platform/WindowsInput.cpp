#include "WindowsInput.h"


#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace NicoBGameEngine
{
	Input* Input::_sInstance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int mouseButton)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());

		auto state = glfwGetMouseButton(window, mouseButton);

		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
		double xPos;
		double yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return std::pair<float, float>((float)xPos, (float)yPos);
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
		double xPos;
		double yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return (float)xPos;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
		double xPos;
		double yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return (float)yPos;
	}
}