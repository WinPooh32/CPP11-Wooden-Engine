#include <iostream>

#include "Engine.h"
#include "constants.h"

#include "Demo/Ship.h"

#undef main

void OnInit(){
	Window::SetMode(800, 600, false, "Hellow, I'm title");

	Ship *ship = new Ship;
	ship->OnLoad("ship.png", 44, 44, 0);
}

int main()
{
	//-static-libgcc -static-libstdc++
	Engine engine;
	engine.ToInit(OnInit);
	engine.Start();
	return 0;
}
