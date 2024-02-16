#-------------------------------#
#			Makefile			#
#-------------------------------#
#
#	cmd command is: make -f makefile
#
CC=g++
CCFLAGS=-g -Wall
OBJS= stat.o ch_type.o token.o

all: stat.out stat 

stat.out: stat
	stat ./calc3/calc3.cpp >stat.out

stat: $(OBJS)
	$(CC) $(CCFLAGS) -o stat $(OBJS)

stat.o: stat.cpp token.h
	$(CC) $(CCFLAGS) -c stat.cpp

ch_type.o: ch_type.cpp ch_type.h
	$(CC) $(CCFLAGS) -c ch_type.cpp

token.o: token.cpp token.h ch_type.h
	$(CC) $(CCFLAGS) -c token.cpp

clean:
	rm -f stat stat.o ch_type.o token.o