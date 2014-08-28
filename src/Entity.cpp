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
	angle = 0.0f;
	rect.x = rect.y = 0.0f;
	rect.w = rect.h = 0;
	anim_state = 0;
	anim_rect = rect;

	EntityList.push_back(this);
}

Entity::~Entity() {
}

bool Entity::OnLoad(std::string fname, short int width, short int height,
		short int max_frames) {
	texture = Surface::LoadTexture(fname);

	rect.w = width;
	rect.h = height;

	anim_rect = rect;

	anim_control.max_frames = max_frames;
	return true;
}

void Entity::OnUpdate() {
	anim_control.OnAnimation();
}

void Entity::OnRender() {

	SDL_Rect tmpRect = { rect.x + Camera::X(), rect.y + Camera::Y(), rect.w,
			rect.h };
	if (Camera::InView(&tmpRect)) {
		anim_rect.x = anim_rect.w * anim_control.GetCurrentFrame();
		if (this->anim_control.max_frames > 0)
			Surface::OnDraw(texture, &anim_rect, &tmpRect);
		else
			Surface::OnDraw(texture, &tmpRect);
	}

}

void Entity::OnCleanUp() {
	for (auto it = EntityList.begin(); it != EntityList.end(); it++) {
		if (*it == this) {
			EntityList.erase(it);
			if(!*it) std::cout << "NULL ENTITY\n";
			//TODO Memory leak on entity clean up?
			break;
		}
	}
}
