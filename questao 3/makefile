#Makefile for "jogoDoDado" C++ application (Cont.)
#Created by Claudio da Cruz Silva Junior 03/04/2018 main.o :
PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I./include
LDFLAGS = -L./lib 
BUILD = ./build/
BIN = ./bin/
OBJS = ./build/main.o  
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN)$(PROG) $(OBJS)
./build/main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp -o $(BUILD)main.o
clean:
	rm -f core $(BIN)$(PROG) $(OBJS) 