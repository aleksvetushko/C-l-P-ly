#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

char input[100];
int time;

/*this function handles what happens when SIGINT is generated
 * SIGINT is generated when user presses Ctrl-Z*/
void sig_handler(int signo) {
   exit(getpid());
}

void timer() {
   struct sigaction sa;
   struct itimerval mytimer;

   memset (&sa, 0, sizeof (sa));
   sa.sa_handler = &sig_handler;
   sigaction (SIGALRM, &sa, NULL);

   mytimer.it_value.tv_sec = time;
   mytimer.it_value.tv_usec = 0; /*timer expires after x seconds*/
   mytimer.it_interval.tv_sec = 0;
   mytimer.it_interval.tv_usec = 0; /*does not repeat*/
   
   /*set the timer*/
   setitimer (ITIMER_REAL, &mytimer, NULL);
}

int main(int argc, char *argv[]) {
   pid_t pid;
   int status, x;

   time = atoi(argv[1]);
   pid = fork();
   
   if(pid == 0) {
      timer(); /*set timer*/
      execv(argv[2], argv + 2);
   }
   else {
      x = waitpid(-1, &status, WIFSIGNALED);
      if(x > 0)
         return 0;
      else
         return x;
   }

   return 0;
}
