/*
 * Entity.h
 *
 *  Created on: 23 июля 2014 г.
 *      Author: snickers
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <vector>
#include <iostream>

#include <SDL2/SDL.h>

#include "Window.h"
#include "Vec2.h"
#include "Surface.h"
#include "Animation.h"
#include "Camera.h"

class Entity {

public:
	Entity();
	virtual ~Entity();

	static std::vector<Entity*> EntityList;


	SDL_Rect rect, anim_rect;
	Uint8 anim_state;

	virtual bool OnLoad(std::string fname, short int width, short int height,
			short int max_frames);
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanUp();

	void Move(const Vec2& pos);

protected:
	double angle;
	SDL_Texture* texture;
	Animation anim_control;
};

#endif /* ENTITY_H_ */
