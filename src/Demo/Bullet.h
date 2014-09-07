/*
 * Bullet.h
 *
 *  Created on: 26 авг. 2014 г.
 *      Author: snickers
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "../Entity.h"
#include "../Vec2.h"

class Bullet: public Entity {
public:
	Bullet(const Vec2& pos, const double& angle);
	virtual ~Bullet();

	Uint32 born_time;
	virtual void OnUpdate();
	virtual void OnRender();

private:
	Vec2 speed;
};

#endif /* BULLET_H_ */
