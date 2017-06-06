#include <stdio.h>
#include "stack.h"

char option;
int  mode = 0;
int number;

int main() {
   printf("Welcome to the stack program. \n");
   
   while(1) {
      printf("\nEnter option: ");
      scanf("%c", &option);
      while(option == '\n')
         scanf("%c", &option);
      
      if(option == 'u') {
         printf("What number? ");
         scanf("%d", &number);
         if(push(number) == 1)
            printf("Overflow!!! \n");
      }

      if(option == 'o') {
         if(pop(&number) == 0)
            printf("Popped %d\n", number);
         else
            printf("Underflow!!! \n");
      }

      if(option == 'h')
         mode = 1; /*hex*/
      if(option == 'c')
         mode = 2; /*char*/
      if(option == 'd')
         mode = 0; /*decimal*/

      if(option == 'x') {
         printf("Goodbye!\n");
         return 0;
      }
      
      while ((getchar()) != '\n');
      
      if(option == 'u' || option == 'o' || option == 'h' || option == 'c' || option == 'd') {
         printf("Stack: ");
         printStack(mode);
      }
      else
         printf("\n");
   }

   return 1;
}
