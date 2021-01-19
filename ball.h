#ifndef BALL_H
#define BALL_H
#include "gameobject.h"
#include "SDL.h"

class Ball:public GameObject{
public:
    Ball();
    ~Ball();

    void update() override;
    void handle_input() override;
    void draw(SDL_Renderer* ren) override;
    void collision(int screen_w, int screen_h) override;
    void collision(GameObject* obj) override;
    void reset();


    int degree;
    int ball_size = 20;
    double ball_speed = 3.05;
};


#endif // BALL_H
