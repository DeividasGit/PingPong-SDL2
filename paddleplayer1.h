#ifndef PADDLEPLAYER1_H
#define PADDLEPLAYER1_H
#include "gameobject.h"
#include "paddle.h"
#include "SDL.h"

class PaddlePlayer1:public Paddle{
public:
    PaddlePlayer1();
    ~PaddlePlayer1();
    PaddlePlayer1(int x, int y);


    void handle_input();

};


#endif // PADDLEPLAYER1_H
