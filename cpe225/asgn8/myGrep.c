#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
   FILE *file;
   char line[100];
   char biggestLine[100];
   int numLines = 0;
   int charCount = 0;

   struct Node {
      
   }
   
   if (argc != 3) {
      printf("myGrep: improper number of arguments\nUsage: a.out <filename> <word>\n");
      return 1;
   }
   printf("%s %s %s\n", argv[0], argv[1], argv[2]);
   
   if( !(file = fopen(argv[1], "r")) ) {
      printf("Unable to open file: %s\n", argv[1]);
      return 1;
   }

   while(fgets(line, 100, file)) {
      numLines ++;
      if(strlen(line) > charCount) {
         strcpy(biggestLine, line);
         charCount = strlen(biggestLine) - 1;
      }
   }
   
   printf("longest line: %snum chars: %d\nnum lines: %d\n", biggestLine, charCount, numLines);

   fclose(file);

   return 0;
}
