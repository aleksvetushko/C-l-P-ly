#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

char input[100];

/*this function handles what happens when SIGINT is generated
 * SIGINT is generated when user presses Ctrl-Z*/
void sig_handler(int signo) {
   printf("Usage: Please type \"quit\" to quit\n");
}

int main(int argc, char *argv[]) {

   signal(SIGINT, sig_handler); /*set sig-handler to handle SIGINT*/

   while(gets(input)) {
      if(strcmp(input, "quit") == 0)
         return 0;
   }

   return 0;
}
