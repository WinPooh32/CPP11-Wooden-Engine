/*
 * TextBox.cpp
 *
 *  Created on: 08 нояб. 2014 г.
 *      Author: snickers
 */

#include "TextBox.h"

TextBox::TextBox(Widget* parent, int x, int y, int w,
		int h) {

	SetParent(parent);
	_rect = {x, y, w, h};

	SetVisible(true);
	_text.Init(x, y, "Пробный текст :)", "PressStart2P.ttf", 12);
}

TextBox::~TextBox() {
	// TODO Auto-generated destructor stub
}

void TextBox::OnEvent(SDL_Event* event){

}

void TextBox::OnUpdate(){

}

void TextBox::OnRender(){
	_text.Draw();
}

void TextBox::SetPos(const int& x, const int& y){
	_rect.x = x;
	_rect.y = y;
	_text.SetPos(x, y);
}

void TextBox::SetText(const std::string& str){
	_text.SetText(str);
}

