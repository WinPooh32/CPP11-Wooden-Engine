/*
 * Engine.h
 *
 *  Created on: 20 сент. 2014 г.
 *      Author: snickers
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"

#include "GUI/GUI.h"
#include "GUI/Window.h"
#include "GUI/Widget.h"
#include "GUI/Text.h"
#include "GUI/TextBox.h"

#include "Render/Camera.h"
#include "Render/Surface.h"
#include "Render/Animation.h"

#include "Core/FPScounter.h"
#include "Core/Entity.h"
#include "Core/Map.h"

#include "IO/Cursor.h"

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
	Widget* widget;
	FPS_counter fps;

	bool Init();
	void Event(SDL_Event* event, const Uint8* keyboardState);
	void Update();
	void Render(const double& interpolation);
	void CleanUp();

	void (*func_OnInit)();//TODO make it virtual
	void (*func_OnEvent)(SDL_Event* event, const Uint8* keyboardState);
};

#endif /* ENGINE_H_ */
