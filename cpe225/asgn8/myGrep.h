#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
   char line[100];
   int lineNum, wordNum;
   struct Node *next;
};

void biggest(char line[]);
struct Node * initNode(char line[], int numLines, int wordCount);
void parseLine(char line[], char *search, int numLines);

