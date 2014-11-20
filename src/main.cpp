#include <iostream>

#include "Engine.h"
#include "constants.h"

#include "Core/FPScounter.h"
#include "Demo/Ship.h"

#undef main

Widget* widget;
TextBox* text;

FPS_counter fps;

void Engine::OnInit(){
	Window::SetMode(800, 600, false, "Hello. I'm title");

	Ship *ship = new Ship;
	ship->OnLoad("ship.png", 44, 44, 0);

	widget = new Widget();
	text = new TextBox(widget);
}

void Engine::OnEvent(SDL_Event* event, const Uint8* keyboardState){

}

void Engine::OnUpdate(){

	fps.OnUpdate();

	text->SetText("FPS: " + std::to_string(fps.GetFPS()));
	text->SetPos(Cursor::X() - 32, Cursor::Y() + 32);

	if (widget != nullptr) {//TODO move to Window
		widget->OnUpdate();
		widget->OnUpdateChildren();
	}

}

void Engine::OnRender(){

	if (widget != nullptr) {
		widget->OnRender();
		widget->OnRenderChildren();
	}

}

void Engine::OnCleanUp(){
	delete widget;
}

int main()
{
	//-static-libgcc -static-libstdc++
	Engine engine;
	engine.Start();
	return 0;
}
