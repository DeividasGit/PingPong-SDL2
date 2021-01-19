#include "game.h"
#include "SDL.h"

#include <iostream>

std::vector<GameObject*> Game::obj;

Game::Game(){}

Game::~Game(){
    SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void Game::init(const char* title, int x, int y, int w, int h){

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return ;
	}


	 win = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return ;
	}


	 ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return ;
	}

	this->obj.push_back(new Ball());
	this->obj.push_back(new PaddlePlayer1(640*0.05,(480-80)/2));
	this->obj.push_back(new PaddlePlayer2(640*(1-0.05)-10,(480-80)/2));
    this->game_loop();

}

void Game::draw_board(SDL_Renderer* ren){
    SDL_SetRenderDrawColor(this->ren,0,0,0,255);
    SDL_RenderClear(this->ren);


    SDL_SetRenderDrawColor(this->ren,255,255,255,255);
    SDL_RenderDrawLine(this->ren,640/2,0,640/2,480);

}

bool Game::check_collision(GameObject* obj1, GameObject* obj2){
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    bool isCollidingYAxis = false;
    bool isCollidingXAxis = false;

    leftA = obj1->getRect().x;
    rightA = obj1->getRect().x + obj1->getRect().w;
    topA = obj1->getRect().y;
    bottomA = obj1->getRect().y + obj1->getRect().h;

    leftB = obj2->getRect().x;
    rightB = obj2->getRect().x + obj2->getRect().w;
    topB = obj2->getRect().y;
    bottomB = obj2->getRect().y + obj2->getRect().h;

    if(rightA <= leftB || leftA >= rightB){
        if(isCollidingYAxis){
            isCollidingYAxis = false;
            return false;
        } else {
            isCollidingXAxis = true;
            return false;
        }
    }

    if(bottomA <= topB || topA >= bottomB){
        if(isCollidingXAxis){
            isCollidingXAxis = false;
            return false;
        } else {
            isCollidingYAxis = true;
            return false;
        }
    }
    return true;
}



void Game::game_loop(){

    for (int i = 0; ; ++i) {
    this->draw_board(this->ren);

    for(int i=0; i<this->obj.size();i++){
        obj[i]->handle_input();
    }
     for(int i=0; i<this->obj.size();i++){
        //collision with screen
        obj[i]->collision(640,480);
    }
    for(int i=0; i<this->obj.size();i++){
        obj[i]->update();
    }
    for(int i=0; i<this->obj.size();i++){
        obj[i]->draw(this->ren);
    }
    //Collision check
    if(this->check_collision(obj[0],obj[1])){
        obj[0]->collision(obj[1]);
        //obj[1]->collision(obj[0]);
    }
    if(this->check_collision(obj[1],obj[2])){
        obj[1]->collision(obj[2]);
        //obj[2]->collision(obj[1]);
    }
    if(this->check_collision(obj[0],obj[2])){
        obj[0]->collision(obj[2]);
        //obj[2]->collision(obj[0]);
    }

    SDL_RenderPresent(this->ren);

    SDL_Delay(1000 / 60);
    }
}
