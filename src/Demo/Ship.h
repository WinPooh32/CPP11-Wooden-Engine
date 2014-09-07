/*
 * Ship.h
 *
 *  Created on: 26 авг. 2014 г.
 *      Author: snickers
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "../Entity.h"
#include "Bullet.h"
#include "../Vec2.h"
#include "../KeyBoard.h"
#include "../Timer.h"

class Ship: public Entity {
public:
	Ship();
	virtual ~Ship();

	virtual void OnUpdate();
	virtual void OnRender();

	void Force(const Vec2& f);
	void Rotate(const double& dAngle);
	double GetAngle();
private:
	const float MAX_SPEED = 5;
	//Вектор скорости корабля
	Vec2 speed;
	Timer gun_timer;
};

#endif /* SHIP_H_ */
