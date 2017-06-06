CC = gcc
CFLAGS = -Wall -ansi -pedantic
MAIN = a.out
OBJS = part6.c part6_tests.c
all : $(MAIN)

$(MAIN) : $(OBJS) part6.h checkit.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

part6_tests.c : checkit.h part6.h
	$(CC) $(CFLAGS) -c part6_tests.c

part6.c : part6.h
	$(CC) $(CFLAGS) -c part6.c

clean :
	rm *.o $(MAIN) core
