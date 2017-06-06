CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = smake
OBJS = smake.o
all : $(MAIN)

$(MAIN) : $(OBJS) smake.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

smake.o : smake.c smake.h
	$(CC) $(CFLAGS) -c smake.c

clean :
	rm *.o $(MAIN) core
