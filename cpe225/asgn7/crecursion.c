#include <stdio.h>

void countBackwardFrom(int x) {
   if(x ==  1)
      printf("%d", x);
   else if(x > 1) {
      printf("%d, ", x);
      countBackwardFrom(x-1);
   }
}

void countForwardTo(int x) {
   if(x == 1)
      printf("%d", x);
   else if(x > 1) {
      countForwardTo(x-1);
      printf(", %d", x);
   }
}

int main() {
   int input;
   printf("Please enter an integer: ");
   scanf("%d", &input);
   countBackwardFrom(input);
   printf("\n");
   countForwardTo(input);
   printf("\n");
   return 0;
}
