-- premake5.lua
workspace "TreeVisualisation"
configurations { "Debug", "Release" }

project "TreeVisualisation"
kind "ConsoleApp"
language "C++"
cppdialect "C++latest"
targetdir "bin/%{cfg.buildcfg}"

files { "**.h", "**.cpp" }
includedirs { "include", "src" }
libdirs { "lib" }
links { "raylib", "winmm" }

filter "configurations:Debug"
architecture "x86_64"
defines { "DEBUG" }
symbols "On"

filter "configurations:Release"
architecture "x86_64"
defines { "NDEBUG" }
optimize "On"
