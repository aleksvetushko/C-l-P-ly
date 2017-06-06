#include <stdio.h>
#include "stack.h"

int stack[10];
int top = -1;

/*push item onto stack*/
int push(int value) {
   if(top < 9) {
      top++;
      stack[top] = value;
      return 0;
   }
   return 1;
}

/*pop item off stack*/
int pop(int *value) {
   if(top != -1) {
      *value = stack[top];
      top--;
      return 0;
   }
   return 1;
}

void printStack(int format) {
   int i;
   if(format == 0) {
      for(i = 0; i <= top; i++) {
         printf("%d ", stack[i]);
      }
   }
   if(format == 1) {
      for(i = 0; i <= top; i++) {
         printf("%x ", stack[i]);
      }
   }
   if(format == 2) {
      for(i = 0; i <= top; i ++) {
         printf("%c ", stack[i]);
      }
   }
   printf("\n");
}
