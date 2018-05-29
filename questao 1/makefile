#Makefile for "jogoDoDado" C++ application (Cont.)
#Created by Claudio da Cruz Silva Junior 03/04/2018 main.o :
PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I./include
LDFLAGS = -L./lib 
BUILD = ./build/
BIN = ./bin/
OBJS = ./build/main.o ./build/palindromo.o ./build/pilha.o 
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN)$(PROG) $(OBJS)
./build/main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp -o $(BUILD)main.o
./build/palindromo.o:./include/palindromo.h
	$(CC) $(CPPFLAGS) -c src/palindromo.cpp -o $(BUILD)palindromo.o
./build/pilha.o:./include/pilha.h
	$(CC) $(CPPFLAGS) -c src/pilha.cpp -o $(BUILD)pilha.o
clean:
	rm -f core $(BIN)$(PROG) $(OBJS) 