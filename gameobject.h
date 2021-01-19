#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL.h"

class GameObject{
public:
    GameObject();
    ~GameObject();

    virtual void update();
    virtual void handle_input();
    virtual void draw(SDL_Renderer* ren);
    virtual void collision(int screen_w, int screen_h);
    virtual void collision(GameObject* obj);
    SDL_Rect getRect(){return this->rect;};
protected:
    double x, y, x_velocity, y_velocity;
    SDL_Rect rect;

};



#endif //GAMEOBJECT_H
