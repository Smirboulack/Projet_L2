all: Ultimate_LIFKAS

Ultimate_LIFKAS: obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o
	g++ -g obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o -o ./bin/Ultimate_LIFKAS

obj/core/Jeu.o: ./src/core/Terrain.h ./src/Personnage.cpp
	g++ -g -Wall -c ./src/core/Jeu.cpp -o obj/core/Jeu.o

obj/core/Terrain.o: ./src/core/Terrain.h ./src/core/Terrain.cpp
	g++ -g -Wall -c ./src/core/Terrain.h -o obj/Terrain.o

obj/core/Personnage.o: ./src/core/Personnage.h ./src/core/Personnage.cpp 
	g++ -g -Wall -c ./src/core/Pixel.cpp -o obj/core/personnage.o

clean:
	rm ./obj/core/* ./bin/Ultimate_LIFKAS


