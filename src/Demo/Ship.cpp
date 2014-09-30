/*
 * Ship.cpp
 *
 *  Created on: 17 сент. 2014 г.
 *      Author: snickers
 */

#include "Ship.h"
#include <iostream>
#include <cmath>

#include "../Window.h"

Ship::Ship() {
	rect.x = 0;
	rect.y = 0;
	speed = 0;
	angle = 0;
	direct = Vec2(1.0f, 0.0f);
}

Ship::~Ship() {
}

void Ship::OnUpdate() {

	//Move ship
	if (speed > 1) { // >1 - anti stairs movement
		rect.x += direct.x * speed; //speed*sin(angle);//(int)(direct.x * speed);
		rect.y += direct.y * speed; //speed*cos(angle);//(int)(direct.y * speed);
		speed -= 0.5f;
	}

	if (keyb.isKeyDown(SDL_SCANCODE_UP)) {
		if (speed < MAX_SPEED)
			speed += 1.0f;
	}

	if (keyb.isKeyDown(SDL_SCANCODE_R)) {
		rect.x = 0;
		rect.y = 0;
		speed = 0;
		direct = Vec2(1.0f, 0.0f);
		angle = 0.0f;
	}


	if (keyb.isKeyDown(SDL_SCANCODE_KP_PLUS)){
		Window::SetMode(Window::GetWidth() + 64, Window::GetHeight() + 64, false, "Проба пера");
		Camera::SetViewport(Window::GetWidth(),  Window::GetHeight());
	}
	if (keyb.isKeyDown(SDL_SCANCODE_KP_MINUS)){
		Window::SetMode(Window::GetWidth() - 64, Window::GetHeight() - 64, false, "Проба пера");
		Camera::SetViewport(Window::GetWidth(),  Window::GetHeight());
	}

	if (keyb.isKeyDown(SDL_SCANCODE_LEFT)) {
		Rotate(-9.0f);
	} else if (keyb.isKeyDown(SDL_SCANCODE_RIGHT)) {
		Rotate(9.0f);
	}
	if (keyb.isKeyDown(SDL_SCANCODE_SPACE)) {
		gun_timer.Start();

		if ( gun_timer.GetTime() > 200 ) {
			Vec2 vect;
			vect.x = this->rect.x + this->rect.w * 0.5f;
			vect.y = this->rect.y + this->rect.h * 0.5f;
			new Bullet(vect, direct, angle);
			gun_timer.Stop();
		}
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

void Ship::OnRender(const double& interpolation) {

	float interpolated_speed;
	if(speed > 1){
		interpolated_speed = speed * interpolation;
	}else{
		interpolated_speed = 0;
	}

	SDL_Rect tmpRect = {
			rect.x + Camera::X() + (int)(direct.x * interpolated_speed),
			rect.y + Camera::Y() + (int)(direct.y * interpolated_speed),
			rect.w,
			rect.h };

	if (Camera::InView(&tmpRect)) {

		//TODO REMOVE LINE AND SQUARE drawing
		//Линия и квадратик
		/*SDL_SetRenderDrawColor(Window::GetRenderer(), 255, 255, 0, 255);
		SDL_RenderDrawLine(Window::GetRenderer(), rect.x + 0.5f * rect.w,
				rect.y + 0.5f * rect.h,
				rect.x + 0.5f * rect.w + direct.x * speed * 10,
				rect.y + 0.5f * rect.h + direct.y * speed * 10);
		SDL_RenderDrawRect(Window::GetRenderer(), &tmpRect);
		SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 0, 255);
		*/
		Surface::OnDraw(texture, nullptr, &tmpRect, angle+90);
	}

}

void Ship::Rotate(const float& da) {
	angle += da;
	//direct = Vec2(0.0f , -1.0f).GetRotated(angle);
	direct = Vec2(cos(angle * RAD), sin(angle * RAD));
}
