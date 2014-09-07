/*
 * Bullet.cpp
 *
 *  Created on: 26 авг. 2014 г.
 *      Author: snickers
 */

#include "Bullet.h"

Bullet::Bullet(const Vec2& pos, const double& angle) {
	rect.x = pos.x;
	rect.y = pos.y;
	born_time = SDL_GetTicks();
	speed = Vec2(0, -10).GetRotated(angle);
}

Bullet::~Bullet() {
	OnCleanUp();
}

void Bullet::OnUpdate() {
	if (SDL_GetTicks() - born_time > 1000) {
		delete this;
		return;
	}

	rect.x += speed.x;
	rect.y += speed.y;

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

void Bullet::OnRender() {

	SDL_SetRenderDrawColor(Window::GetRenderer(), 255, 255, 0, 255);
	SDL_RenderDrawLine(Window::GetRenderer(), rect.x, rect.y,
			rect.x + speed.x, rect.y + speed.y );
	SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 0, 255);

}

