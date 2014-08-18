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
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	quit = false;

	SDL_Event* event = new SDL_Event;

	if (!Init(title, w, h, fScreen)) {
		return false;
	}

	//SDL_RenderSetScale(render, 2, 2);

	map.OnLoad("map.txt");
	map.texture_tileset = Surface::LoadTexture("overworld_1.png");

	torch.OnLoad("animated_torch_0.png", 32, 64, 8);
	torch2.OnLoad("animated_torch_0.png", 32, 64, 8);
	torch2.rect.x = 32;

	fps = 0;

	fps_text.Init(10, 10, "", "PressStart2P.ttf", 20);
	fps_text.SetText("Test Text");
	fps_text.SetSize(11);

	const int TICKS_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;
	Uint32 next_game_tick = SDL_GetTicks();
	interpolation = 0;

	while (!quit) {

		int loops = 0;
		while (SDL_GetTicks() > next_game_tick && loops < MAX_FRAMESKIP) {

			Cursor::Update(Window::GetWindow()); // TODO FIX this shit
			fps_text.SetPos(Cursor::X() - 32, Cursor::Y() + 32); //TODO remove this shit

			Event(event, keyboardState);

			Update();

			next_game_tick += SKIP_TICKS;
			loops++;
		}

		interpolation = float(SDL_GetTicks() + SKIP_TICKS - next_game_tick)
				/ float(SKIP_TICKS);

		Render(Window::GetRenderer());
		SDL_Delay(1);
	}

	/*

	 while (!quit) {

	 int diff = SDL_GetTicks() - old_time;

	 Cursor::Update(win); // TODO FIX this shit

	 Update();
	 Event(event, keyboardState);

	 Render(render);

	 fps_text.SetPos(Cursor::X() - 32 , Cursor::Y() + 32); //TODO remove this shit

	 if (diff >= 1000) {
	 fps = count;
	 count = 0;
	 string str = "FPS: " + std::to_string(fps);
	 fps_text.SetText(render, str);

	 old_time = SDL_GetTicks();
	 } else {
	 count++;
	 }

	 }

	 */

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
	Cursor::Init(Surface::LoadTexture("cursor.png"), 25, 32);

	//SDL_RenderSetLogicalSize(render, LOGIC_WIN_WIDTH, LOGIC_WIN_HEIGHT); // одинаковый масштаб на разных разрешениях

	std::cout << "Successfully initialized!" << std::endl;
	return true;	//success
}

void Wooden::Event(SDL_Event* event, const Uint8* keyboardState) {
	while (SDL_PollEvent(event)) {
		bool ALT_F4 = keyboardState[SDL_SCANCODE_LALT]
				&& keyboardState[SDL_SCANCODE_F4];
		bool ESCAPE = keyboardState[SDL_SCANCODE_ESCAPE];

		if (ESCAPE || ALT_F4 || (event->type == SDL_QUIT)) {
			quit = true;
			return;
		}

		if (event->type == SDL_KEYDOWN) {

			if (keyboardState[SDL_SCANCODE_UP]) {
				//torch.rect.y -= 1;
				Camera::Move(0, 10 * interpolation);
			}
			if (keyboardState[SDL_SCANCODE_DOWN]) {
				//torch.rect.y += 1;
				Camera::Move(0, -10 * interpolation);
			}
			if (keyboardState[SDL_SCANCODE_LEFT]) {
				//torch.rect.x -= 1;
				//Camera::Move(1,0);
			}
			if (keyboardState[SDL_SCANCODE_RIGHT]) {
				//torch.rect.x += 1;
				//Camera::Move(-1,0);
			}
		}

		if (event->type == SDL_MOUSEBUTTONDOWN) {
			torch.rect.x = Cursor::X() - torch.rect.w / 2 - Camera::X();
			torch.rect.y = Cursor::Y() - torch.rect.h / 2 - Camera::Y();
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

	map.OnRender(0, 0);

	for (unsigned int i = 0; i < Entity::EntityList.size(); i++) {
		if (Entity::EntityList[i] != nullptr) {
			Entity::EntityList[i]->OnRender();
		}
	}

	fps_text.Draw();				//TODO remove it
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
