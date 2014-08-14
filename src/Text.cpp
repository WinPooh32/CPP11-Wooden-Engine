/*
 * Text.cpp
 *
 *  Created on: 13 авг. 2014 г.
 *      Author: snickers
 */

#include "Text.h"

Text::Text() {
	_font = nullptr;
	_texture = nullptr;
	_visible = false;
	_rect = {0, 0, 0, 0};
	_color = {255, 255, 255, 255}; //White color
}

Text::~Text() {
	TTF_CloseFont(_font); //TODO CRASH if before TTF_Quit()
	SDL_DestroyTexture(_texture);
}

void Text::Init(SDL_Renderer* render, const int x, const int y,
		const std::string text, const std::string font, const int ptsize) {

	_visible = true;
	_font = TTF_OpenFont(font.c_str(), ptsize);
	SetPos(x, y);
	SetText(render, text);

}

void Text::Draw(SDL_Renderer* render) {
	if (_visible) {
		Surface::OnDraw(render, _texture, &_rect);
	}
}

void Text::Show(const bool enabled) {
	_visible = enabled;
}

void Text::SetColor(const SDL_Color color) {
	_color = color;
}

void Text::SetText(SDL_Renderer* render, const std::string text) {
	_text = text;
	GetTexture(render);
}

void Text::SetPos(const int x, const int y) {
	_rect.x = x;
	_rect.y = y;
}

void Text::GetTexture(SDL_Renderer* render) {

	if (_font) {
		if (_texture) {
			SDL_DestroyTexture(_texture);
			_texture = nullptr;
		}

		SDL_Surface* surface = TTF_RenderText_Solid(_font, _text.c_str(),
				_color);
		_texture = SDL_CreateTextureFromSurface(render, surface);
		SDL_QueryTexture(_texture, nullptr, nullptr, &_rect.w, &_rect.h);

		SDL_FreeSurface(surface);
	} else {
		std::cout << "Null font at text: " << _text << std::endl;
	}

}
