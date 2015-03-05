/*
 * Sprite.cpp
 *
 *  Created on: 05 марта 2015 г.
 *      Author: snickers
 */

#include <Render/Sprite.h>

Sprite::Sprite() {
	_texture = nullptr;
}

Sprite::~Sprite() {

}

void Sprite::Draw(){
	//TODO Make animation
	Surface::OnDraw(_texture, &_rect);
}

void Sprite::SetPos(const Vec2& new_pos){
	_rect.x = new_pos.x;
	_rect.y = new_pos.y;
}

void Sprite::SetSize(const Vec2& size){
	_rect.w = size.x;
	_rect.h = size.y;
}

void Sprite::SetTexture(SDL_Texture* texture){
	_texture = texture;
}
