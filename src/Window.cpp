/*
 * Window.cpp
 *
 *  Created on: 18 авг. 2014 г.
 *      Author: snickers
 */

#include "Window.h"

SDL_Window* Window::_window;
SDL_Renderer* Window::_renderer;

bool Window::Init(const Uint32& w, const Uint32& h, const std::string title, const bool full_screen) {

	//WINDOW INIT------------------------------------------------------
	//выравниваем окно по центру экрна
	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, w, h,
			SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN * full_screen);
	if (_window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//RENDER INIT------------------------------------------------------
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError()
				<< std::endl;
		return false;
	}

	return true;
}

SDL_Window* Window::GetWindow() {
	return _window;
}

SDL_Renderer* Window::GetRenderer() {
	return _renderer;
}
void Window::OnCleanUp(){
	SDL_DestroyWindow(_window);
	_window = nullptr;

	SDL_DestroyRenderer(_renderer);
	_renderer = nullptr;
}
