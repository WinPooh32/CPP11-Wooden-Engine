/*
 * Surface.cpp
 *
 *  Created on: 21 июля 2014 г.
 *      Author: snickers
 */

#include "Surface.h"

std::map <std::string, SDL_Texture*> Surface::Textures;

SDL_Texture* Surface::LoadTexture(SDL_Renderer* render,
		const std::string fpath) {

	std::cout << "Loading texture \"" << fpath << "\"..." << std::endl;

	SDL_Texture* texture = Textures[fpath];


	if (texture == nullptr) {

		texture = IMG_LoadTexture(render, fpath.c_str());

		if (texture != nullptr) {
			Textures[fpath] = texture;
		} else {
			std::cout << " >> !WARNING! << " << SDL_GetError() << std::endl;
		}

	}

	return texture;
}

void Surface::OnDraw(SDL_Renderer* render, SDL_Texture* texture,
		SDL_Rect* dstrect) {

	if (texture) {
		SDL_RenderCopy(render, texture, nullptr, dstrect);
	} else {
		OnDrawRect(render, dstrect, 255, 0, 255, 255);
	}

}

void Surface::OnDraw(SDL_Renderer* render, SDL_Texture* texture,
		SDL_Rect* srcrect, SDL_Rect* dstrect) {

	if (texture) {
		SDL_RenderCopy(render, texture, srcrect, dstrect);
	} else {
		OnDrawRect(render, dstrect, 255, 0, 255, 255);
	}

}

void Surface::OnDrawRect(SDL_Renderer* render, SDL_Rect* rect, const Uint8 r,
		const Uint8 g, const Uint8 b, const Uint8 a) {

	SDL_SetRenderDrawColor(render, r, g, b, a);
	SDL_RenderFillRect(render, rect);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

}

void Surface::OnCleanUp() {

	auto iterator = Textures.begin();

	while (iterator != Textures.end()) {
		SDL_DestroyTexture((*iterator).second);
		iterator++;
	}

	Textures.clear();
}
