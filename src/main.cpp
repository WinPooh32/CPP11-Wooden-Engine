#include <iostream>

#include "Engine.h"
#include "constants.h"

#include "Demo/Ship.h"

#undef main

void OnInit(){
	Window::SetMode(800, 600, false, "Проба пера");

	Ship *ship = new Ship;
	ship->OnLoad("ship.png", 44, 44, 0);
}

int main()
{
	//setenv("SDL_VIDEO_X11_LEGACY_FULLSCREEN", "1", 0);
	//-static -static-libgcc -static-libstdc++
	//"-lmingw32 -lSDL2main -lSDL2 -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc"
	Engine engine;
	engine.ToInit(OnInit);
	engine.Start();
	return 0;
}
