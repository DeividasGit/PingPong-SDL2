#ifndef PADDLEPLAYER2_H
#define PADDLEPLAYER2_H
#include "gameobject.h"
#include "paddle.h"
#include "SDL.h"

class PaddlePlayer2:public Paddle{
public:
    PaddlePlayer2();
    ~PaddlePlayer2();
    PaddlePlayer2(int x, int y);


    void handle_input();

};


#endif // PADDLEPLAYER1_H

