/*
 * Engine.h
 *
 *  Created on: 20 сент. 2014 г.
 *      Author: snickers
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
#include "FPScounter.h"

class Engine {
public:
	bool quit;

	Engine();
	virtual ~Engine();
	void ToInit(void (*func_OnInit)());
	void ToEvent(void (*func_OnEvent)(SDL_Event* event, const Uint8* keyboardState));
	void SetVideo(int w, int h, bool full_screen, std::string win_title);
	void Start();

private:
	FPS_counter fps;

	bool Init();
	void Event(SDL_Event* event, const Uint8* keyboardState);
	void Update();
	void Render(const double& interpolation);
	void CleanUp();

	void (*func_OnInit)();
	void (*func_OnEvent)(SDL_Event* event, const Uint8* keyboardState);
};

#endif /* ENGINE_H_ */
