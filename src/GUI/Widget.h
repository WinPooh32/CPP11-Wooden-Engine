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
	Widget(Widget* parent = nullptr, int x = 0, int y = 0, int w = 0,
			int h = 0);
	virtual ~Widget();

	void Move(const int& x, const int& y);

	void SetParent(Widget* parent);
	void SetWidth(const int& width);
	void SetHeight(const int& height);
	void SetVisible(const bool& visible);

	Widget* GetParent();
	const SDL_Rect& GetRect();
	const bool& isVisible();

	virtual void OnEvent(SDL_Event* event);//TODO implement
	virtual void OnUpdate();
	virtual void OnRender();

	void OnUpdateChildren();
	void OnRenderChildren();

protected:
	SDL_Rect _rect;
	int screen_X; //Позиция на экране
	int screen_Y;

private:
	Widget* _parent;
	bool _visible;
	std::list<Widget*> ChildrenList;

	void AddChild(Widget* child);
	void RemoveChild(Widget* child);
};

#endif /* WIDGET_H_ */
