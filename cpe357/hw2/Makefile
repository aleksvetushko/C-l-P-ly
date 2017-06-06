CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = guess
OBJS = guess.o
all : $(MAIN)

$(MAIN) : $(OBJS) guess.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

guess.o : guess.c guess.h
	$(CC) $(CFLAGS) -c guess.c

clean :
	rm *.o $(MAIN) core
