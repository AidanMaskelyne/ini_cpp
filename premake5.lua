workspace "ini_parser"
	configurations { "Debug", "Release" }

project "ini_parser"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	toolset "clang"

	targetdir "target/%{cfg.buildcfg}"
	objdir "target/%{cfg.buildcfg}/obj"

	files {
		"src/**.h",
		"src/**.cpp",
	}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"
