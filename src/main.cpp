#include <iostream>
#include "Wooden.h"

#include "constants.h"

#undef main

int main()
{
	//setenv("SDL_VIDEO_X11_LEGACY_FULLSCREEN", "1", 0);
	//-static -static-libgcc -static-libstdc++
	//"-lmingw32 -lSDL2main -lSDL2 -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc"
	Wooden engine;
	engine.Start("Wooden Engine v0.0046", 1280, 720, 0);
	return 0;
}
