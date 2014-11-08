/*
 * TextBox.h
 *
 *  Created on: 08 нояб. 2014 г.
 *      Author: snickers
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include "Widget.h"
#include "Text.h"

class TextBox: public Widget {
public:
	TextBox(Widget* parent = nullptr, int x = 0, int y = 0, int w = 0,
			int h = 0);
	virtual ~TextBox();

	virtual void OnEvent(SDL_Event* event);//TODO to implement it
	virtual void OnUpdate();
	virtual void OnRender();

	void SetPos(const int& x, const int& y);
	void SetText(const std::string& str);


private:
	Text _text;
};

#endif /* TEXTBOX_H_ */
