#include <iostream>

#include "Engine.h"
#include "constants.h"
#include "GUI/Cursor.h"
#include "Core/sys.h"
#include "Core/FPScounter.h"
#include "Demo/Ship.h"

Widget* widget;
TextBox* text;
TextBox* test, * test2;

FPS_counter fps;

void Engine::OnInit(){
	Window::SetMode(800, 600, false, "Shot yourself!");

	Ship *ship = new Ship;
	ship->OnLoad("ship.png", 44, 44, 0);
       
	widget = new Widget();
	text = new TextBox(widget);
        text->Move(100, 100);
        
        test = new TextBox(text);
        test->SetText("Пробный текст\nНовая строка");
        test->Move(0, 12);
        
        test2 = new TextBox(test);
        test2->SetText("Тест2");
        test2->Move(0, 30);
}

void Engine::OnEvent(SDL_Event* event, const Uint8* keyboardState){

}

void Engine::OnUpdate(){
	fps.OnUpdate();

	text->SetText("FPS: " + int_to_str(fps.GetFPS()));
	
            if(Cursor::button == SDL_BUTTON_LEFT){
                text->Move(Cursor::X() - 32, Cursor::Y() + 32);
            }
        
        //text->Move(Cursor::X() - 32, Cursor::Y() + 32);
	if (widget != nullptr) {//TODO move to Window
		widget->OnUpdate();
		widget->OnUpdateChildren();
	}

}

void Engine::OnRender(){

	if (widget != nullptr) {
		widget->OnRender();
		widget->OnRenderChildren();
	}

}

void Engine::OnCleanUp(){
	delete widget;
}

#undef main
int main()
{
	//-static-libgcc -static-libstdc++
	Engine engine;
	engine.Start();
	return 0;
}
