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
    SDL_Rect rect4draw = {screen_X, screen_Y, _rect.w, _rect.h};
    Surface::DrawRect(&rect4draw, 204, 204, 204, 100); //gray rect
    for(auto it = Lines.begin(); it != Lines.end(); it++){
        (*it)->Draw();
    }
}


void TextBox::Move(const int& x, const int& y){
    Widget::Move(x, y);
    SetPos(x,y);
}

void TextBox::SetPos(const int& x, const int& y){
    int i = 0;
    for(auto it = Lines.begin(); it != Lines.end(); it++){
        (*it)->SetPos(screen_X, screen_Y + i*STEP_LINE);
        i++;
    }
}

void TextBox::SetText(const std::string& str){
    for(auto it = Lines.begin(); it != Lines.end(); it++){
        delete(*it);
    }
    Lines.clear();
    
    //_text.SetText(str);
    bool done = false;
    int cur_p = 0; 
    int last_p = 0;
    int len;
    int x = screen_X;
    int y = screen_Y;
    int max = 0;
    
    
    while(!done){
       cur_p = str.find('\n', ++cur_p);
       if(cur_p == -1){
           cur_p = str.length();
           done = true;
       }
       len = cur_p - last_p;
       if(len > 0){
           Text* text_line = new Text;
           text_line->Init(x, y, str.substr(last_p, len), "PressStart2P.ttf", 12);
           y += STEP_LINE;
           Lines.push_back(text_line);
           
           //Set max for rect width
           if(text_line->GetW() > max) max = text_line->GetW();
       }
       last_p = 1 + cur_p;
    }
    
    _rect.w = max;
    _rect.h = Lines.size() * 12;// * ptsize
}

