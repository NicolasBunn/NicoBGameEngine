#pragma once

#include <iostream>

#ifdef NB_PLATFORM_WINDOWS
	#ifdef NB_BUILD_DLL
		#define NB_API __declspec(dllexport)
	#else
	#define NB_API __declspec(dllimport)
	#endif
#else
	#error NB error
#endif

#ifdef NB_DEBUG
	#define NB_ENABLE_ASSERTS
#endif
#ifdef NB_ENABLE_ASSERTS
	#define NB_ASSERTS(x, ...){if(!(x)) {std::cout << __VA_ARGS__ << std::endl; __debugbreak();}}
#else
	#define NBGE_ASSERT(x,...)
	#define NGBE_CORE_ASSERT(x,...)
#endif

namespace NicoBGameEngine
{
	template<typename T>
	using Unique = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Unique<T> CreateUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Shared = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Shared<T> CreateShared(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}