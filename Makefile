sfml-app: main.o Game.o Tilemap.o Entity.o Character.o Animation.o AnimatedSprite.o
	g++ -o sfml-app main.o Game.o Tilemap.o Entity.o Character.o Animation.o AnimatedSprite.o -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Game.h
	g++ -c -g -std=c++11 -Wall -W -pedantic main.cpp

Game.o: Game.cpp Game.h Tilemap.h Entity.h Character.h
	g++ -c -g -std=c++11 -Wall -W -pedantic Game.cpp

Tilemap.o: Tilemap.cpp Tilemap.h
	g++ -c -g -std=c++11 -Wall -W -pedantic Tilemap.cpp

Entity.o: Entity.cpp Entity.h
	g++ -c -g -std=c++11 -Wall -W -pedantic Entity.cpp

Character.o: Character.cpp Character.h Entity.h
	g++ -c -g -std=c++11 -Wall -W -pedantic Character.cpp

Animation.o: Animation.cpp Animation.hpp
	g++ -c -g -std=c++11 -Wall -W -pedantic Animation.cpp

AnimatedSprite.o: AnimatedSprite.cpp AnimatedSprite.hpp
	g++ -c -g -std=c++11 -Wall -W -pedantic AnimatedSprite.cpp

clean:
	rm -f *.o sfml-app