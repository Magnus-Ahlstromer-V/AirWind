workspace "Workspace"
    architecture "x64"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}"

project "Game"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++14"
    staticruntime "on"

    targetdir("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir)

    files
    {
        "source/**.h",
        "source/**.cpp"
    }

    includedirs
    {
        "source"
    }

    links { "SDL2main", "SDL2", "SDL2_image" }

    filter "configurations:Debug"
        symbols "on"
        defines { "DEBUG" }

    filter "configurations:Release"
        optimize "on"
        defines { "RELEASE" }
