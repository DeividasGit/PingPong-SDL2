#include "SDL.h"
#include <iostream>
#include "paddleplayer2.h"
#include "gameobject.h"


PaddlePlayer2::PaddlePlayer2(){
}

PaddlePlayer2::~PaddlePlayer2(){
}

PaddlePlayer2::PaddlePlayer2(int x, int y):Paddle(x,y){
    this->rect.x = x;
    this->rect.y = y;
    this->rect.h = 80;
    this->rect.w = 10;
}

void PaddlePlayer2::handle_input(){
       const auto state = SDL_GetKeyboardState(NULL);

        SDL_PumpEvents();
		if(state[SDL_SCANCODE_UP]){
                this->x +=0;
                this->y -=3.08;
		}
		if(state[SDL_SCANCODE_DOWN]){
                this->x +=0;
                this->y +=3.08;
}

}
