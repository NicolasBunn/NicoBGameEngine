#pragma once

#include "Core.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace NicoBGameEngine
{
	class  Input
	{
	public:
		inline static bool IsKeyPressed(int keycode)
		{
			return _sInstance->IsKeyPressedImpl(keycode);
		}

		inline static bool IsMouseButtonPressed(int mouseButton)
		{
			return _sInstance->IsMouseButtonPressedImpl(mouseButton);
		}

		inline static std::pair<float, float> GetMousePosition()
		{
			return _sInstance->GetMousePositionImpl();
		}

		inline static float GetMouseX()
		{
			return _sInstance->GetMouseXImpl();
		}

		inline static float GetMouseY()
		{
			return _sInstance->GetMouseYImpl();
		}

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int mouseButton) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:
		static Input* _sInstance;

	};
}
