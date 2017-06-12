CC = gcc
CFLAGS = -ansi -Wall -pedantic -g
MAIN = httpd
OBJS = httpd.o simple_net.o
all : $(MAIN)

$(MAIN) : $(OBJS) httpd.h simple_net.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

httpd.o : httpd.c httpd.h simple_net.o
	$(CC) $(CFLAGS) -c httpd.c

simple_net.o : simple_net.c simple_net.h
	$(CC) $(CFLAGS) -c simple_net.c

clean :
	rm *.o $(MAIN) core
