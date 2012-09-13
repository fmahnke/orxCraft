About orxCraft
--------------
orxCraft is a config (.ini) file editor for the Orx portable game engine.

It runs using Orx itself, so the effects of changing configuration files can immediately be shown on screen.

Development Schedule
--------------------
* Object Editor and FX Slot Editor (proof of concept)
* Save and Load configuration .ini files
* Complete editor windows for remainder of Orx structures
* Integrate orxCraft with ScrollEd

Building
--------

* Project files for codelite and Microsoft Visual Studio 2010 are included.
* A Premake file is included for building on Linux. See [Building orxCraft](https://github.com/fmahnke/orxCraft/wiki/Building)

Setup Using CEGUI as the GUI engine
-----------------------------------
The following needs to be in the executable directory. You might have to do
this manually on Windows:

* All the stuff from the cegui folder 
* All the TaharezLook.* files from your own CEGUI build
* CEGUI .dll dependencies from your CEGUI build
* sampleconfig.ini from the data directory

Notes on libRocket
------------------
The code to render the GUI with libRocket is now out of sync with the master
branch (continuing with CEGUI is the focus). The libRocket code has been
removed from master and is now contained in the librocket-support branch.

It will need some modifications before it will work with the master branch.

