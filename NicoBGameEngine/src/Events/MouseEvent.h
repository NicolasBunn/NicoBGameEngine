#pragma once

#include "Events/Event.h"

namespace NicoBGameEngine
{
	class MouseMoveEvent : public Event
	{
	public:

		MouseMoveEvent(float x, float y)
			: _mouseX(x), _mouseY(y)
		{

		}

		inline float GetX() const
		{
			return _mouseX;
		}

		inline float GetY() const
		{
			return _mouseY;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent : " << _mouseX << " : " << _mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _mouseX;
		float _mouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(float x, float y)
			: _XOffset(x), _YOffset(y)
		{

		}

		inline float GetXOffset() const
		{
			return _XOffset;
		}

		inline float GetYOffset() const
		{
			return _YOffset;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent : " << _XOffset << " : " << _YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _XOffset;
		float _YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:

		MouseButtonEvent(float x, float y)
			: _XOffset(x), _YOffset(y)
		{

		}

		inline float GetXOffset() const
		{
			return _XOffset;
		}

		inline float GetYOffset() const
		{
			return _YOffset;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent : " << _XOffset << " : " << _YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _XOffset;
		float _YOffset;
	};

	//Il manque des events
}