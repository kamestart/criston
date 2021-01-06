#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Criston {
	class CRISTON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros

#define CS_CORE_ERROR(...)   ::Criston::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CS_CORE_WARN(...)    ::Criston::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CS_CORE_INFO(...)    ::Criston::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CS_CORE_TRACE(...)   ::Criston::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CS_CORE_FATAL(...)   ::Criston::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros

#define CS_CLIENT_ERROR(...) ::Criston::Log::GetClientLogger()->error(__VA_ARGS__)
#define CS_CLIENT_WARN(...)  ::Criston::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CS_CLIENT_INFO(...)  ::Criston::Log::GetClientLogger()->info(__VA_ARGS__)
#define CS_CLIENT_TRACE(...) ::Criston::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CS_CLIENT_FATAL(...) ::Criston::Log::GetClientLogger()->fatal(__VA_ARGS__)