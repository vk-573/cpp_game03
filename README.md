# cpp modulable 2d game

final cpp project for the Chung Ang univerity's cpp module
Made on LINUX UBUNTU.

----------------------
#binary:

./bin/game
you must copy the binary to the root.

--------
#compilation

How to compile :
./comppileWithConan.sh
will launche a series of scripst which will execute conan, cmake and make.

---------------------
IF YOU DONT HAVE CONAN
replace the actual cmake with the one who is at cmake02/withoutConan path
and compile with the ./compile.sh script
 - --- -  - - - - -- - -- - - - - - -- -- -

how to launch: 
./game
after compilation

---------- -- -------
You must have sfml 2.5 dependecie in order to execute this project.
If conan install doesnt work for you, please install the sfml lib manually on your machine and then recompile this project  with ./compile and the cmake which is at cmake02/withoutConan
command to install sfml: sudo apt-get install libsfml-dev

--------------------------------

You must also add the players, weapons and maps plugin into their respectives folders at the libs/ path
libs/players/player.so
libs/weapons/weapon.so
libs/maps/map.so

plugins must have unique names.

this project contain default plugins:
libMapCave.so
libMapSpace.so
libPlayerJojo.so
libPlayerVince.so
libPlayerBab.so
libPlayerDave.so
libWeaponBazooka.so
libWeaponSoldier.so
libWeaponSpeedy.so
libWeaponZeus.so

You must compile the ressources before launching the game otherwise the program will exit with the code 84 and an error plugin message.

To compile these default plugins you must execute 
make at the ./libs/ path
which will compile the plugins src into the .so shared dynamic libraries.

You can edit the libs/makefile in order to add your plugins. the plugin ressources must be at libs/pluginname/ressources
example : 
libs/weapons/ressources/WeaponZeus.png
 --------------

Enjoy !



