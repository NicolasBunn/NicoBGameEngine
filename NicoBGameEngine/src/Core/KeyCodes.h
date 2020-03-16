#pragma once

#include "nbgepch.h"

namespace NicoBGameEngine
{
	typedef enum  KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define NBGE_KEY_SPACE           ::NicoBGameEngine::Key::Space
#define NBGE_KEY_APOSTROPHE      ::NicoBGameEngine::Key::Apostrophe    /* ' */
#define NBGE_KEY_COMMA           ::NicoBGameEngine::Key::Comma         /* , */
#define NBGE_KEY_MINUS           ::NicoBGameEngine::Key::Minus         /* - */
#define NBGE_KEY_PERIOD          ::NicoBGameEngine::Key::Period        /* . */
#define NBGE_KEY_SLASH           ::NicoBGameEngine::Key::Slash         /* / */
#define NBGE_KEY_0               ::NicoBGameEngine::Key::D0
#define NBGE_KEY_1               ::NicoBGameEngine::Key::D1
#define NBGE_KEY_2               ::NicoBGameEngine::Key::D2
#define NBGE_KEY_3               ::NicoBGameEngine::Key::D3
#define NBGE_KEY_4               ::NicoBGameEngine::Key::D4
#define NBGE_KEY_5               ::NicoBGameEngine::Key::D5
#define NBGE_KEY_6               ::NicoBGameEngine::Key::D6
#define NBGE_KEY_7               ::NicoBGameEngine::Key::D7
#define NBGE_KEY_8               ::NicoBGameEngine::Key::D8
#define NBGE_KEY_9               ::NicoBGameEngine::Key::D9
#define NBGE_KEY_SEMICOLON       ::NicoBGameEngine::Key::Semicolon     /* ; */
#define NBGE_KEY_EQUAL           ::NicoBGameEngine::Key::Equal         /* = */
#define NBGE_KEY_A               ::NicoBGameEngine::Key::A
#define NBGE_KEY_B               ::NicoBGameEngine::Key::B
#define NBGE_KEY_C               ::NicoBGameEngine::Key::C
#define NBGE_KEY_D               ::NicoBGameEngine::Key::D
#define NBGE_KEY_E               ::NicoBGameEngine::Key::E
#define NBGE_KEY_F               ::NicoBGameEngine::Key::F
#define NBGE_KEY_G               ::NicoBGameEngine::Key::G
#define NBGE_KEY_H               ::NicoBGameEngine::Key::H
#define NBGE_KEY_I               ::NicoBGameEngine::Key::I
#define NBGE_KEY_J               ::NicoBGameEngine::Key::J
#define NBGE_KEY_K               ::NicoBGameEngine::Key::K
#define NBGE_KEY_L               ::NicoBGameEngine::Key::L
#define NBGE_KEY_M               ::NicoBGameEngine::Key::M
#define NBGE_KEY_N               ::NicoBGameEngine::Key::N
#define NBGE_KEY_O               ::NicoBGameEngine::Key::O
#define NBGE_KEY_P               ::NicoBGameEngine::Key::P
#define NBGE_KEY_Q               ::NicoBGameEngine::Key::Q
#define NBGE_KEY_R               ::NicoBGameEngine::Key::R
#define NBGE_KEY_S               ::NicoBGameEngine::Key::S
#define NBGE_KEY_T               ::NicoBGameEngine::Key::T
#define NBGE_KEY_U               ::NicoBGameEngine::Key::U
#define NBGE_KEY_V               ::NicoBGameEngine::Key::V
#define NBGE_KEY_W               ::NicoBGameEngine::Key::W
#define NBGE_KEY_X               ::NicoBGameEngine::Key::X
#define NBGE_KEY_Y               ::NicoBGameEngine::Key::Y
#define NBGE_KEY_Z               ::NicoBGameEngine::Key::Z
#define NBGE_KEY_LEFT_BRACKET    ::NicoBGameEngine::Key::LeftBracket   /* [ */
#define NBGE_KEY_BACKSLASH       ::NicoBGameEngine::Key::Backslash     /* \ */
#define NBGE_KEY_RIGHT_BRACKET   ::NicoBGameEngine::Key::RightBracket  /* ] */
#define NBGE_KEY_GRAVE_ACCENT    ::NicoBGameEngine::Key::GraveAccent   /* ` */
#define NBGE_KEY_WORLD_1         ::NicoBGameEngine::Key::World1        /* non-US #1 */
#define NBGE_KEY_WORLD_2         ::NicoBGameEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define NBGE_KEY_ESCAPE          ::NicoBGameEngine::Key::Escape
#define NBGE_KEY_ENTER           ::NicoBGameEngine::Key::Enter
#define NBGE_KEY_TAB             ::NicoBGameEngine::Key::Tab
#define NBGE_KEY_BACKSPACE       ::NicoBGameEngine::Key::Backspace
#define NBGE_KEY_INSERT          ::NicoBGameEngine::Key::Insert
#define NBGE_KEY_DELETE          ::NicoBGameEngine::Key::Delete
#define NBGE_KEY_RIGHT           ::NicoBGameEngine::Key::Right
#define NBGE_KEY_LEFT            ::NicoBGameEngine::Key::Left
#define NBGE_KEY_DOWN            ::NicoBGameEngine::Key::Down
#define NBGE_KEY_UP              ::NicoBGameEngine::Key::Up
#define NBGE_KEY_PAGE_UP         ::NicoBGameEngine::Key::PageUp
#define NBGE_KEY_PAGE_DOWN       ::NicoBGameEngine::Key::PageDown
#define NBGE_KEY_HOME            ::NicoBGameEngine::Key::Home
#define NBGE_KEY_END             ::NicoBGameEngine::Key::End
#define NBGE_KEY_CAPS_LOCK       ::NicoBGameEngine::Key::CapsLock
#define NBGE_KEY_SCROLL_LOCK     ::NicoBGameEngine::Key::ScrollLock
#define NBGE_KEY_NUM_LOCK        ::NicoBGameEngine::Key::NumLock
#define NBGE_KEY_PRINT_SCREEN    ::NicoBGameEngine::Key::PrintScreen
#define NBGE_KEY_PAUSE           ::NicoBGameEngine::Key::Pause
#define NBGE_KEY_F1              ::NicoBGameEngine::Key::F1
#define NBGE_KEY_F2              ::NicoBGameEngine::Key::F2
#define NBGE_KEY_F3              ::NicoBGameEngine::Key::F3
#define NBGE_KEY_F4              ::NicoBGameEngine::Key::F4
#define NBGE_KEY_F5              ::NicoBGameEngine::Key::F5
#define NBGE_KEY_F6              ::NicoBGameEngine::Key::F6
#define NBGE_KEY_F7              ::NicoBGameEngine::Key::F7
#define NBGE_KEY_F8              ::NicoBGameEngine::Key::F8
#define NBGE_KEY_F9              ::NicoBGameEngine::Key::F9
#define NBGE_KEY_F10             ::NicoBGameEngine::Key::F10
#define NBGE_KEY_F11             ::NicoBGameEngine::Key::F11
#define NBGE_KEY_F12             ::NicoBGameEngine::Key::F12
#define NBGE_KEY_F13             ::NicoBGameEngine::Key::F13
#define NBGE_KEY_F14             ::NicoBGameEngine::Key::F14
#define NBGE_KEY_F15             ::NicoBGameEngine::Key::F15
#define NBGE_KEY_F16             ::NicoBGameEngine::Key::F16
#define NBGE_KEY_F17             ::NicoBGameEngine::Key::F17
#define NBGE_KEY_F18             ::NicoBGameEngine::Key::F18
#define NBGE_KEY_F19             ::NicoBGameEngine::Key::F19
#define NBGE_KEY_F20             ::NicoBGameEngine::Key::F20
#define NBGE_KEY_F21             ::NicoBGameEngine::Key::F21
#define NBGE_KEY_F22             ::NicoBGameEngine::Key::F22
#define NBGE_KEY_F23             ::NicoBGameEngine::Key::F23
#define NBGE_KEY_F24             ::NicoBGameEngine::Key::F24
#define NBGE_KEY_F25             ::NicoBGameEngine::Key::F25

/* Keypad */
#define NBGE_KEY_KP_0            ::NicoBGameEngine::Key::KP0
#define NBGE_KEY_KP_1            ::NicoBGameEngine::Key::KP1
#define NBGE_KEY_KP_2            ::NicoBGameEngine::Key::KP2
#define NBGE_KEY_KP_3            ::NicoBGameEngine::Key::KP3
#define NBGE_KEY_KP_4            ::NicoBGameEngine::Key::KP4
#define NBGE_KEY_KP_5            ::NicoBGameEngine::Key::KP5
#define NBGE_KEY_KP_6            ::NicoBGameEngine::Key::KP6
#define NBGE_KEY_KP_7            ::NicoBGameEngine::Key::KP7
#define NBGE_KEY_KP_8            ::NicoBGameEngine::Key::KP8
#define NBGE_KEY_KP_9            ::NicoBGameEngine::Key::KP9
#define NBGE_KEY_KP_DECIMAL      ::NicoBGameEngine::Key::KPDecimal
#define NBGE_KEY_KP_DIVIDE       ::NicoBGameEngine::Key::KPDivide
#define NBGE_KEY_KP_MULTIPLY     ::NicoBGameEngine::Key::KPMultiply
#define NBGE_KEY_KP_SUBTRACT     ::NicoBGameEngine::Key::KPSubtract
#define NBGE_KEY_KP_ADD          ::NicoBGameEngine::Key::KPAdd
#define NBGE_KEY_KP_ENTER        ::NicoBGameEngine::Key::KPEnter
#define NBGE_KEY_KP_EQUAL        ::NicoBGameEngine::Key::KPEqual

#define NBGE_KEY_LEFT_SHIFT      ::NicoBGameEngine::Key::LeftShift
#define NBGE_KEY_LEFT_CONTROL    ::NicoBGameEngine::Key::LeftControl
#define NBGE_KEY_LEFT_ALT        ::NicoBGameEngine::Key::LeftAlt
#define NBGE_KEY_LEFT_SUPER      ::NicoBGameEngine::Key::LeftSuper
#define NBGE_KEY_RIGHT_SHIFT     ::NicoBGameEngine::Key::RightShift
#define NBGE_KEY_RIGHT_CONTROL   ::NicoBGameEngine::Key::RightControl
#define NBGE_KEY_RIGHT_ALT       ::NicoBGameEngine::Key::RightAlt
#define NBGE_KEY_RIGHT_SUPER     ::NicoBGameEngine::Key::RightSuper
#define NBGE_KEY_MENU            ::NicoBGameEngine::Key::Menu