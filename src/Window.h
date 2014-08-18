/*
 * Window.h
 *
 *  Created on: 18 авг. 2014 г.
 *      Author: snickers
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <string>
#include <iostream>

#include <SDL2/SDL.h>


class Window {
public:
	static bool Init(const Uint32& w, const Uint32& h, std::string title, bool full_screen);
	static SDL_Window* GetWindow();
	static SDL_Renderer* GetRenderer();
	static void OnCleanUp();

	/* more Window functions are here https://wiki.libsdl.org/CategoryVideo */

private:
	static SDL_Window* _window;
	static SDL_Renderer* _renderer;
};

#endif /* WINDOW_H_ */
