CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = httpd
OBJS = httpd.o simple_net.o
all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

httpd.o : httpd.c simple_net.h httpd.h httpd.c httpd_funcs.c httpd_funcs.h
	$(CC) $(CFLAGS) -c httpd.c

httpd_funcs.o : httpd_funcs.c httpd_funcs.h simple_net.h simple_net.c
	$(CC) $(CFLAGS) -c httpd_funcs.c

simple_net.o : simple_net.c simple_net.h
	$(CC) $(CFLAGS) -c simple_net.c
