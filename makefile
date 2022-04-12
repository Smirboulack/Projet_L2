all: main_sdl main_txt

main_sdl: obj/sdl2/main_sdl.o obj/core/Items.o obj/core/Armure.o obj/core/Arme.o obj/core/Piece.o obj/core/Vie.o obj/sdl2/sdlJeu.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o obj/core/Monstre.o
	g++ -ggdb obj/sdl2/main_sdl.o obj/core/Items.o obj/core/Armure.o obj/core/Arme.o obj/core/Piece.o obj/core/Vie.o obj/sdl2/sdlJeu.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o obj/core/Monstre.o -lSDL2 -lSDL2_image -o ./bin/main_sdl

main_txt: obj/txt/main_txt.o obj/core/Items.o obj/core/Armure.o obj/core/Arme.o obj/core/Piece.o obj/core/Vie.o obj/txt/txtJeu.o obj/txt/winTxt.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o obj/core/Monstre.o
	g++ -ggdb obj/txt/main_txt.o obj/core/Armure.o obj/core/Arme.o obj/core/Piece.o obj/core/Vie.o obj/core/Items.o obj/txt/txtJeu.o obj/txt/winTxt.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o obj/core/Monstre.o -o ./bin/main_txt

obj/sdl2/main_sdl.o: ./src/core/Jeu.h ./src/sdl2/main_sdl.cpp
	g++ -ggdb -Wall -c ./src/sdl2/main_sdl.cpp -o  obj/sdl2/main_sdl.o

obj/txt/main_txt.o: ./src/txt/txtJeu.h ./src/txt/winTxt.h ./src/txt/main_txt.cpp
	g++ -ggdb -Wall -c ./src/txt/main_txt.cpp -o  obj/txt/main_txt.o

obj/sdl2/sdlJeu.o:./src/sdl2/sdlJeu.h ./src/sdl2/sdlJeu.cpp ./src/core/Jeu.h
	g++ -ggdb -Wall -c ./src/sdl2/sdlJeu.cpp -o obj/sdl2/sdlJeu.o

obj/txt/txtJeu.o:./src/txt/txtJeu.h ./src/txt/txtJeu.cpp ./src/core/Jeu.h ./src/txt/winTxt.h
	g++ -ggdb -Wall -c ./src/txt/txtJeu.cpp -o obj/txt/txtJeu.o

obj/core/Jeu.o: ./src/core/Jeu.h ./src/core/Jeu.cpp ./src/core/Terrain.h ./src/core/Personnage.h ./src/core/Monstre.h ./src/core/Items.h
	g++ -ggdb -Wall -c ./src/core/Jeu.cpp -o obj/core/Jeu.o

obj/txt/winTxt.o: ./src/txt/winTxt.cpp ./src/txt/winTxt.h
	g++ -ggdb -Wall -c ./src/txt/winTxt.cpp -o obj/txt/winTxt.o

obj/core/Terrain.o: ./src/core/Terrain.h ./src/core/Terrain.cpp ./src/core/Items.h
	g++ -ggdb -Wall -c ./src/core/Terrain.cpp -o obj/core/Terrain.o

obj/core/Monstre.o: ./src/core/Monstre.h ./src/core/Monstre.cpp ./src/core/Terrain.h
	g++ -ggdb -Wall -c ./src/core/Monstre.cpp -o obj/core/Monstre.o

obj/core/Personnage.o: ./src/core/Personnage.h ./src/core/Personnage.cpp ./src/core/Terrain.h
	g++ -ggdb -Wall -c ./src/core/Personnage.cpp -o obj/core/Personnage.o

obj/core/Items.o: ./src/core/Items.h ./src/core/Items.cpp ./src/core/Terrain.h ./src/core/Vie.h ./src/core/Piece.h ./src/core/Arme.h ./src/core/Armure.h
	g++ -ggdb -Wall -c ./src/core/Items.cpp -o obj/core/Items.o

obj/core/Vie.o: ./src/core/Vie.h ./src/core/Vie.cpp
	g++ -ggdb -Wall -c ./src/core/Vie.cpp -o obj/core/Vie.o

obj/core/Piece.o: ./src/core/Piece.h ./src/core/Piece.cpp
	g++ -ggdb -Wall -c ./src/core/Piece.cpp -o obj/core/Piece.o

obj/core/Arme.o: ./src/core/Arme.h ./src/core/Arme.cpp
	g++ -ggdb -Wall -c ./src/core/Arme.cpp -o obj/core/Arme.o

obj/core/Armure.o: ./src/core/Armure.h ./src/core/Armure.cpp
	g++ -ggdb -Wall -c ./src/core/Armure.cpp -o obj/core/Armure.o

clean:
	rm ./obj/core/*.o ./obj/sdl2/*.o ./obj/txt/*.o ./bin/main_sdl ./bin/main_txt
