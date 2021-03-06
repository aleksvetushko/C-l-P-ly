#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <termios.h>
#include <math.h>

#define TICKS_PER_SECOND 20
#define TRUE 1
#define FALSE 0

int handleKeyboard();
int listen();

void timer();
void timer_handler(int signum);
void setTerminal (struct termios *old_tio);
void restoreTerminal (struct termios *tio);

void invalidInput(int argc, char *argv[]);
