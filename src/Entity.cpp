/*
 * Entity.cpp
 *
 *  Created on: 23 июля 2014 г.
 *      Author: snickers
 */

#include "Entity.h"
#include <iostream>

std::vector<Entity*> Entity::EntityList;

Entity::Entity() {
	texture = nullptr;
	rect.x = rect.y = 0.0f;
	rect.w = rect.h = 0;
	anim_state = 0;
	anim_rect = rect;

	EntityList.push_back(this);
}

Entity::~Entity() {
	//this->OnCleanUp();
}

bool Entity::OnLoad(SDL_Renderer* render, std::string fname, short int width,
		short int height, short int max_frames) {
	texture = Surface::LoadTexture(render, fname);

	rect.w = width;
	rect.h = height;

	anim_rect = rect;

	anim_control.max_frames = max_frames;
	return true;
}

void Entity::OnUpdate() {
	anim_control.OnAnimation();
}

void Entity::OnRender(SDL_Renderer* render) {

	SDL_Rect tmpRect = { rect.x + Camera::X(), rect.y + Camera::Y(), rect.w,
			rect.h };
	if (Camera::InView(&tmpRect)) {
		anim_rect.x = rect.w * anim_control.GetCurrentFrame();
		if (this->anim_control.max_frames > 0)
			Surface::OnDraw(render, texture, &anim_rect, &tmpRect);
		else
			Surface::OnDraw(render, texture, &tmpRect);
	}

}

void Entity::OnCleanUp() {
	auto it = EntityList.begin();
	bool done = false;

	while (it != EntityList.end() || done) {
		if (*it == this) {
			EntityList.erase(it);
			done = true;
		} else {
			it++;
		}
	}
}
