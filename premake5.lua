-- premake5.lua
workspace "TreeVisualisation"
configurations { "Debug", "Release" }

project "TreeVisualisation"
kind "ConsoleApp"
language "C"
targetdir "bin/%{cfg.buildcfg}"

files { "**.h", "**.c" }
includedirs { "include" }
libdirs { "lib" }
links { "raylib" }

filter "configurations:Debug"
architecture "x86_64"
defines { "DEBUG" }
symbols "On"

filter "configurations:Release"
architecture "x86_64"
defines { "NDEBUG" }
optimize "On"
