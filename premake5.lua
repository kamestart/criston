workspace "criston"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outpudir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "criston"
	location "criston"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outpudir .. "/%{prj.name}")
	objdir ("bin-int/" .. outpudir .. "/%{prj.name}")

	pchheader "cspch.h"
	pchsource "criston/src/cspch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"criston/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"CRISTON_PLATFORM_WINDOWS",
			"CRISTON_BUILD_DLL"
		}

		

	filter "configurations:Debug"
		defines "CS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CS_DIST"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outpudir .. "/%{prj.name}")
	objdir ("bin-int/" .. outpudir .. "/%{prj.name}")

	

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"criston/src",
		"criston/vendor/spdlog/include"
		
	}

	links
	{
		"criston"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"CRISTON_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "CS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CS_DIST"
		optimize "On"