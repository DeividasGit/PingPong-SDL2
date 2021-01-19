#include "SDL.h"
#include <iostream>
#include "paddle.h"

Paddle::Paddle(){
}

Paddle::~Paddle(){
}

Paddle::Paddle(int x, int y){
    this->rect.x = x;
    this->rect.y = y;
    this->x = 0;
    this->y = 0;
}

void Paddle::draw(SDL_Renderer* ren){
    SDL_SetRenderDrawColor(ren,255,255,255,255);
    SDL_RenderFillRect(ren,&this->rect);
}

void Paddle::update(){


    this->rect.x += this->x;
    this->x = 0;

    this->rect.y += this->y;
    this->y = 0;

}



void Paddle::collision(int screen_w, int screen_h){
    if((this->rect.y + this->y - 3.08)<0){
                    this->rect.y = 0;
                    this->y = 0;
    }
            else if((this->rect.y + this->y - 3.08)>screen_h - 80){
                this->rect.y = screen_h - 80;
                this->y = 0;
    }

    if((this->rect.y + this->y + 3.08)<0){
                    this->rect.y = 0;
                    this->y = 0;
    }
            else if((this->rect.y + this->y + 3.08)>screen_h - 80){
                this->rect.y = screen_h - 80;
                this->y = 0;
    }
}

void Paddle::collision(GameObject* obj){
}
