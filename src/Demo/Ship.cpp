/*
 * Ship.cpp
 *
 *  Created on: 26 авг. 2014 г.
 *      Author: snickers
 */

#include "Ship.h"

#include <iostream>

Ship::Ship() {
	angle = 0.0f;
}

Ship::~Ship() {

}

void Ship::OnUpdate() {

	if (speed.GetLength() > 0.5f) {

		rect.x += speed.x;
		rect.y += speed.y;

		speed -= speed.GetNormalized() * 0.1;
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

	//Обрабатываем клавиатуру
	KeyBoard board;

	if (board.isKeyDown(SDL_SCANCODE_UP)) {
		this->Force(Vec2(0, -1.0f));
	} else if (board.isKeyDown(SDL_SCANCODE_DOWN)) {
		//ship.Force(Vec2(0, 0.2f));
	}

	if (board.isKeyDown(SDL_SCANCODE_LEFT)) {
		this->Rotate(-3.0f);
	} else if (board.isKeyDown(SDL_SCANCODE_RIGHT)) {
		this->Rotate(3.0f);
	}


	if (board.isKeyDown(SDL_SCANCODE_SPACE)) {
		gun_timer.Start();

		if ( gun_timer.GetTime() > 200 ) {
			Vec2 vect;
			//vect = vect.GetRotated(ship.GetAngle());
			vect.x += this->rect.x + this->rect.w * 0.5f;
			vect.y += this->rect.y + this->rect.h * 0.5f;
			new Bullet(vect, angle);
			gun_timer.Stop();
		}
	}

}

void Ship::OnRender() {

	SDL_Rect tmpRect = { rect.x + Camera::X(), rect.y + Camera::Y(), rect.w,
			rect.h };
	if (Camera::InView(&tmpRect)) {
		Surface::OnDrawRect(&tmpRect, 255, 0, 255, 255);
		Surface::OnDraw(texture, nullptr, &tmpRect, angle);
	}

}

void Ship::Force(const Vec2& f) {
	if (speed.GetLength() < MAX_SPEED) {
		Vec2 tmp_vec = f;
		speed += tmp_vec.GetRotated(angle);
	}
}

void Ship::Rotate(const double& dAngle) {
	angle += dAngle;

	if(angle > 360){
		angle = (int)angle % 360;
	}else if(angle < -360){
		angle = 360 - angle;
	}
}

double Ship::GetAngle() {
	return angle;
}
