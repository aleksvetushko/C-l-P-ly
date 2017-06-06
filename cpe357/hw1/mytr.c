/*Aleks Vetushko
HW 1*/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
   int array[256];
   int i;
   int k;
   int j;
   char set1[100];
   char set2[100];
   char tempset1[100];
   char tempset2[100];
   char c;
   int inputchar;
   int outputchar;

   while(argc == 3) {
      if(strcmp(argv[2], "") == 0) {
         fprintf(stderr, "tr: when not truncating set1, string2 must be non-empty\n");
         return 1;
      }

      /*initialize array 0-255*/
      for(i = 0; i < 256; i++) {
         array[i] = i;
      }

      j = 0;
      for(k = 0; k < strlen(argv[1]); k++) {
         if(argv[1][k] == (char) 92 ) {
            if(argv[1][k+1] == 'n') {
               tempset1[j] = 10 + 0;
               j++;
            }
            if(argv[1][k+1] == 't') {
               tempset1[j] = 9 + 0;
               j++;
            }
            if(argv[1][k+1] == (char) 92) {
               tempset1[j] = 92 + 0;
               j++;
            }
            else {
               tempset1[j] = argv[1][k+1];
               j++;
            }
            k++;
         }
         else {
            tempset1[j] = argv[1][k];
            j++;
         }
      }

      j = 0;
      for(k = 0; k < strlen(argv[2]); k++) {
         if(argv[2][k] == (char) 92 ) {
            if(argv[2][k+1] == 'n') {
               tempset2[j] = 10 + 0;
               j++;
            }
            if(argv[2][k+1] == 't') {
               tempset2[j] = 9 + 0;
               j++;
            }
            if(argv[2][k+1] == (char) 92) {
               tempset2[j] = 92 + 0;
               j++;
            }
            else {
               tempset2[j] = argv[2][k+1];
               j++;
            }
            k++;
         }
         else {
            tempset2[j] = argv[2][k];
            j++;
         }
      }

      /*if -d*/
      if(tempset1[0] == '-' && tempset1[1] == 'd') {
         for(k = 0; k < strlen(tempset2); k++) {
            set1[k] = tempset2[k];
         }

         for(k = 0; k < strlen(set1); k++) {
            array[(int)set1[k]] = 0;
         }

         while((c = getchar()) != EOF) {
            inputchar = (int)c;
            outputchar = array[inputchar];
            if(outputchar != 0) {
               putchar(outputchar + 0);
            }
         }
         return 0;
      }

      /*if set1 > set2*/
      if(strlen(tempset1) > strlen(tempset2)) {
         for(k = 0; k < strlen(tempset1); k++) {
            set1[k] = tempset1[k];
         }
         for(k = 0; k < strlen(tempset2); k++) {
            set2[k] = tempset2[k];
         }
         for(k = strlen(tempset2); k < strlen(tempset1); k++) {
            set2[k] = set2[strlen(tempset2) - 1];
         }
      }

      /*if set1 <= set2*/
      if(strlen(tempset1) <= strlen(tempset2)) {
         for(k = 0; k < strlen(tempset1); k++) {
            set1[k] = tempset1[k];
            set2[k] = tempset2[k];
         }
      }

      for(k = 0; k < strlen(set1); k++) {
         array[(int)set1[k]] = (int)set2[k];
      }

      while((c = getchar()) != EOF) {
         inputchar = (int)c;
         outputchar = array[inputchar];
         putchar(outputchar);
      }
      return 0;
   }

   if(argc == 1) {
      fprintf(stderr, "tr: missing operand\nTry 'tr --help' for more information.\n");
      return 1;
   }

   if(argc == 2) {
      if(argv[1][0] == '-') {
         if(argv[1][1] == '\0') {
            fprintf(stderr, "tr: missing operand after ‘-’\nTwo strings must be given when translating.\nTry 'tr --help' for more information.\n");
            return 1;
         }
         if(argv[1][1] == 'd') {
            fprintf(stderr, "tr: missing operand\nTry 'tr --help' for more information.\n");
            return 1;
         }
         else {
            fprintf(stderr, "tr: invalid option -- '%c'\nTry 'tr --help' for more information.\n", argv[1][1]);
            return 1;
         }
      }
      /*if second arg doesn't begin with -*/
      else {
         fprintf(stderr, "tr: missing operand after ‘%s’\nTwo strings must be given when translating.\nTry 'tr --help' for more information.\n", argv[1]);
         return 1;
      }
   }

   if(argc > 3) {
      fprintf(stderr, "tr: extra operand ‘%s’\nTry 'tr --help' for more information.\n", argv[3]);
      return 1;
   }
   return 1;
}
