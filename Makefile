CC := g++
SRC := ./src/
BUILD := ./build/
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: prog

run:
	./prog

prog: $(BUILD)main.o 
	$(CC) $(CFLAGS) -o prog $(BUILD)main.o 

$(BUILD)main.o: $(SRC)main.cpp
	$(CC) $(CFLAGS) -o $(BUILD)main.o -c $(SRC)main.cpp