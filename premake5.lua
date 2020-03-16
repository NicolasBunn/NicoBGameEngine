workspace "NicoBGameEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "NicoBGameEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "NicoBGameEngine/vendor/Glad/include"
IncludeDir["glm"] =  "NicoBGameEngine/vendor/glm"

include "NicoBGameEngine/vendor/GLFW"
include "NicoBGameEngine/vendor/Glad"

project "NicoBGameEngine"
	location "NicoBGameEngine"
	kind "Staticlib"
	cppdialect "c++17"
	language "C++"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"NB_PLATFORM_WINDOWS",
			"NB_BUILD_DLL"
		}

	filter "configurations:Debug"
			defines "NB_DEBUG"
			symbols "on"

	filter "configurations:Release"
			defines "NB_RELEASE"
			optimize "on"

	filter "configurations:Dist"
			defines "NB_DIST"
			optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"NicoBGameEngine/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"NicoBGameEngine"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"NB_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
			defines "NB_DEBUG"
			symbols "on"

	filter "configurations:Release"
			defines "NB_RELEASE"
			optimize "on"

	filter "configurations:Dist"
			defines "NB_DIST"
			optimize "on"

	


