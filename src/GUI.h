/*
 * GUI.h
 *
 *  Created on: 13 авг. 2014 г.
 *      Author: snickers
 */

#ifndef GUI_H_
#define GUI_H_

#include <iostream>
#include <SDL2/SDL_ttf.h>

class GUI {
public:
	GUI();
	virtual ~GUI();

	static void Init();

	static void OnDrawText(SDL_Renderer* render);
};

#endif /* GUI_H_ */
