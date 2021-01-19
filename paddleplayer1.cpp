#include "SDL.h"
#include <iostream>
#include "paddleplayer1.h"
#include "gameobject.h"


PaddlePlayer1::PaddlePlayer1(){
}

PaddlePlayer1::~PaddlePlayer1(){
}

PaddlePlayer1::PaddlePlayer1(int x, int y):Paddle(x,y){
    this->rect.x = x;
    this->rect.y = y;
    this->rect.h = 80;
    this->rect.w = 10;
}

void PaddlePlayer1::handle_input(){
       const auto state = SDL_GetKeyboardState(NULL);

        SDL_PumpEvents();
		if(state[SDL_SCANCODE_W]){
                this->x +=0;
                this->y -=3.08;
		}
		if(state[SDL_SCANCODE_S]){
                this->x +=0;
                this->y +=3.08;
}

}
