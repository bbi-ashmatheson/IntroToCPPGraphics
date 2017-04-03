-- Solution definition
solution "IntroToGraphicsCPP"
  location "../build"

  -- Only Debug and Release configurations
  configurations {
    "Debug",
    "Release",
  }

  -- Support for X86, X64 and 'native' (for other OSes)
  platforms {
    "x32",
    "x64",
    "Native",
  }

  -- C++
  language "C++"

-- Folder for the 'workspace'
WORKSPACE_DIR = path.getabsolute("..")

-- For when we have a 3rd party library set (AssImp, any font libs, etc)
local THIRD_PARTY_DIR = path.join(WORKSPACE_DIR, "3rdparty")

-- Add in the toolchain.lua scrip and fire off the main script
-- to set up the build environment
dofile (path.join(WORKSPACE_DIR, "scripts/toolchain.lua"))
if not toolchain(WORKSPACE_DIR, THIRD_PARTY_DIR) then
	return -- no action specified
end

-- configureations for Debug
configuration "Debug"
  defines { "WIN32", "_DEBUG", "_WINDOWS", "_UNICODE", "UNICODE", "%(PreprocessorDefinitions)" }
  links {"D3D11", "D3DCompiler"}
  links {"kernel32","user32","gdi32","winspool","comdlg32","advapi32","shell32","ole32","oleaut32","uuid","odbc32","odbccp32"}

-- configuration for Release
configuration "Release"
  defines { "WIN32", "NDEBUG", "_WINDOWS", "_UNICODE", "UNICODE", "%(PreprocessorDefinitions)" }
  links {"D3D11", "D3DCompiler"}
  links {"kernel32","user32","gdi32","winspool","comdlg32","advapi32","shell32","ole32","oleaut32","uuid","odbc32","odbccp32"}

-- our first project
project "intro01"
  PROJ_DIR = path.join(WORKSPACE_DIR, "intro01")
  flags { "WinMain"}

  kind "WindowedApp"

  includedirs {
    path.join(PROJ_DIR, "src")
  }

  files {
    path.join(PROJ_DIR, "src/**.h"),
    path.join(PROJ_DIR, "src/**.cpp"),
  }
