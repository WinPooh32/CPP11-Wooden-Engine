/*
 * Cursor.h
 *
 *  Created on: 26 июля 2014 г.
 *      Author: Admin
 */

#ifndef CURSOR_H_
#define CURSOR_H_

#include <SDL2/SDL.h>

#include "Render/Surface.h"
#include "GUI/Window.h"

#include "constants.h"

class Cursor {
public:
	static SDL_Texture* cursor_texture;
	static SDL_Rect cursor_rect;
	static void Init(SDL_Texture* cursor, int w, int h);
	static void Update();
	static void Draw();
	static int X();
	static int Y();
};

#endif /* CURSOR_H_ */
