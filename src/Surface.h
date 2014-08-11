/*
 * Surface.h
 *
 *  Created on: 21 июля 2014 г.
 *      Author: snickers
 */

#ifndef SURFACE_H_
#define SURFACE_H_

#include <string>
#include <iostream>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Surface {

public:
	static SDL_Texture* LoadTexture(SDL_Renderer* render, std::string fpath);
	static void OnDraw(SDL_Renderer* render, SDL_Texture* texture,
			SDL_Rect* dstrect);
	static void OnDraw(SDL_Renderer* render, SDL_Texture* texture,
			SDL_Rect* srcrect, SDL_Rect* dstrect);
	static void OnDrawRect(SDL_Renderer* render, SDL_Rect* rect,
			const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
	static void OnCleanUp();

private:
	static std::map <std::string, SDL_Texture* > Textures;

};

#endif /* SURFACE_H_ */
