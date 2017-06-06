CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = sfind
OBJS = sfind.o
all : $(MAIN)

$(MAIN) : $(OBJS) sfind.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

guess.o : sfind.c sfind.h
	$(CC) $(CFLAGS) -c sfind.c

clean :
	rm *.o $(MAIN) core
