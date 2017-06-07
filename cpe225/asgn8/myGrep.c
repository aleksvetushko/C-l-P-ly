#include "myGrep.h"

FILE *file;
char line[100];
char biggestLine[100];
int numLines, wordCount, charCount, searchCount = 0;

struct Node *head;
struct Node *tail;
struct Node *current;

/*stores biggest line and num of chars in that line*/
void biggest(char line[]) {
   if(strlen(line) > charCount) {
      strcpy(biggestLine, line);
      charCount = strlen(biggestLine);
   }
}

/*creates a node in the linked list and returns pointer to that node*/
struct Node * initNode(char line[], int numLines, int wordCount) {
   struct Node * node;
   node = malloc(sizeof(struct Node));
   
   if(line[strlen(line) - 1] == '\n') /*if last char in line is \n get rid of it*/
      line[strlen(line) - 1] = 0;
   strcpy(node->line, line);
   node->lineNum = numLines;
   node->wordNum = wordCount;
   node->next = NULL;
   if(tail->line != NULL)
      tail->next = node;
   tail = node;
   searchCount++;
   return node;
}

/*parses through a line and creates nodes if search word is present*/
void parseLine(char line[], char *search, int lineNum) {
   char delimited[100]; /*holds delimited line*/
   char *token; /*pointer to the first char of the token in delimited*/
   strcpy(delimited, line);
   if ((token = strtok(delimited, " \n")) != NULL) { /*if first word in the line isn't null*/
      if(strcmp(token, search) == 0) { /*if first word matches search word*/
         if(head->line == NULL) {/*create a head if no head*/
            head = initNode(line, lineNum, wordCount);
            head = tail;
         }
         else
            initNode(line, lineNum, wordCount);
      }
      wordCount ++;

      while ((token = strtok(NULL, " \n")) != NULL) { /*while there are more words in the line*/
         if(strcmp(token, search) == 0) { /*if word matches search word*/
            if(head->line == NULL) {/*create a head if no head*/
               head = initNode(line, lineNum, wordCount);
               head = tail;
            }
            else
               initNode(line, lineNum, wordCount);
         }
         wordCount ++;
      }
   }
   wordCount = 0;
   numLines ++;
}

int main(int argc, char *argv[]) { 
   if (argc != 3) {
      printf("myGrep: improper number of arguments\nUsage: ./a.out <filename> <word>\n");
      return 1;
   }
   if( !(file = fopen(argv[1], "r")) ) {
      printf("Unable to open file: %s\n", argv[1]);
      return 1;
   }

   printf("%s %s %s\n", argv[0], argv[1], argv[2]);
   
   while(fgets(line, 100 + 1, file)) { /*loop through lines in file*/
      biggest(line); /*is it the biggest line?*/
      parseLine(line, argv[2], numLines);
   }
   
   printf("longest line: %snum chars: %d\nnum lines: %d\n", biggestLine, charCount, numLines);

   printf("total occurrences of word: %d\n", searchCount);

   current = head;
   while(current != NULL) {
      head = current;/*head used as reference to free the node after*/
      printf("line %d; word %d; %s\n", current->lineNum, current->wordNum, current->line);
      current = current->next;
      free(head);
   }

   fclose(file);

   return 0;
}
