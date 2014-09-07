/*
 * Cursor.cpp
 *
 *  Created on: 26 июля 2014 г.
 *      Author: Admin
 */

#include "Cursor.h"

SDL_Texture* Cursor::cursor_texture = nullptr;
SDL_Rect Cursor::cursor_rect;

void Cursor::Init(SDL_Texture* cursor, int w, int h){
	SDL_ShowCursor(0);
	SDL_SetRelativeMouseMode(SDL_bool(0));

	if(cursor != nullptr){
		cursor_texture = cursor;
	}

	cursor_rect = {0,0,w,h};
}

void Cursor::Update(SDL_Window* win){
	SDL_GetMouseState( &(cursor_rect.x),  &(cursor_rect.y) );
	//TODO Cursor issue with logic resolution :<(
}

void Cursor::Draw(){
	Surface::OnDraw(cursor_texture, &cursor_rect);
}

int Cursor::X(){
	return cursor_rect.x;
}

int Cursor::Y(){
	return cursor_rect.y;
}
