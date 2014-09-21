/*
 * Ship.cpp
 *
 *  Created on: 17 сент. 2014 г.
 *      Author: snickers
 */

#include "Ship.h"
#include <iostream>

Ship::Ship() {
	rect.x = 0;
	rect.y = 0;
	speed = 0;
	direct = Vec2(0.0f, -1.0f);
}

Ship::~Ship() {
}

void Ship::OnUpdate() {

	if (speed > 1) { // >1 - anti stairs movement
		rect.x += direct.x * speed;
		rect.y += direct.y * speed;
		speed -= 0.1f;
	}

	if (keyb.isKeyDown(SDL_SCANCODE_UP)) {
		if (speed < MAX_SPEED)
			speed += 1.0f;
	}

	if (keyb.isKeyDown(SDL_SCANCODE_R)) {
		rect.x = 0;
		rect.y = 0;
		speed = 0;
		direct = Vec2(0.0f, -1.0f);
		angle = 0.0f;
	}

	if (keyb.isKeyDown(SDL_SCANCODE_LEFT)) {
		Rotate(-9.0f);
	} else if (keyb.isKeyDown(SDL_SCANCODE_RIGHT)) {
		Rotate(9.0f);
	}

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

void Ship::OnRender() {

	SDL_Rect tmpRect = { rect.x + Camera::X(), rect.y + Camera::Y(), rect.w,
			rect.h };
	if (Camera::InView(&tmpRect)) {
		SDL_SetRenderDrawColor(Window::GetRenderer(), 255, 255, 0, 255);
		SDL_RenderDrawLine(Window::GetRenderer(), rect.x, rect.y,
				rect.x + direct.x * speed * 10, rect.y + direct.y * speed * 10);
		SDL_RenderDrawRect(Window::GetRenderer(), &tmpRect);
		SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 0, 255);

		Surface::OnDraw(texture, nullptr, &tmpRect, angle);
	}

}

void Ship::Rotate(const float& da) {
	angle += da;
	direct = Vec2(0.0f, -1.0f).GetRotated(angle);
}
