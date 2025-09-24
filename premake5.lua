workspace "MonteCarlo"
    architecture "x64"
    startproject "MonteCarlo"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }
    
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MonteCarlo"
    location "MonteCarlo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "c++20"
    staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "on"


    filter "configurations:Release"
        defines "RELEASE"
        optimize "on"

    
    filter "configurations:Dist"
        defines "DIST"
        optimize "on"
        symbols "off"