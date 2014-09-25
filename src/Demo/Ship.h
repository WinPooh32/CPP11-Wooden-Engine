/*
 * Ship.h
 *
 *  Created on: 17 сент. 2014 г.
 *      Author: snickers
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "../Entity.h"
#include "../Vec2.h"
#include "../KeyBoard.h"
#include "../Timer.h"
#include "Bullet.h"

class Ship: public Entity {
public:
	Ship();
	virtual ~Ship();
	void OnUpdate();
	void OnRender();
	void Rotate(const float& da);

	const Uint8 MAX_SPEED = 20;
	const float RAD = 3.14 / 180;
	KeyBoard keyb;
	float speed;
	Vec2 direct;
	Timer gun_timer;
};

#endif /* SHIP_H_ */
