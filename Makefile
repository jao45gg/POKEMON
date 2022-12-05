CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.exe
CFLAGS := -g -Wall -std=c++11 -I include/
TESTTARGET := tests/Testes.exe

all: main

Cartas:
	
	$(CC) $(CFLAGS) -c src/Cartas.cpp -o build/Cartas/Cartas.o

Baralho:
	
	$(CC) $(CFLAGS) -c src/Baralho.cpp -o build/Baralho/Baralho.o

Usuario:
	
	$(CC) $(CFLAGS) -c src/Usuario.cpp -o build/Usuario/Usuario.o

Partida:
	
	$(CC) $(CFLAGS) -c src/Partida.cpp -o build/Partida/Partida.o

main: Cartas Baralho Usuario Partida

	$(CC) $(CFLAGS) build/Cartas/Cartas.o build/Baralho/Baralho.o build/Usuario/Usuario.o build/Partida/Partida.o src/main.cpp -o $(TARGET)
	$(CC) $(CFLAGS) build/Cartas/Cartas.o build/Baralho/Baralho.o build/Usuario/Usuario.o build/Partida/Partida.o tests/Testes.cpp -o $(TESTTARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
