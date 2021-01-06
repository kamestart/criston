#pragma once

#ifdef CRISTON_PLATFORM_WINDOWS
	#ifdef CRISTON_BUILD_DLL
		#define CRISTON_API __declspec(dllexport)		
	#else
		#define CRISTON_API __declspec(dllimport)
	#endif
#else
	#error Sorry! Criston Supports Only Windows For Now!
#endif