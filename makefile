CC = g++
CFLAGS = -c -Wall -Werror
SOURCES = src/*.cpp
OBJECTS = $(SOURCES:.cpp = .0)
EXECUTABLE = TODO-List




all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) -g -Wall -Werror $(OBJECTS) -o $@  -lsfml-graphics -lsfml-window -lsfml-system

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

run:
	./TODO-List