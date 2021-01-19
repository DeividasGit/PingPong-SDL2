#ifndef GAME_H
#define GAME_H
#include "gameobject.h"
#include "ball.h"
#include "paddle.h"
#include "paddleplayer1.h"
#include "paddleplayer2.h"
#include "SDL.h"
#include <vector>


class Game {


public:
	SDL_Window *win;
	SDL_Renderer *ren;
	static std::vector<GameObject*> obj;

	Game();
	~Game();
	SDL_Renderer* getrenderer(){return this->ren;}


	void init(const char* title, int x, int y, int w, int h);
	void game_loop();
	void draw_board(SDL_Renderer* ren);
	bool check_collision(GameObject* obj1, GameObject* obj2);

private:
    Ball ball;
    PaddlePlayer1 player1;
    PaddlePlayer2 player2;


};


#endif // GAME_H
