/*
 * Wooden.h
 *
 *  Created on: 20 июля 2014 г.
 *      Author: snickers
 */

#ifndef WOODEN_H_
#define WOODEN_H_

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "constants.h"

#include "Surface.h"
#include "GUI.h"
#include "Text.h"
#include "Animation.h"
#include "Entity.h"
#include "Map.h"
#include "Camera.h"
#include "Cursor.h"

using namespace std;

class Wooden {
public:
	//Wooden();
	//virtual ~Wooden();

	bool Start(string title, int w, int h, bool fScreen);

private:
	bool quit;

	Entity torch, torch2;
	Map map;

	Text fps_text;
	Uint32 fps;

	TTF_Font* Font;
	SDL_Color White;
	SDL_Texture* Message;
	SDL_Rect Message_rect;

	int _w,_h;
	bool _fScreen;

	bool Init(SDL_Renderer*& render, SDL_Window*& win, string title, int w, int h, bool fScreen);
	void Render(SDL_Renderer* render);
	void Update();
	void Event(SDL_Event* event, const Uint8* keyboardState);
	void CleanUp(SDL_Renderer*& render, SDL_Window*& win);
};

#endif /* WOODEN_H_ */
