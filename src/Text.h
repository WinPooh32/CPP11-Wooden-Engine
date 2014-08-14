/*
 * Text.h
 *
 *  Created on: 13 авг. 2014 г.
 *      Author: snickers
 */

#ifndef TEXT_H_
#define TEXT_H_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Surface.h"

class Text {
public:
	Text();
	virtual ~Text();

	void Init(SDL_Renderer* render, const int x, const int y,
			const std::string text, const std::string font, const int ptsize);

	void Draw(SDL_Renderer* render);

	void Show(const bool enabled);
	void SetColor(const SDL_Color color);
	void SetText(SDL_Renderer* render, const std::string text);
	//void SetFont()
	void SetPos(const int x, const int y);

private:
	SDL_Texture* _texture;
	TTF_Font* _font;

	std::string _text;
	SDL_Rect _rect;
	SDL_Color _color;

	bool _visible;

	void GetTexture(SDL_Renderer* render);

};

#endif /* TEXT_H_ */
