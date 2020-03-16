#pragma once

#include "nbgepch.h"

namespace NicoBGameEngine
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define HZ_MOUSE_BUTTON_0      ::NicoBGameEngine::Mouse::Button0
#define HZ_MOUSE_BUTTON_1      ::NicoBGameEngine::Mouse::Button1
#define HZ_MOUSE_BUTTON_2      ::NicoBGameEngine::Mouse::Button2
#define HZ_MOUSE_BUTTON_3      ::NicoBGameEngine::Mouse::Button3
#define HZ_MOUSE_BUTTON_4      ::NicoBGameEngine::Mouse::Button4
#define HZ_MOUSE_BUTTON_5      ::NicoBGameEngine::Mouse::Button5
#define HZ_MOUSE_BUTTON_6      ::NicoBGameEngine::Mouse::Button6
#define HZ_MOUSE_BUTTON_7      ::NicoBGameEngine::Mouse::Button7
#define HZ_MOUSE_BUTTON_LAST   ::NicoBGameEngine::Mouse::ButtonLast
#define HZ_MOUSE_BUTTON_LEFT   ::NicoBGameEngine::Mouse::ButtonLeft
#define HZ_MOUSE_BUTTON_RIGHT  ::NicoBGameEngine::Mouse::ButtonRight
#define HZ_MOUSE_BUTTON_MIDDLE ::NicoBGameEngine::Mouse::ButtonMiddle
