#ifndef PADDLE_H
#define PADDLE_H
#include "gameobject.h"
#include "SDL.h"

class Paddle:public GameObject{
public:
    Paddle();
    ~Paddle();
    Paddle(int x, int y);
    void update() override;
    void draw(SDL_Renderer* ren) override;
    void collision(GameObject* obj) override;
    void collision(int screen_w, int screen_h) override;

};

#endif // PADDLE_H
