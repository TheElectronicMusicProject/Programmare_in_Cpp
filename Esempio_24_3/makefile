#-------------------------------#
#			Makefile			#
#-------------------------------#
#
#	cmd command is: make -f makefile
#
CC=g++
CFLAGS=-g -Wall -Wextra
SRC=square.cpp square.h integer.h main.cpp

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(SRC) -lm
	
clean:
	rm -f main
