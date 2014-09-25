/*
 * Bullet.h
 *
 *  Created on: 24 сент. 2014 г.
 *      Author: snickers
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "../Entity.h"
#include "../Vec2.h"

class Bullet: public Entity {
public:
	Bullet(const Vec2& pos, const Vec2& direct, const double& angle);
	virtual ~Bullet();

	void OnUpdate();
	void OnRender();

	const float RAD = 3.14 / 180;
	const float SPEED = 30;
	Uint32 born_time;
	Vec2 direct;
};

#endif /* BULLET_H_ */
