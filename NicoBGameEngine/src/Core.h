#pragma once

#ifdef NB_PLATFORM_WINDOWS
	#ifdef NB_BUILD_DLL
		#define NB_API __declspec(dllexport)
	#else
	#define NB_API __declspec(dllimport)
	#endif
#else
	#error NB error
#endif
