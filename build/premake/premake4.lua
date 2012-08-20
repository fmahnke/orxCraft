-- orxCraft solution description
solution "orxCraft"

  os.chdir("..")

  PATH = _ACTION

  configurations {"Linux64 Embedded Dynamic Debug",
                  "Linux64 Embedded Dynamic Profile",
                  "Linux64 Embedded Dynamic Release"}

  flags {"EnableSSE2", "FloatFast","ExtraWarnings",
         "NoManifest", "NoPCH", "StaticRuntime"}

  configuration "*Debug"
    defines {"__orxDEBUG__"}
    flags {"Symbols"}

  configuration "*Profile"
    defines {"__orxPROFILER__"}
    flags {"NoRTTI"}

  configuration "*Release"
    flags {"NoRTTI"}

  location (PATH)

  project "orxCraft"

    language "C++"
    kind "ConsoleApp"

    orx_path = os.getenv("ORX_DIR") or ORX_DIR
    orx_path = orx_path .. "/code"
    orxlib_path = orx_path .. "/lib/dynamic"
    scroll_path = os.getenv("SCROLL_DIR") or SCROLL_DIR
    scroll_path = scroll_path .. "/include/Scroll"
    cegui_path = os.getenv("CEGUI_DIR") or CEGUI_DIR
    ceguilib_path = cegui_path .. "/lib"

    targetdir ("../bin")

    includedirs {"../include", orx_path .. "/include", scroll_path,
                 cegui_path .. "/include/CEGUI"}
    files {"../src/**.cpp"}

    excludes {"../src/CEGUICheckbox.cpp"}

    libdirs {orxlib_path, ceguilib_path}

    links {"CEGUIBase", "CEGUIOpenGLRenderer"}

    configuration "Linux*"
    linkoptions {"-Wl,-rpath=./", "-Wl,-rpath=" .. orxlib_path,
                 "-Wl,-rpath=" .. ceguilib_path}
	postbuildcommands {"ln -sfn ../data ../../bin/data",
			   "ln -sfn ../cegui ../../bin/cegui",
			   "cp ../../data/orxCraftd.ini ../../bin"}

    configuration "Linux64 Embedded Dynamic Debug"
	targetname ("orxCraftd")
	links {"orxd"}

    configuration "Linux64 Embedded Dynamic Release"
	links {"orx"}
