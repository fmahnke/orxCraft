About OrxCraft
--------------
OrxCraft is a config (.ini) file editor for the Orx portable game engine.

It runs using Orx itself, so the effects of changing configuration files can immediately be shown on screen.

Development Schedule
--------------------
* Object Editor and FX Slot Editor (proof of concept)
* Save and Load configuration .ini files
* Complete editor windows for remainder of Orx structures
* Integrate OrxCraft with ScrollEd

Using CEGUI as the GUI engine
-----------------------------
To enable CEGUI support (may crash/not build), unset preprocessor directive USE_LIBROCKET

The following needs to be in the executable directory:

* All the stuff from the cegui folder 
* All the TaharezLook.* files from your own CEGUI build
* CEGUI .dll dependencies from your CEGUI build
* sampleconfig.ini from the data directory

libRocket
---------
To enable libRocket support (may crash/not build) set preprocessor directive USE_LIBROCKET

The following needs to be in the executable directory:

* RocketCore.dll, RocketControls.dll, RocketDebugger.dll form your libRocket build
* All the files in the libRocket folder. These are the libRocket templates and layout files.
* sampleconfig.ini from the data directory