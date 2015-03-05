/*
 * Object.h
 *
 *  Created on: 03 March 2015 г.
 *      Author: WinPooh32
 */

#ifndef SRC_CORE_OBJECT_H_
#define SRC_CORE_OBJECT_H_

#include <iostream>
#include <list>
#include <vector>

#include <SDL2/SDL.h>

#include <Core/Vec2.h>
#include <Render/Surface.h>

enum obj_type{
	OBJ_NONE = 0,
	OBJ_ENTITY,
	OBJ_GROUND
};

/*
enum obj_draw_layer{
//TODO objects draw layers
};
*/

class Object {
public:
	Object();
	virtual ~Object();

	void SetPos(const Vec2* new_pos);
	void Move(const Vec2* delta_pos);

	Object* GetOwner();
	void SetOwner(Object* obj);
	void Connect(Object* obj);
	void Disconnect(Object* obj);

	void SetType(obj_type type);
	obj_type GetType();

	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCollide(Object* obj);

protected:
	Vec2 _pos;
	Vec2 _global_pos;
	SDL_Rect _draw_rect;

private:
	static std::list<Object*> ObjList;
	static int _last_id; //last created object id

	std::list<Object*> ChildrenList;
	//std::list< /*subsystem type*/ > _subsystems; //TODO subsystem list

	int _id;
	obj_type _type;
	Object* _owner;

	void MoveChildern();
	std::list<Object*>::iterator FindChild(Object* obj);

	void UpdateChildren();
	void RenderChildren();
};

#endif /* SRC_CORE_OBJECT_H_ */
