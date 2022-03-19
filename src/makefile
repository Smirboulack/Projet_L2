all: Ultimate_LIFKAS

Ultimate_LIFKAS: obj/core/main_Ultimate_LIFKAS.o ./src/core/main_Ultimate_LIFKAS.cpp
	g++ -g obj/core/main_Ultimate_LIFKAS.o -o ./bin/Ultimate_LIFKAS

obj/core/main_Ultimate_LIFKAS.o: /src/core/Jeu.h ./src/core/main_Ultimate_LIFKAS.cpp
	g++ -g -Wall -c ./src/core/main_Ultimate_LIFKAS.cpp -o  obj/core/main_Ultimate_LIFKAS.o
 
obj/core/Jeu.o: ./src/core/Jeu.h ./src/core/Jeu.cpp ./src/core/Terrain.h ./src/core/Personnage.h ./src/core/Monstre.h ./src/core/Menu.h
	g++ -g -Wall -c ./src/core/Jeu.cpp -o obj/core/Jeu.o

obj/core/Menu.o: ./src/core/Menu.h ./src/core/Menu.cpp
	g++ -g -Wall -c ./src/core/Menu.cpp -o obj/core/Menu.o

obj/core/Terrain.o: ./src/core/Terrain.h ./src/core/Terrain.cpp
	g++ -g -Wall -c ./src/core/Terrain.h -o obj/core/Terrain.o

obj/core/Monstre.o: ./src/core/Monstre.h ./src/core/Monstre.cpp ./src/core/Personnage.h ./src/core/Terrain.h
	g++ -g -Wall -c ./src/core/Monstre.cpp -o obj/core/Monstre.o

obj/core/Personnage.o: ./src/core/Personnage.h ./src/core/Personnage.cpp ./src/core/Terrain.h
	g++ -g -Wall -c ./src/core/Personnage.cpp -o obj/core/Personnage.o

clean:
	rm ./obj/core/* ./bin/Ultimate_LIFKAS
