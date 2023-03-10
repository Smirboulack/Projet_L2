all: main_sdl main_txt mainmenu_sdl

main_sdl: obj/sdl2/main_sdl.o obj/sdl2/Image.o obj/core/Camera.o obj/core/Menu.o obj/sdl2/sdlJeu.o obj/txt/winTxt.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o
	g++ -ggdb -Wall obj/sdl2/main_sdl.o obj/sdl2/Image.o obj/core/Camera.o obj/core/Menu.o obj/sdl2/sdlJeu.o obj/txt/winTxt.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o -lSDL2 -lSDL2_image -lSDL2_mixer -o ./bin/main_sdl

main_txt: obj/txt/main_txt.o obj/core/Menu.o obj/txt/txtJeu.o obj/txt/winTxt.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o 
	g++ -ggdb -Wall obj/txt/main_txt.o obj/core/Menu.o obj/txt/txtJeu.o obj/txt/winTxt.o obj/core/Jeu.o obj/core/Terrain.o obj/core/Personnage.o -o ./bin/main_txt

mainmenu_sdl: obj/sdl2/mainmenu_sdl.o obj/sdl2/Image.o
	g++ -ggdb -Wall obj/sdl2/mainmenu_sdl.o obj/sdl2/Image.o -lSDL2 -lSDL2_image -o ./bin/mainmenu_sdl

obj/sdl2/main_sdl.o:./src/sdl2/main_sdl.cpp
	g++ -ggdb -Wall -c ./src/sdl2/main_sdl.cpp -o  obj/sdl2/main_sdl.o

obj/txt/main_txt.o: ./src/txt/main_txt.cpp
	g++ -ggdb -Wall -c ./src/txt/main_txt.cpp -o  obj/txt/main_txt.o

obj/sdl2/mainmenu_sdl.o: ./src/sdl2/mainmenu_sdl.cpp ./src/sdl2/Image.h
	g++ -ggdb -Wall -c ./src/sdl2/mainmenu_sdl.cpp -o  obj/sdl2/mainmenu_sdl.o

obj/sdl2/sdlJeu.o:./src/sdl2/sdlJeu.h ./src/sdl2/sdlJeu.cpp
	g++ -ggdb -Wall -c ./src/sdl2/sdlJeu.cpp -o obj/sdl2/sdlJeu.o

obj/sdl2/Image.o:./src/sdl2/Image.cpp ./src/sdl2/Image.h
	g++ -ggdb -Wall -c ./src/sdl2/Image.cpp -o obj/sdl2/Image.o

obj/core/Camera.o:./src/core/Camera.cpp ./src/core/Camera.h
	g++ -ggdb -Wall -c ./src/core/Camera.cpp -o obj/core/Camera.o

obj/txt/txtJeu.o:./src/txt/txtJeu.h ./src/txt/txtJeu.cpp
	g++ -ggdb -Wall -c ./src/txt/txtJeu.cpp -o obj/txt/txtJeu.o

obj/core/Jeu.o: ./src/core/Jeu.h ./src/core/Jeu.cpp
	g++ -ggdb -Wall -c ./src/core/Jeu.cpp -o obj/core/Jeu.o

obj/txt/winTxt.o: ./src/txt/winTxt.cpp ./src/txt/winTxt.h
	g++ -ggdb -Wall -c ./src/txt/winTxt.cpp -o obj/txt/winTxt.o

obj/core/Menu.o: ./src/core/Menu.h ./src/core/Menu.cpp
	g++ -ggdb -Wall -c ./src/core/Menu.cpp -o obj/core/Menu.o

obj/core/Terrain.o: ./src/core/Terrain.h ./src/core/Terrain.cpp
	g++ -ggdb -Wall -c ./src/core/Terrain.cpp -o obj/core/Terrain.o

obj/core/Boss.o: ./src/core/Boss.h ./src/core/Boss.cpp
	g++ -ggdb -Wall -c ./src/core/Boss.cpp -o obj/core/Boss.o

obj/core/Personnage.o: ./src/core/Personnage.h ./src/core/Personnage.cpp 
	g++ -ggdb -Wall -c ./src/core/Personnage.cpp -o obj/core/Personnage.o

clean:
	rm ./obj/core/*.o ./obj/sdl2/*.o ./obj/txt/*.o ./bin/main_sdl ./bin/mainmenu_sdl ./bin/main_txt
