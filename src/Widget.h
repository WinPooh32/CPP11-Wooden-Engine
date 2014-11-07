/*
 * Widget.h
 *
 *  Created on: 24 сент. 2014 г.
 *      Author: snickers
 */

#ifndef WIDGET_H_
#define WIDGET_H_

#include <iostream>
#include <list>

#include <SDL2/SDL.h>

class Widget {
public:
	Widget(Widget* parent);
	virtual ~Widget();

	void Move(const int& x, const int& y);
	void SetWidth(const int& width);
	void SetHeight(const int& height);

	virtual void OnEvent(SDL_Event* event);
	virtual void OnUpadate();
	virtual void OnRender();

protected:
	SDL_Rect _rect;

private:
	Widget* _parent;
	std::list<Widget*> ChildrenList;

	void AddChild(Widget* child);
	void RemoveChild(Widget* child);
};

#endif /* WIDGET_H_ */
