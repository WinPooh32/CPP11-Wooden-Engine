/*
 * Surface.cpp
 *
 *  Created on: 21 июля 2014 г.
 *      Author: snickers
 */

#include "Surface.h"

std::map<std::string, SDL_Texture*> Surface::Textures;

SDL_Texture* Surface::LoadTexture(const std::string fpath) {

	std::string real_path = SPRITES_PATH + fpath;

	std::cout << "Loading texture \"" << real_path << "\"..." << std::endl;

	SDL_Texture* texture = Textures[fpath];

	if (texture == nullptr) {

		texture = IMG_LoadTexture(Window::GetRenderer(), real_path.c_str());

		if (texture != nullptr) {
			Textures[fpath] = texture;
		} else {
			std::cout << " >> !WARNING! << " << SDL_GetError() << std::endl;
			if (!Window::GetRenderer())
				std::cout << " Is Renderer initialized?" << std::endl;
		}

	}

	return texture;
}

void Surface::OnDraw(SDL_Texture* texture, SDL_Rect* dstrect) {

	if (texture) {
		SDL_RenderCopy(Window::GetRenderer(), texture, nullptr, dstrect);
	} else {
		DrawRect(dstrect, COLOR_MAGENTA);
	}

}

void Surface::OnDraw(SDL_Texture* texture, SDL_Rect* srcrect,
		SDL_Rect* dstrect) {

	if (texture) {
		SDL_RenderCopy(Window::GetRenderer(), texture, srcrect, dstrect);
	} else {
		DrawRect(dstrect, COLOR_MAGENTA);
	}

}

void Surface::OnDraw(SDL_Texture* texture, SDL_Rect* srcrect, SDL_Rect* dstrect,
		const double& angle) {
	if (texture) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		SDL_RenderCopyEx(Window::GetRenderer(), texture, srcrect, dstrect, angle, nullptr, flip);
	} else {
		DrawRect(dstrect, COLOR_MAGENTA);
	}
}

void Surface::DrawRect(SDL_Rect* rect, const Uint8 r, const Uint8 g,
		const Uint8 b, const Uint8 a) {

	SDL_SetRenderDrawColor(Window::GetRenderer(), r, g, b, a);
	SDL_RenderFillRect(Window::GetRenderer(), rect);
	SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 0, 255);

}

void DrawRect(SDL_Rect* rect, SDL_Color* color){	
        SDL_SetRenderDrawColor(Window::GetRenderer(), color.r, color.g, color.b, 
                color.a);
	SDL_RenderFillRect(Window::GetRenderer(), rect);
	SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 0, 255);    
}

void Surface::OnCleanUp() {

	auto iterator = Textures.begin();

	while (iterator != Textures.end()) {
		SDL_DestroyTexture((*iterator).second);
		iterator++;
	}

	Textures.clear();
}
