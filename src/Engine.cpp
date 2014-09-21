/*
 * Engine.cpp
 *
 *  Created on: 20 сент. 2014 г.
 *      Author: snickers
 */

#include "Engine.h"


Engine::Engine() {
	quit = false;
	func_OnInit = nullptr;
	func_OnEvent = nullptr;
}

Engine::~Engine() {

}

void Engine::ToInit(void (*func_OnInit)()) {
	Engine::func_OnInit = func_OnInit;
}

void Engine::ToEvent(
		void (*func_OnEvent)(SDL_Event* event, const Uint8* keyboardState)) {
	Engine::func_OnEvent = func_OnEvent;
}

void SetVideo(int w, int h, bool full_screen, std::string win_title){
	Window::SetMode(w, h, full_screen, win_title);
}

void Engine::Start() {

	if(!Init()){
		return;
	}

	const int TICKS_PER_SECOND = 30;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 9;
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	SDL_Event* event  = new SDL_Event;
	Uint32 next_game_tick = SDL_GetTicks();
	Uint32 beginTime;     // the time when the cycle begun
	int timeDiff;      // the time it took for the cycle to execute
	int sleepTime;      // ms to sleep (<0 if we're behind)

	while (!quit) {

		beginTime = SDL_GetTicks();
		int framesSkipped = 0;      // number of frames being skipped

		Event(event, keyboardState);
		Update();
		Render();

		if (!MAX_FPS) {
			timeDiff = SDL_GetTicks() - beginTime;

			sleepTime = (int) (SKIP_TICKS - timeDiff);
			if (sleepTime > 0) {
				SDL_Delay(sleepTime);
			}

			while (sleepTime < 0 && framesSkipped < MAX_FRAMESKIP) {
				Event(event, keyboardState);
				Update();

				sleepTime += SKIP_TICKS;
				framesSkipped++;
			}
		}
	}

}

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//CALL user function OnInit
	if(func_OnInit != nullptr){
		(*func_OnInit)();
	}

	if(!Window::IsInitialised()){
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

		bool ALT_F4 = keyboardState[SDL_SCANCODE_LALT] && keyboardState[SDL_SCANCODE_F4];
		bool ESCAPE = keyboardState[SDL_SCANCODE_ESCAPE];

		if (ESCAPE || ALT_F4 || (event->type == SDL_QUIT)) {
			quit = true;
			return;
		}

		//CALL user function OnEvent
		if(func_OnEvent != nullptr){
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
	Cursor::Update();
}

void Engine::Render() {

	SDL_RenderClear(Window::GetRenderer());

	for (unsigned int i = 0; i < Entity::EntityList.size(); i++) {
		if (Entity::EntityList[i] != nullptr) {
			Entity::EntityList[i]->OnRender();
		}
	}
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
