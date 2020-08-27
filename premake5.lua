workspace "CppCat"
  architecture "x64"
  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
CppCat_Name = "CppCat"
Sandbox_Name = "Sandbox"

----------------------------------------------------------------------
-- Project CppCat
----------------------------------------------------------------------
project (CppCat_Name)
  location (CppCat_Name)
  kind "SharedLib"
  language "C++"

  targetdir ("bin/"..output_dir.."/%{prj.name}")
  objdir ("bin-intermediates/"..output_dir.."/%{prj.name}")

  pchheader "CppCatPCH.h"
  pchsource "CppCat/src/CppCatPCH.cpp"

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
  }

  includedirs
  {
    "%{prj.name}/src",
    "%{prj.name}/thirdpart/spdlog/include",
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "CppCat_Platform_Windows",
      "CppCat_Build_Dll"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. output_dir .. "/" .. Sandbox_Name)
    }

  filter "configurations:Debug"
    defines "CppCat_Debug"
    symbols "On"

  filter "configurations:Release"
    defines "CppCat_Release"
    optimize "On"

  filter "configurations:Dist"
    defines "CppCat_Dist"
    optimize "On"

----------------------------------------------------------------------
-- Project Sandbox
----------------------------------------------------------------------
project (Sandbox_Name)
  location (Sandbox_Name)
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/"..output_dir.."/%{prj.name}")
  objdir ("bin-intermediates/"..output_dir.."/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
  }

  includedirs
  {
    "%{prj.name}/src",
    (CppCat_Name .. "/thirdpart/spdlog/include"),
    (CppCat_Name .. "/src"),
  }

  links
  {
    (CppCat_Name)
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "CppCat_Platform_Windows",
    }

  filter "configurations:Debug"
    defines "CppCat_Debug"
    symbols "On"

  filter "configurations:Release"
    defines "CppCat_Release"
    optimize "On"

  filter "configurations:Dist"
    defines "CppCat_Dist"
    optimize "On"