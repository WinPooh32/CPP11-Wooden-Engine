/*
 * Widget.cpp
 *
 *  Created on: 24 сент. 2014 г.
 *      Author: snickers
 */

#include "Widget.h"

Widget::Widget(Widget* parent = 0) {
	_parent = parent;
	_rect = {0, 0, 32, 32};
}

Widget::~Widget() {
	//Delete all chindren
	for(auto it = ChildrenList.begin(); it != ChildrenList.end(); it++){
		if(*it != nullptr){
			delete *it;
		}
	}
	ChildrenList.clear();

	//Say parent to remove this child
	if(_parent != nullptr){
		_parent->RemoveChild(this);
	}
}

void Widget::Move(const int& x, const int& y){
	_rect.x = x;
	_rect.y = y;
}

void Widget::SetWidth(const int& width){
	_rect.w = width;
}

void Widget::SetHeight(const int& height){
	_rect.h = height;
}

void Widget::OnEvent(SDL_Event* event){

}

void Widget::OnUpadate(){

}

void Widget::OnRender(){

}

void Widget::AddChild(Widget* child){
	for(auto it = ChildrenList.begin(); it != ChildrenList.end(); it++){
		if(*it == child){
			std::cout << "Widget::AddChild() DEBUG: child is existed." << std::endl; //TODO Is checking for child existance needed?
			return;
		}
	}
	ChildrenList.push_front(child);
}

void Widget::RemoveChild(Widget* child){
	for(auto it = ChildrenList.begin(); it != ChildrenList.end(); it++){
		if(*it == child){
			std::cout << "Widget::AddChild() DEBUG: child was deleted." << std::endl;
			ChildrenList.erase(it);
			return;
		}
	}
}
