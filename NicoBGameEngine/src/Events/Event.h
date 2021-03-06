#pragma once

#include <string>

#include "Core/Core.h"

namespace NicoBGameEngine
{
	enum class EvenType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication,
		EventCategoryInput,
		EventCategoryKeyboard,
		EventCategoryMouse,
		EventCategoryMouseButton
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::type;}\
								   virtual EventType GetEventType() const override {return GetStaticType();}\
								   virtual const char* GetName() const override {return #type;}

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class Event
	{
		public:

			bool _handled = false;
			virtual EvenType GetEventType() const = 0;
			virtual const char* GetName() const = 0;
			virtual int GetCategoryFlags() const = 0;
			virtual std::string ToString() const
			{
				return GetName();
			}

			inline bool IsInCategory(EventCategory category)
			{
				return GetCategoryFlags() & category;
			}
	};

	class EventDispatcher
	{
		public:
			EventDispatcher(Event& event)
				: _event(event)
			{

			}

			template<typename T, typename F>
			bool Dispatch(const F& func)
			{
				if (_event.GetEventType() == T::GetStaticType())
				{
					_event.handled = func(static_cast<T&>(_event));
					return true;
				}
				return false;
			}

		private:
			Event& _event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}