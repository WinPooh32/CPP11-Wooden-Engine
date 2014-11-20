/*
 * GUI.cpp
 *
 *  Created on: 13 авг. 2014 г.
 *      Author: snickers
 */

#include "GUI.h"

std::map <std::string, TTF_Font*> GUI::Fonts;

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
/*Open and store font with individual size*/
TTF_Font* GUI::LoadFont(const std::string& fpath, const int& ptsize){

	std::string real_path = FONTS_PATH + fpath;
	std::string size_path = fpath + std::to_string(ptsize);

	//Store font with size
	TTF_Font* font = Fonts[size_path];

	if (font == nullptr) {

		font = TTF_OpenFont(real_path.c_str(), ptsize);

		if (font != nullptr) {
			Fonts[size_path] = font;
		} else {
			std::cout << " >> !WARNING! << " << SDL_GetError() << std::endl;
		}

	}
	return font;
}

void GUI::OnCleanUp(){

	//Cleaning fonts
	auto iterator = Fonts.begin();
	while( iterator != Fonts.end()){
		TTF_CloseFont((*iterator).second);
		iterator++;
	}
	Fonts.clear();

	//Cleaning Widgets
	//...
}

