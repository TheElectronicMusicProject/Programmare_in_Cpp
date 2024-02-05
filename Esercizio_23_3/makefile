#-------------------------------#
#			Makefile			#
#-------------------------------#
#
#	cmd command is: make -f makefile
#
CC=g++
CFLAGS=-g -Wall -Wextra
SRC=lookup.cpp main.cpp
OBJ=lookup.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: lookup.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

lookup.o: lookup.h lookup.cpp
	$(CC) $(CFLAGS) -c lookup.cpp
	
clean:
	rm -f main io.o lookup.o
