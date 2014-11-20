/*
 * Widget.cpp
 *
 *  Created on: 24 сент. 2014 г.
 *      Author: snickers
 */

#include "Widget.h"

Widget::Widget(Widget* parent, int x, int y, int w, int h) {
	SetParent(parent);

	_rect = {x, y, w, h};

	SetVisible(true);
	std::cout << "OnWidgetCreate\n";
}

Widget::~Widget() {
	//Delete all chindren
	for (auto it = ChildrenList.begin(); it != ChildrenList.end(); it++) {
		if ((*it) != nullptr) {
			delete (*it);
		}
	}
	ChildrenList.clear();

	//Say parent to remove this child
	if (_parent != nullptr) {
		_parent->RemoveChild(this);
	}
}

void Widget::Move(const int& x, const int& y) {
	if (_parent != nullptr) {
		_rect.x = _parent->_rect.x + x;
		_rect.y = _parent->_rect.y + y;
	}else{
		_rect.x = x;
		_rect.y = y;
	}
}

void Widget::SetParent(Widget* parent) {

	_parent = parent;

	if (_parent != nullptr) {
		_parent->AddChild(this);
	}

}

void Widget::SetWidth(const int& width) {
	_rect.w = width;
}

void Widget::SetHeight(const int& height) {
	_rect.h = height;
}

void Widget::SetVisible(const bool& visible) {
	_visible = visible;
}

Widget* Widget::GetParent() {
	return _parent;
}

const SDL_Rect& Widget::GetRect() {
	return _rect;
}

const bool& Widget::isVisible() {
	return _visible;
}

void Widget::OnEvent(SDL_Event* event) {

}

void Widget::OnUpdate() {

}

void Widget::OnRender() {
	//do nothing
}

void Widget::OnUpdateChildren() {

	if (ChildrenList.empty()) {
		return;
	}

	for (auto it = ChildrenList.begin(); it != ChildrenList.end(); it++) {
		(*it)->OnUpdate();
		(*it)->OnUpdateChildren();
	}

}

void Widget::OnRenderChildren() {

	if (ChildrenList.empty() || !_visible) {
		return;
	}

	for (auto it = ChildrenList.begin(); it != ChildrenList.end(); it++) {
		(*it)->OnRender();
		(*it)->OnRenderChildren();
	}

}

void Widget::AddChild(Widget* child) {

	if (!ChildrenList.empty()) {
		for (auto it = ChildrenList.begin(); it != ChildrenList.end(); it++) {
			if (*it == child) {
				std::cout << "Widget::AddChild() DEBUG: child is existed."
						<< std::endl; //TODO Is checking for child existance needed?
				return;
			}
		}
	}

	ChildrenList.push_front(child);

}

void Widget::RemoveChild(Widget* child) {
	if (ChildrenList.empty() || child == nullptr) {
		return;
	}

	for (auto it = ChildrenList.begin(); it != ChildrenList.end(); it++) {
		if (*it == child) {
			std::cout << "Widget::RemoveChild() DEBUG: child was deleted."
					<< std::endl;
			ChildrenList.erase(it);
			return;
		}
	}

}
