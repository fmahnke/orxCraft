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
    flags {"NoRTTI", "Optimize"}

  configuration "*Release"
    flags {"NoRTTI", "Optimize"}

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
    files {"../src/**.cpp", "../include/**.h"}

    libdirs {orxlib_path, ceguilib_path}

    links {"CEGUIBase", "CEGUIOpenGLRenderer"}

    configuration "Linux*"
      buildoptions { "-Wno-unused-function" }
      linkoptions {"-Wl,-rpath=./", "-Wl,-rpath=" .. orxlib_path,
		   "-Wl,-rpath=" .. ceguilib_path}
      postbuildcommands {"ln -sfn ../data ../../bin/data",
			 "ln -sfn ../cegui ../../bin/cegui"}

    configuration "Linux64 Embedded Dynamic Debug"
      targetname ("orxCraftd")
      postbuildcommands {"ln -sfn ../data/orxCraftd.ini ../../bin"}
      links {"orxd"}

    configuration "Linux64 Embedded Dynamic Profile"
      postbuildcommands {"ln -sfn ../data/orxCraft.ini ../../bin"}
      links {"orx"}

    configuration "Linux64 Embedded Dynamic Release"
      postbuildcommands {"ln -sfn ../data/orxCraft.ini ../../bin"}
      links {"orx"}

    -- Workaround a bug in premake codelite generator that does not properly
    -- escape configuration names.
    -- TODO Test if this is still required for premake 4.4 or mercurial HEAD.
    if _ACTION == "codelite" then
      configuration "Linux64 Embedded Dynamic Debug"
	objdir ("obj/Linux64EmbeddedDynamicDebug")

      configuration "Linux64 Embedded Dynamic Profile"
	objdir ("obj/Linux64EmbeddedDynamicProfile")

      configuration "Linux64 Embedded Dynamic Release"
	objdir ("obj/Linux64EmbeddedDynamicRelease")
    end

-- vim: tabstop=8 shiftwidth=2 softtabstop=4 noexpandtab
