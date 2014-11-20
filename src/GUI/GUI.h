/*
 * GUI.h
 *
 *  Created on: 13 авг. 2014 г.
 *      Author: snickers
 */

#ifndef GUI_H_
#define GUI_H_

#include <string>
#include <iostream>
#include <map>
#include <SDL2/SDL_ttf.h>
#include "../constants.h"

class GUI {
public:
	GUI();
	virtual ~GUI();

	static void Init();
	static TTF_Font* LoadFont(const std::string& fname, const int& ptsize);
	static void OnDraw(SDL_Renderer* render);
	static void OnCleanUp();

private:
	static std::map <std::string, TTF_Font* > Fonts;
};

#endif /* GUI_H_ */
