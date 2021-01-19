#include "gameobject.h"
#include "SDL.h"
#include <iostream>

GameObject::GameObject(){
}

GameObject::~GameObject(){
}

void GameObject::update(){
}

void GameObject::handle_input(){
}

void GameObject::draw(SDL_Renderer* ren){
}

void GameObject::collision(int screen_w, int screen_h){
}

void GameObject::collision(GameObject* obj){
}
