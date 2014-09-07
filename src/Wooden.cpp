/*
 * Wooden.cpp
 *
 *  Created on: 20 июля 2014 г.
 *      Author: snickers
 */

#include "Wooden.h"

#include <string>
#include <iostream>
#include "Surface.h"

/*
 Wooden::Wooden() {
 // TODO Auto-generated constructor stub

 }

 Wooden::~Wooden() {
 // TODO Auto-generated destructor stub
 }*/

bool Wooden::Start(string title, int w, int h, bool fScreen) {

	on_up_pressed = on_down_pressed = false;

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	quit = false;

	SDL_Event* event = new SDL_Event;

	if (!Init(title, w, h, fScreen)) {
		return false;
	}

	fps_text.Init(10, 10, "", "PressStart2P.ttf", 8);
	welcome.Init(w / 2 - 100, 0, "Игра \"Привет,Мир!\"", "PressStart2P.ttf",
			13);

	const int TICKS_PER_SECOND = 59;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 9;
	Uint32 next_game_tick = SDL_GetTicks();

	//Таймер для ограничения выстрелов
	timer = SDL_GetTicks();

	int old_time = 0;
	int fps = 0;

	Uint32 beginTime;     // the time when the cycle begun
	int timeDiff;      // the time it took for the cycle to execute
	int sleepTime;      // ms to sleep (<0 if we're behind)

	ship.OnLoad("ship.png", 44, 44, 0);

	while (!quit) {

		//SDL_Delay(4);

		beginTime = SDL_GetTicks();
		int framesSkipped = 0;      // number of frames being skipped

		Event(event, keyboardState);
		Cursor::Update(Window::GetWindow()); // TODO FIX this shit
		Update();

		Render(Window::GetRenderer());

		if (!MAX_FPS) {
			timeDiff = SDL_GetTicks() - beginTime;

			sleepTime = (int) (SKIP_TICKS - timeDiff);
			if (sleepTime > 0) {
				SDL_Delay(sleepTime);
			}

			while (sleepTime < 0 && framesSkipped < MAX_FRAMESKIP) {
				Event(event, keyboardState);
				Cursor::Update(Window::GetWindow()); // TODO FIX this shit
				Update();

				sleepTime += SKIP_TICKS;
				framesSkipped++;
			}
		}

		int diff = SDL_GetTicks() - old_time;
		if (diff >= 1000) {
			string str = "FPS: " + std::to_string(fps);
			fps_text.SetText(str);
			old_time = SDL_GetTicks();
			fps = 0;
		} else {
			fps++;
		}
	}

	CleanUp();

	TTF_Quit();
	SDL_Quit();

	return true;
}

//TODO Make virtual method GameLoop()...

bool Wooden::Init(string title, Uint32 w, Uint32 h, bool fScreen) {

//SDL INIT---------------------------------------------------------
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (!Window::Init(w, h, title, fScreen)) {
		return false;
	}
	GUI::Init();
	Camera::Init(0, 0, w, h);
	Cursor::Init(Surface::LoadTexture("cursor.png"), 16, 16);

	//SDL_RenderSetLogicalSize(Window::GetRenderer(), LOGIC_WIN_WIDTH,
	//	LOGIC_WIN_HEIGHT); // одинаковый масштаб на разных разрешениях

	std::cout << "Successfully initialized!" << std::endl;
	return true;	//success
}

void Wooden::Event(SDL_Event* event, const Uint8* keyboardState) {

	//SDL_PollEvent(event);
	while (SDL_PollEvent(event)) {
		bool ALT_F4 = keyboardState[SDL_SCANCODE_LALT]
				&& keyboardState[SDL_SCANCODE_F4];
		bool ESCAPE = keyboardState[SDL_SCANCODE_ESCAPE];

		if (ESCAPE || ALT_F4 || (event->type == SDL_QUIT)) {
			quit = true;
			return;
		}

		if (event->type == SDL_KEYDOWN) {

		}
	}


}

void Wooden::Update() {

	for (unsigned int i = 0; i < Entity::EntityList.size(); i++) {
		if (Entity::EntityList[i] != nullptr) {
			Entity::EntityList[i]->OnUpdate();
		}
	}

}

void Wooden::Render(SDL_Renderer* render) {
	SDL_RenderClear(render);

	//map.OnRender(0, 0);

	for (unsigned int i = 0; i < Entity::EntityList.size(); i++) {
		if (Entity::EntityList[i] != nullptr) {
			Entity::EntityList[i]->OnRender();
		}
	}

	fps_text.Draw();				//TODO remove it
	welcome.Draw();

	Cursor::Draw();
	SDL_RenderPresent(render);
}

void Wooden::CleanUp() {

	std::cout << "Unloading textures..." << std::endl;
	Surface::OnCleanUp();		//Destroy all textures

	std::cout << "Killing entities..." << std::endl;
	Entity::EntityList.clear(); //Cleanup all entities

	std::cout << "Cleaning GUI..." << std::endl;
	GUI::OnCleanUp();

	std::cout << "Closing window..." << std::endl;
	Window::OnCleanUp();

	std::cout << "Quitting..." << std::endl;
}
