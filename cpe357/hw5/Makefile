CC = gcc
CFLAGS = -std=c99 -D_POSIX_C_SOURCE -Wall -pedantic -g
MAIN = mytimer
OBJS = mytimer.o
all : $(MAIN)

$(MAIN) : $(OBJS) mytimer.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

guess.o : mytimer.c mytimer.h
	$(CC) $(CFLAGS) -c mytimer.c

clean :
	rm *.o $(MAIN) core
