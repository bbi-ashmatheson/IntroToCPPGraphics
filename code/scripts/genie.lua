solution "IntroToGraphicsCPP"
  location "../build"

  configurations {
    "Debug",
    "Release",
  }

  platforms {
    "x32",
    "x64",
    "Native",
  }

  language "C++"

WORKSPACE_DIR = path.getabsolute("..")
local THIRD_PARTY_DIR = path.join(BGFX_DIR, "3rdparty")

dofile (path.join(WORKSPACE_DIR, "scripts/toolchain.lua"))
if not toolchain(WORKSPACE_DIR, THIRD_PARTY_DIR) then
	return -- no action specified
end

configuration "Debug"
  defines { "WIN32", "_DEBUG", "_WINDOWS", "_UNICODE", "UNICODE", "%(PreprocessorDefinitions)" }
  links {"D3D11", "D3DCompiler"}
  links {"kernel32","user32","gdi32","winspool","comdlg32","advapi32","shell32","ole32","oleaut32","uuid","odbc32","odbccp32"}
configuration "Release"
  defines { "WIN32", "NDEBUG", "_WINDOWS", "_UNICODE", "UNICODE", "%(PreprocessorDefinitions)" }
  links {"D3D11", "D3DCompiler"}
  links {"kernel32","user32","gdi32","winspool","comdlg32","advapi32","shell32","ole32","oleaut32","uuid","odbc32","odbccp32"}

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
