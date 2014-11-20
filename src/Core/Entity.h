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

#include "GUI/Window.h"
#include "Core/Vec2.h"
#include "Render/Surface.h"
#include "Render/Animation.h"
#include "Render/Camera.h"

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
	virtual void OnRender(const double& interpolation);
	virtual void OnCleanUp();

	void Move(const Vec2& pos);

protected:
	int angle;
	SDL_Texture* texture;
	Animation anim_control;
};

#endif /* ENTITY_H_ */
