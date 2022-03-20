all: main_sdl

main_sdl: obj/sdl2/main_sdl.o obj/sdl2/sdlJeu.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o obj/core/Monstre.o
	g++ -g obj/sdl2/main_sdl.o obj/sdl2/sdlJeu.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o obj/core/Monstre.o -lSDL2 -lSDL2_image -o ./bin/main_sdl

obj/sdl2/main_sdl.o: ./src/core/Jeu.h ./src/sdl2/main_sdl.cpp
	g++ -g -Wall -c ./src/sdl2/main_sdl.cpp -o  obj/sdl2/main_sdl.o

obj/sdl2/sdlJeu.o:./src/sdl2/sdlJeu.h ./src/sdl2/sdlJeu.cpp ./src/core/Jeu.h
	g++ -g -Wall -c ./src/sdl2/sdlJeu.cpp -o obj/sdl2/sdlJeu.o

obj/core/Jeu.o: ./src/core/Jeu.h ./src/core/Jeu.cpp ./src/core/Terrain.h ./src/core/Personnage.h ./src/core/Monstre.h
	g++ -g -Wall -c ./src/core/Jeu.cpp -o obj/core/Jeu.o

obj/core/Terrain.o: ./src/core/Terrain.h ./src/core/Terrain.cpp
	g++ -g -Wall -c ./src/core/Terrain.cpp -o obj/core/Terrain.o

obj/core/Monstre.o: ./src/core/Monstre.h ./src/core/Monstre.cpp ./src/core/Terrain.h
	g++ -g -Wall -c ./src/core/Monstre.cpp -o obj/core/Monstre.o

obj/core/Personnage.o: ./src/core/Personnage.h ./src/core/Personnage.cpp ./src/core/Terrain.h
	g++ -g -Wall -c ./src/core/Personnage.cpp -o obj/core/Personnage.o

clean:
	rm ./obj/core/*.o ./obj/sdl2/*.o ./bin/main_sdl
