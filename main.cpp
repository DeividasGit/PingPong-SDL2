#include "game.h"
#include "SDL.h"
#include <iostream>


int main(int argc, char** argv) {

    ///Paleidziamas zaidimas:
	Game().init("2D Ping Pong",100, 100, 640, 480);

	return 0;
}
