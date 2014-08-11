/*
 * Cursor.h
 *
 *  Created on: 26 июля 2014 г.
 *      Author: Admin
 */

#ifndef CURSOR_H_
#define CURSOR_H_

#include <SDL2/SDL.h>
#include "Surface.h"
#include "constants.h"

class Cursor {
public:
	static SDL_Texture* cursor_texture;
	static SDL_Rect cursor_rect;
	static void Init(SDL_Texture* cursor, int w, int h);
	static void Update(SDL_Window* win);
	static void Draw(SDL_Renderer* render);
	static int X();
	static int Y();
};

#endif /* CURSOR_H_ */

