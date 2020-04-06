TODO-List: main.o menu.o
		g++ -g -Wall main.o -o menu.h menu.o -o TODO-List -lsfml-graphics -lsfml-window -lsfml-system 

main.o: main.cpp 
		g++ -c main.cpp menu.h

menu.o: menu.cpp
		g++ -c menu.cpp 

run:
		./TODO-List