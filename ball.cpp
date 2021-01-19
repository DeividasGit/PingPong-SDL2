#include "ball.h"
#include <cmath>
#include <ctime>
#include <random>
#include <iostream>
#include "SDL.h"

Ball::Ball(){
    this->reset();
}

Ball::~Ball(){
}

void Ball::update(){

    std::cout << x_velocity << "   " << y_velocity << std::endl;
    this->x += x_velocity;
    this->y += y_velocity;

    this->rect.x += this->x;
    this->x = 0;

    this->rect.y += this->y;
    this->y = 0;

}

void Ball::handle_input(){
     const auto state = SDL_GetKeyboardState(NULL);

        SDL_PumpEvents();
		if(state[SDL_SCANCODE_R]){
               this->reset();
		}

}

void Ball::draw(SDL_Renderer* ren){
    SDL_SetRenderDrawColor(ren,255,255,255,255);
    SDL_RenderFillRect(ren,&this->rect);
}
void Ball::collision(int screen_w, int screen_h){
    if(this->rect.y < 0 || this->rect.y + ball_size > screen_h){
        this->y_velocity = -this->y_velocity;
    }

    if(this->rect.x<0){
        this->reset();
    }
    if(this->rect.x + this->rect.w > screen_w){
        this->reset();
    }
}

void Ball::reset(){
    this->rect = {640/2-ball_size/2,480/2-ball_size/2,ball_size,ball_size};

    std::srand(std::time(0));
    this->degree = rand() % 70 + 1;


    this->x_velocity = std::pow(-1,rand())*ball_speed*std::cos(degree*3.14/180.0);
    this->y_velocity = std::pow(-1,rand())*ball_speed*std::sin(degree*3.14/180.0);

}

void Ball::collision(GameObject* obj){

if(obj->getRect().x < this->rect.x+1){
    this->x += obj->getRect().x + obj->getRect().w - this->rect.x;
    this->y += 0;
      this->x_velocity = -this->x_velocity;

    }

else if(obj->getRect().x > this->rect.x+1){
    this->x += -(this->rect.x + this->rect.w - obj->getRect().x);
    this->y += 0;
     this->x_velocity = -this->x_velocity;

}
else if(this->rect.y + this->rect.h >= obj->getRect().y || this->rect.y <= obj->getRect().y + obj->getRect().h){
        //susiduria vertikaliai
        this->y_velocity = -this->y_velocity;
    }

    }



