#pragma once

#include "Events/Event.h"
#include "Core/KeyCodes.h"


namespace NicoBGameEngine
{
	class KeyEvent : public Event
	{
	public:
		inline KeyCode GetKeyCode() const { return _keyCode; }

	protected:
		KeyEvent(KeyCode keycode)
			: _keyCode(keycode)
		{

		}

		KeyCode _keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keycode, int repeatCount)
			: KeyEvent(keycode), _repeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const
		{
			return _repeatCount;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent : " << _keyCode << "( " << _repeatCount << " )";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int _repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode keycode)
			: KeyEvent(keycode)
		{}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent : " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(KeyCode keycode)
			: KeyEvent(keycode)
		{}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent : " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};


}