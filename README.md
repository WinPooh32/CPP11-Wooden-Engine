Wooden_Engine
=============
Cross-platform 2D game engine written in C++11 using SDL2 library.

Building steps:
=============

###Linux

Install dependencies:
```
$ sudo apt-get install g++ make cmake libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev 
```
Build source:
```
$ cd /path/to/build/
$ cmake /path/to/folder/with/cmakelists
$ make -j4
```
Where `-j4` is 4 parallel make jobs, it depends on your count of CPU cores.

###Windows
Coming soon...

###Mac OS X
Coming soon...