#-------------------------------#
#			Makefile			#
#-------------------------------#
#
#	cmd command is: make -f makefile
#
CC=g++
CFLAGS=-g -Wall -Wextra
SRC=ia.cpp main.cpp
OBJ=ia.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: ia.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

ia.o: ia.h ia.cpp
	$(CC) $(CFLAGS) -c ia.cpp
	
clean:
	rm -f main io.o hist.o
