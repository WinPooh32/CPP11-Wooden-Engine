/*
 * GUI.cpp
 *
 *  Created on: 13 авг. 2014 г.
 *      Author: snickers
 */

#include "GUI.h"

GUI::GUI() {
	// TODO Auto-generated constructor stub

}

GUI::~GUI() {
	// TODO Auto-generated destructor stub
}

void GUI::Init(){

	//TTF FONTS INIT---------------------------------------------------
	if (TTF_Init() == -1) {
		std::cout << "TTF_Init Error: " << SDL_GetError() << std::endl;
	}

}

void GUI::OnDrawText(SDL_Renderer* render){

}
