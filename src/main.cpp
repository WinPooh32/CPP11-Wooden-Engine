#include <iostream>
#include "Wooden.h"

#include "constants.h"

#undef main

int main()
{
	//setenv("SDL_VIDEO_X11_LEGACY_FULLSCREEN", "1", 0);
	//-static -static-libgcc -static-libstdc++
	Wooden engine;
	engine.Start("Wooden Engine v0.0045", 640, 800, 0);
	return 0;
}
