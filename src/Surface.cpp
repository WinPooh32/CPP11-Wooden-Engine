/*
 * Surface.cpp
 *
 *  Created on: 21 июля 2014 г.
 *      Author: snickers
 */

#include "Surface.h"

Surface::Surface() {
}

Surface::~Surface() {
}

SDL_Texture* Surface::LoadTexture(SDL_Renderer* render,
		const std::string fpath) {

	SDL_Texture* texture = IMG_LoadTexture(render, fpath.c_str());

	if( texture == nullptr){
		std::cout << "Can't load image \"" << fpath << "\"" << std::endl;
	}

	return texture;

}

void Surface::OnDraw(SDL_Renderer* render, SDL_Texture* texture,
		SDL_Rect* dstrect) {

	if (texture) {
		SDL_RenderCopy(render, texture, nullptr, dstrect);
	} else {
		SDL_SetRenderDrawColor(render, 255, 0, 255, 255);
		SDL_RenderFillRect(render, dstrect);
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	}

}

void Surface::OnDraw(SDL_Renderer* render, SDL_Texture* texture,
		SDL_Rect* srcrect, SDL_Rect* dstrect) {

	if (texture) {
		SDL_RenderCopy(render, texture, srcrect, dstrect);
	} else {
		SDL_SetRenderDrawColor(render, 255, 0, 255, 255);
		SDL_RenderFillRect(render, dstrect);
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	}

}
