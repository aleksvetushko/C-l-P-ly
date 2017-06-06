#include <stdio.h>
#include <stdlib.h>

int main() {
   char * x = malloc(1024*1024*10);
   if(x == NULL) {
      printf("fail");
   }
   return 0;
}
