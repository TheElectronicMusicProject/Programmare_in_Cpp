#-------------------------------#
#			Makefile			#
#-------------------------------#
#
#	cmd command is: make -f makefile
#
CC=g++
CFLAGS=-g -Wall -Wextra
SRC=file_style.cpp main.cpp
OBJ=file_style.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: file_style.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

file_style.o: file_style.h file_style.cpp
	$(CC) $(CFLAGS) -c file_style.cpp
	
clean:
	rm -f main io.o file_style.o
