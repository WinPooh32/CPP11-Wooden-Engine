/*
 * Widget.h
 *
 *  Created on: 24 сент. 2014 г.
 *      Author: snickers
 */

#ifndef WIDGET_H_
#define WIDGET_H_

#include <SDL2/SDL.h>

class Widget {
public:
	Widget();
	virtual ~Widget();

	void Move(int x, int y);

protected:
	SDL_Rect rect;
};

#endif /* WIDGET_H_ */
