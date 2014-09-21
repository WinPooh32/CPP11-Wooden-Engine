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

class Ship: public Entity {
public:
	Ship();
	virtual ~Ship();
	void OnUpdate();
	void OnRender();
	void Rotate(const float& da);

	const Uint8 MAX_SPEED = 15;
	KeyBoard keyb;
	float speed;
	Vec2 direct;
};

#endif /* SHIP_H_ */
