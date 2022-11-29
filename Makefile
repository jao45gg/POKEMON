CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -std=c++11 -I include/

all: main

Cartas:
	@mkdir build/Cartas/
	$(CC) $(CFLAGS) -c src/Cartas.cpp -o build/Cartas/Cartas.o

Baralho:
	@mkdir build/Baralho/
	$(CC) $(CFLAGS) -c src/Baralho.cpp -o build/Baralho/Baralho.o

Usuario:
	@mkdir build/Usuario/
	$(CC) $(CFLAGS) -c src/Usuario.cpp -o build/Usuario/Usuario.o

Partida:
	@mkdir build/Partida/
	$(CC) $(CFLAGS) -c src/Partida.cpp -o build/Partida/Partida.o

main: Cartas Baralho Usuario Partida

	$(CC) $(CFLAGS) build/Cartas/Cartas.o build/Baralho/Baralho.o build/Usuario/Usuario.o build/Partida/Partida.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
