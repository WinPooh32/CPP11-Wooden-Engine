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

#include "Window.h"
#include "Surface.h"
#include "GUI.h"
#include "Text.h"
#include "Animation.h"
#include "Entity.h"
#include "Map.h"
#include "Camera.h"
#include "Cursor.h"

#include "Demo/Ship.h"
#include "Demo/Bullet.h"

using namespace std;

class Wooden {
public:
	//Wooden();
	//virtual ~Wooden();

	bool Start(string title, int w, int h, bool fScreen);

private:
	bool on_up_pressed, on_down_pressed;

	bool quit;

	Ship ship;
	Uint32 timer;

	Text fps_text;
	Text welcome;
	Uint32 fps;

	bool Init(string title, Uint32 w, Uint32 h, bool fScreen);
	void Render(SDL_Renderer* render);
	void Update();
	void Event(SDL_Event* event, const Uint8* keyboardState);
	void CleanUp();
};

#endif /* WOODEN_H_ */
