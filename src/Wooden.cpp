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
	SDL_Renderer* render = nullptr;
	SDL_Window* win = nullptr;

	if (!Init(render, win, title, w, h, fScreen)) {
		return false;
	}

	Camera::CamInit(0, 0, w, h);
	Cursor::Init(Surface::LoadTexture(render, "cursor.png"), 25, 32);

	SDL_RenderSetLogicalSize(render, LOGIC_WIN_WIDTH, LOGIC_WIN_HEIGHT); // одинаковый масштаб на разных разрешениях
	//SDL_RenderSetScale(render, 2, 2);

	map.OnLoad("map.txt");
	map.texture_tileset = Surface::LoadTexture(render, "overworld_1.png");

	torch.OnLoad(render, "./animated_torch_0.png", 32, 64, 8);
	torch2.OnLoad(render, "./animated_torch_0.png", 32, 64, 8);
	torch2.rect.x = 32;

	//Entity menu;
	//menu.OnLoad(render, "menu.png", 640, 800,0);
	//menu.rect.w = 160;
	//menu.rect.h = 200;
	//menu.rect.x = 100;

	fps = 0;

	TTF_Init();
	Font = TTF_OpenFont("PressStart2P.ttf", 12); //this opens a font style and sets a size
	White = {255, 255, 255}; // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
	Message_rect.x = 5;
	Message_rect.y = 5;


	int old_time = 0 ;
	int count = 0;

	while (!quit) {

		Cursor::Update(win); // TODO FIX this shit

		Update();
		Render(render);
		Event(event, keyboardState);

		int diff = SDL_GetTicks() - old_time;
		//std::cout << diff << std::endl;

		if(diff >= 1000 ){
			fps = count;
			count = 0;
			if(Message)SDL_DestroyTexture(Message);
			string str = "FPS: " + std::to_string(fps);
			SDL_Surface * surface = TTF_RenderText_Solid(Font, str.c_str(), White);
			Message = SDL_CreateTextureFromSurface(render, surface);
		    SDL_QueryTexture(Message,0, 0, &Message_rect.w, &Message_rect.h);

			SDL_FreeSurface(surface);
			old_time = SDL_GetTicks();
		}
		else count++;
	}

	CleanUp(render, win);
	SDL_Quit();

	return true;
}

bool Wooden::Init(SDL_Renderer*& render, SDL_Window*& win, string title, int w,
		int h, bool fScreen) {
	//SDL INIT---------------------------------------------------------
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}
	//-----------------------------------------------------------------

	//WINDOW INIT------------------------------------------------------
	//выравниваем окно по центру экрна
	win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, w, h,
			SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN * fScreen);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}
	//-----------------------------------------------------------------

	//RENDER INIT------------------------------------------------------
	render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (render == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError()
				<< std::endl;
		return false;
	}
	//-----------------------------------------------------------------

	return true;	  //success
}

void Wooden::Event(SDL_Event* event, const Uint8* keyboardState) {
	SDL_PollEvent(event);

	bool ALT_F4 = keyboardState[SDL_SCANCODE_LALT]
			&& keyboardState[SDL_SCANCODE_F4];
	bool ESCAPE = keyboardState[SDL_SCANCODE_ESCAPE];

	if (ESCAPE || ALT_F4 || (event->type == SDL_QUIT)) {
		quit = true;
	}

	if (keyboardState[SDL_SCANCODE_UP]) {
		//torch.rect.y -= 1;
		Camera::Move(0, 1);
	}
	if (keyboardState[SDL_SCANCODE_DOWN]) {
		//torch.rect.y += 1;
		Camera::Move(0, -1);
	}
	if (keyboardState[SDL_SCANCODE_LEFT]) {
		//torch.rect.x -= 1;
		//Camera::Move(1,0);
	}
	if (keyboardState[SDL_SCANCODE_RIGHT]) {
		//torch.rect.x += 1;
		//Camera::Move(-1,0);
	}

	if (event->type == SDL_MOUSEBUTTONDOWN) {
		torch.rect.x = Cursor::X() - torch.rect.w / 2 - Camera::X();
		torch.rect.y = Cursor::Y() - torch.rect.h / 2 - Camera::Y();
	}

}

void Wooden::Update() {

	SDL_Delay(1);

	for (int i = 0; i < Entity::EntityList.size(); i++) {
		if (!Entity::EntityList[i]) {
			continue;
		}
		Entity::EntityList[i]->OnUpdate();
	}

}

void Wooden::Render(SDL_Renderer* render) {
	SDL_RenderClear(render);

	map.OnRender(render, 0, 0);

	for (int i = 0; i < Entity::EntityList.size(); i++) {
		if (!Entity::EntityList[i]) {
			continue;
		}
		Entity::EntityList[i]->OnRender(render);
	}


	//SDL_Rect Message_rect = {0, 0, 10, 40}; //create a rect
	SDL_RenderCopy(render, Message, nullptr, &Message_rect);






	Cursor::Draw(render);

	SDL_RenderPresent(render);
}

void Wooden::CleanUp(SDL_Renderer*& render, SDL_Window*& win) {

	/*for (int i = 0; i < Entity::EntityList.size(); i++) {
	 if (!Entity::EntityList[i]) {
	 continue;
	 }
	 Entity::EntityList[i]->OnCleanUp();
	 }*/
	Entity::EntityList.clear();
}
