TODO-List: main.o menu.o createTask.o
		g++ -g -Wall -Werror main.o -o src/menu.h menu.o -o src/createTask.h createTask.o -o TODO-List -lsfml-graphics -lsfml-window -lsfml-system 

main.o: src/main.cpp 
		g++ -c src/main.cpp src/menu.h

menu.o: src/menu.cpp src/createTask.h
		g++ -c src/menu.cpp src/createTask.h


createTask.o: src/createTask.cpp
		g++ -c src/createTask.cpp src/createTask.h

run:
		./TODO-List