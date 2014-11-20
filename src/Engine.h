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
#include "GUI/Cursor.h"

#include "Render/Camera.h"
#include "Render/Surface.h"
#include "Render/Animation.h"

#include "Core/Entity.h"
#include "Core/Map.h"

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
	bool Core_Init();
	void Core_Event(SDL_Event* event, const Uint8* keyboardState);
	void Core_Update();
	void Core_Render(const double& interpolation);
	void Core_CleanUp();

	virtual void OnInit();
	virtual void OnEvent(SDL_Event* event, const Uint8* keyboardState);
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanUp();
};

#endif /* ENGINE_H_ */
