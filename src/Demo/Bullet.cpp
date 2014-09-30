/*
 * Bullet.cpp
 *
 *  Created on: 24 сент. 2014 г.
 *      Author: snickers
 */

#include "Bullet.h"
#include <iostream>

Bullet::Bullet(const Vec2& pos, const Vec2& direct, const double& angle) {
	rect.x = pos.x;
	rect.y = pos.y;
	born_time = SDL_GetTicks();
	this->direct = direct;
}

Bullet::~Bullet() {
	OnCleanUp();
}

void Bullet::OnUpdate(){
	if (SDL_GetTicks() - born_time > 1000) {
		delete this;
		return;
	}

	rect.x += direct.x * SPEED;
	rect.y += direct.y * SPEED;

	//check borders
	//move ship if it not in cam view
	if (rect.x + Camera::X() + rect.w < 0) {
		Move(Vec2(Camera::cam_rect.w + rect.w, rect.y));
	} else if (rect.x + Camera::X() - rect.w > Camera::cam_rect.w) {
		Move(Vec2(-rect.w, rect.y));
	} else if (rect.y + Camera::Y() + rect.h < 0) {
		Move(Vec2(rect.x, Camera::cam_rect.h + rect.h));
	} else if (rect.y + Camera::Y() - rect.h > Camera::cam_rect.h) {
		Move(Vec2(rect.x, -rect.h));
	}

}

void Bullet::OnRender(const double& interpolation){

	int next_pos_X = direct.x * interpolation * SPEED;
	int next_pos_Y = direct.y * interpolation * SPEED;
	int new_x = rect.x + next_pos_X;
	int new_y = rect.y + next_pos_Y;

	SDL_SetRenderDrawColor(Window::GetRenderer(), 255, 255, 0, 255);
	SDL_RenderDrawLine(
			Window::GetRenderer(),
			new_x,
			new_y,
			new_x + direct.x * 10,
			new_y + direct.y * 10
			);
	SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 30, 255);
}
