#-------------------------------#
#			Makefile			#
#-------------------------------#
#
#	cmd command is: make -f makefile
#
CC=g++
CFLAGS=-g -Wall -Wextra
SRC=search_open.cpp main.cpp
OBJ=search_open.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: search_open.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

search_open.o: search_open.h search_open.cpp
	$(CC) $(CFLAGS) -c search_open.cpp
	
clean:
	rm -f main io.o search_open.o
