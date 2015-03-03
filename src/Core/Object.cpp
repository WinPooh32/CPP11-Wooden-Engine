/*
 * Object.cpp
 *
 *  Created on: 03 марта 2015 г.
 *      Author: snickers
 */

#include <Core/Object.h>

std::list<Object*> Object::ObjList;
int Object::_last_id = 0;

Object::Object() {
	_owner = nullptr;
	_id = _last_id++;
	_type = OBJ_NONE;
}

Object::~Object() {
	if (_owner) {
		_owner->Disconnect(this);
	}

	while (!ChildrenList.empty()) {
		auto it = ChildrenList.begin();
		std::cout << (*it)->_id << std::endl;
		delete (*it);
	}
}

void Object::SetPos(const Vec2* new_pos) {
	_pos = *new_pos;

	if (_owner) {
		_draw_rect.x = _owner->_draw_rect.x + _pos.x;
		_draw_rect.y = _owner->_draw_rect.y + _pos.x;
	}

	if (!ChildrenList.empty())
		MoveChildern();
}

void Object::Move(const Vec2* delta_pos) {
	_pos.x += delta_pos->x;
	_pos.y += delta_pos->y;

	if (_owner) {
		_draw_rect.x = _owner->_draw_rect.x + _pos.x;
		_draw_rect.y = _owner->_draw_rect.y + _pos.x;
	}

	if (!ChildrenList.empty())
		MoveChildern();
}

Object* Object::GetOwner() {
	return _owner;
}

void Object::SetOwner(Object* obj) {
	_owner = obj;
}

void Object::Connect(Object* obj) {
	if(obj->_owner != nullptr){
		std::cout << "[Warning!] Object " << obj->_id << " already connected to " << obj->_owner->_id << std::endl;
	}else if (FindChild(obj) == ChildrenList.end()) {
		std::cout << "Object connected: " << obj->_id << std::endl;
		ChildrenList.push_back(obj);
		obj->SetOwner(this);
	}
}

void Object::Disconnect(Object* obj) {
	ChildrenList.remove(obj);
	obj->SetOwner(nullptr);
}

void Object::SetType(obj_type type) {
	_type = type;
}

obj_type Object::GetType() {
	return _type;
}

void Object::MoveChildern() {
	Vec2 null; // x=0 y=0
	for (auto it = ChildrenList.begin(); it != ChildrenList.end(); it++) {
		(*it)->Move(&null);
	}
}

std::list<Object*>::iterator Object::FindChild(Object* obj) {
	for (auto it = ChildrenList.begin(); it != ChildrenList.end(); it++) {
		if ((*it)->_id == obj->_id) {
			return it;
		}
	}
	return ChildrenList.end(); //not found
}

void Object::OnUpdate() {

}

void Object::OnRender() {

}

void Object::OnCollide(Object* obj) {

}
