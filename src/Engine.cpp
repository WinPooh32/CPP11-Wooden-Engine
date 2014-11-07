/*
 * Engine.cpp
 *
 *  Created on: 20 сент. 2014 г.
 *      Author: snickers
 */

#include "Engine.h"

#include <iostream>

Engine::Engine() {
	quit = false;
	func_OnInit = nullptr;
	func_OnEvent = nullptr;
}

Engine::~Engine() {
	CleanUp(); //Очищаем все
}

void Engine::ToInit(void (*func_OnInit)()) {
	Engine::func_OnInit = func_OnInit;
}

void Engine::ToEvent(
		void (*func_OnEvent)(SDL_Event* event, const Uint8* keyboardState)) {
	Engine::func_OnEvent = func_OnEvent;
}

void SetVideo(int w, int h, bool full_screen, std::string win_title) {
	Window::SetMode(w, h, full_screen, win_title);
}

void Engine::Start() {

	if (!Init()) {
		return;
	}

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	SDL_Event* event = new SDL_Event;
	double previous = SDL_GetTicks();
	double lag = 0.0;
	int MS_PER_UPDATE = 30;

	while (!quit) {
		SDL_Delay(4);
		double current = SDL_GetTicks();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		Event(event, keyboardState);

		while (lag >= MS_PER_UPDATE) {
			Update();
			lag -= MS_PER_UPDATE;
		}

		Render(lag/MS_PER_UPDATE);
		fps.OnUpdate();
	}

}

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//CALL user function OnInit
	if (func_OnInit != nullptr) {
		(*func_OnInit)();
	}

	if (!Window::IsInitialised()) {
		Window::SetMode(640, 470, false, "Wooden Engine");
	}

	GUI::Init();
	Camera::Init(0, 0, Window::GetWidth(), Window::GetHeight());
	Cursor::Init(Surface::LoadTexture("cursor.png"), 16, 16);

	//SDL_RenderSetLogicalSize(Window::GetRenderer(), LOGIC_WIN_WIDTH,
	//	LOGIC_WIN_HEIGHT); // одинаковый масштаб на разных разрешениях

	std::cout << "Successfully initialized!" << std::endl;
	return true;	//success
}

void Engine::Event(SDL_Event* event, const Uint8* keyboardState) {
	while (SDL_PollEvent(event)) {

		bool ALT_F4 = keyboardState[SDL_SCANCODE_LALT]
				&& keyboardState[SDL_SCANCODE_F4];
		bool ESCAPE = keyboardState[SDL_SCANCODE_ESCAPE];

		if (ESCAPE || ALT_F4 || (event->type == SDL_QUIT)) {
			quit = true;
			return;
		}

		//TODO ЗАЧЕМ???
		//CALL user function OnEvent
		if (func_OnEvent != nullptr) {
			(*func_OnEvent)(event, keyboardState);
		}

	}
}

void Engine::Update() {
	for (unsigned int i = 0; i < Entity::EntityList.size(); i++) {
		if (Entity::EntityList[i] != nullptr) {
			Entity::EntityList[i]->OnUpdate();
		}
	}

}

void Engine::Render(const double& interpolation) {
	SDL_RenderClear(Window::GetRenderer());

	for (unsigned int i = 0; i < Entity::EntityList.size(); i++) {
		if (Entity::EntityList[i] != nullptr) {
			Entity::EntityList[i]->OnRender(interpolation);
		}
	}

	Cursor::Update();
	Cursor::Draw();

	SDL_RenderPresent(Window::GetRenderer());
}

void Engine::CleanUp() {
	std::cout << "Unloading textures..." << std::endl;
	Surface::OnCleanUp();		//Destroy all textures

	std::cout << "Killing entities..." << std::endl;
	Entity::EntityList.clear(); //Cleanup all entities

	std::cout << "Cleaning GUI..." << std::endl;
	GUI::OnCleanUp();

	std::cout << "Closing window..." << std::endl;
	Window::OnCleanUp();

	std::cout << "Quitting..." << std::endl;

	TTF_Quit();
	SDL_Quit();
}
