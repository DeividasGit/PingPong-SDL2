CXXFLAGS = -Isdl2/32bit/include/SDL2 -std=c++0x
LXXFLAGS = -Lsdl2/32bit/lib -lmingw32 -lSDL2main -lSDL2

main: main.o paddle.o gameobject.o game.o ball.o paddleplayer1.o paddleplayer2.o
	g++ main.o paddle.o gameobject.o game.o ball.o paddleplayer1.o paddleplayer2.o -o main $(LXXFLAGS)
	
main.o: main.cpp
	g++ main.cpp -c $(CXXFLAGS)
	
paddle.o: paddle.cpp paddle.h
	g++ paddle.cpp -c $(CXXFLAGS)

gameobject.o: gameobject.cpp gameobject.h
	g++ gameobject.cpp -c $(CXXFLAGS)

game.o: game.cpp game.h
	g++ game.cpp -c $(CXXFLAGS)

ball.o: ball.cpp ball.h
	g++ ball.cpp -c $(CXXFLAGS)

paddleplayer1.o: paddleplayer1.cpp paddleplayer1.h
	g++ paddleplayer1.cpp -c $(CXXFLAGS)

paddleplayer2.o: paddleplayer2.cpp paddleplayer2.h
	g++ paddleplayer2.cpp -c $(CXXFLAGS)