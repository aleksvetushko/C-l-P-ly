#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "guess.h"

FILE * db;
char ** tree;
int c; /*size of tree including zero spot*/

void freeTree(void) {
   int i = 0;
   for(i = 0; i < c; i++) {
      free(*(tree+i));
   }
   free(tree);
}

/* reads a line from user input and returns it, with a (-,-x) or (a,bx) at the start 
 * This denotes line number of child nodes or - if no children [answer]
 * if the line is \n then loops until user enters valid line */
char * readInput(int yes, int no) {
   char ch;
   int i = 0;
   char *string = calloc(10, sizeof(char));
   
   /*while getchar is enter keep prompting for a char*/
   while((ch = fgetc(stdin)) == '\n') {
      if(yes == -1) /*if input is an answer*/
         printf("An empty response is not acceptable.  Please answer again.\nWhat is it (with article)? ");
      else /*input is question*/
         printf ("An empty response is not acceptable.  Please answer again.\n? ");
   }

   /*start string with children */
   sprintf(string, "%d,%dx", yes, no);
   i += strlen(string);

   /*we append this char bc we already got one of the chars from the users^*/
   string[i] = ch;
   i++;

   /*keep getting chars until it's EOF or enter*/
   while((ch = fgetc(stdin)) != EOF && ch != '\n') {
      string[i] = ch;
      i++;
      if((i+1) % 10 == 0) {
         string = realloc( string, 1 + i*sizeof(char) + 10*sizeof(char) );
         memset(string + i, 0, 10*sizeof(char));
      }
   }
   return string;
}

/* reads line from file and returns it
 * if line is \n then returns NULL */
char * readlineToPopulateTree(FILE * file) {
   char ch;
   int i = 0;
   char *string = calloc(10, sizeof(char));

   while((ch = fgetc(file)) != EOF && ch != '\n') {
      string[i] = ch; 
      i++;
      if((i+1) % 10 == 0) {
         string = realloc(string, 1+ i*sizeof(char) + sizeof(char)*10);
         memset(string + i, 0, 10*sizeof(char));
      }
   }

   /*if line was enter*/
   if(i == 0 && ch == '\n') {
      free(string);
      return NULL;
   }

   /*if ch == EOF then a string of 10 zeros is returned?*/
   return string;
}


/*reads qa.db to populate the tree*/
void populateTree() {
   char * string;
   c = 1;
   
   db = fopen("qa.db", "r");
   tree = calloc(1, sizeof(char*));

   /*while line read from file isn't NULL or EOF*/
   while((string = readlineToPopulateTree(db)) != NULL && string[0] != 0)  {
      tree = realloc(tree, (c+1)*sizeof(char*) );
      memset(tree + c, 0, sizeof(char*));
      tree[c] = string;
      c++;
   }

   fclose(db);

   if(string == NULL) {
      printf("Your database file is corrupted! Looks like someone added an empty line at line number %i.\n", c);
      free(string);
      freeTree();
      exit(1);
   }
   if((c%2)) { /*if even number of lines*/
      printf("Your database file is corrupted! Looks like someone added a non-null line or deleted a line.\n");
      free(string);
      freeTree();
      exit(1);
   }
   free(string);
}

/*element is an answer*/
void answer(char *start, int positionInTree) {
   char ch;
   printf("Is it %s? ", start);
   while( (ch = getc(stdin)) == '\n') {
      printf("An empty response is not acceptable.  Please answer again.\n");
      printf("Is it %s? ", start);
   }
   if( (ch == 'y' || ch == 'Y')) { /*if yes*/
      printf("\nMy, am I clever.  :)\nThanks for playing.\n\n");
      freeTree();
      exit(0);
   }
   else /*if no*/
      getNewElement(*(tree+positionInTree), start, positionInTree);
}
   
/*if element is a question*/
int question(char *start, int yes, int no, int positionInTree) {
   char ch;
   printf("%s ", start);
   while( (ch = getc(stdin)) == '\n') {
      printf("An empty response is not acceptable.  Please answer again.\n"); 
      printf("%s ", start);
   }
   if( (ch == 'y' || ch == 'Y')) /*if yes*/
      positionInTree = yes;
   else /*if no*/
      positionInTree = no;
   return positionInTree;
}

/*the big function, traverses the tree with the user*/
void traverse(void) {
   int positionInTree = 1; /*tree[0] is null*/
   int yes, no;
   char * start, * strfromyes, * strfromno;

   while(*(tree+positionInTree)) {
      yes = strtol(*(tree+positionInTree), &strfromyes, 10);
      no = strtol(strfromyes + 1, &strfromno, 10);
      start = strfromno + 1;

      /*if the element is an answer*/
      if(*(tree+positionInTree)[0] == '-')
         answer(start, positionInTree);

      else /*question*/
         positionInTree = question(start, yes, no, positionInTree);

      while ((getchar()) != '\n'); /*flushes the input buffer*/
   }
   return;
}

/*get new element and update the tree*/
void getNewElement(char * oldAnimal, char * start, int positionInTree) {
   char ch;
   int answer, i; /*value to increment c by when adding element*/
   char * question, * animal;

   printf("\nHow disappointing.\nWhat is it (with article)? ");
   while ((getchar()) != '\n'); /*flushes the input buffer*/
   animal = readInput(-1,-1);
   printf("What is a yes/no question that will distinguish %s from %s?\n? ", animal+6, start);
   question = readInput(c, c+1);
   printf("\nWhat is the answer to the question for %s? ", animal+6);
   while( (ch = getc(stdin)) == '\n') {
      printf("An empty response is not acceptable.  Please answer again.\n");
      printf("\nWhat is the answer to the question for %s? ", animal+6);
   }

   if( (ch == 'y' || ch == 'Y'))
      answer = 0;
   else
      answer = 1;

   /*increase tree by size of 2*/
   tree = realloc(tree, (c+2)*sizeof(char*) );
   memset(tree + c + 0, 0, sizeof(char*));
   memset(tree + c + 1, 0, sizeof(char*));

   *(tree+positionInTree) = question;
   if(answer == 0) {
      *(tree+c) = animal;
      *(tree+c+1) = oldAnimal;
   }
   if(answer == 1) {
      *(tree+c) = oldAnimal;
      *(tree+c+1) = animal;
   }
   c += 2;

   db = fopen("qa.db","w+");
   for(i = 1; i < c; i++) {
      fprintf(db, "%s\n",*(tree+i));
   }
   fclose(db);
   freeTree();

   printf("\nI'll get it next time, I'm sure.\nThanks for playing.\n\n");
   exit(0); 
}


int main() {
   /*if file exists*/
   if(access("qa.db", F_OK) != -1) {
      populateTree();
      traverse();
      return 0;
   }

   /* if file DNE, make a new file and get an animal's name, storing name in file */
   else {
      char * string;
      printf("qa.db: No such file or directory\nUnable to read database qa.db.  Starting fresh.\n\nWhat is it (with article)? ");
      string = readInput(-1,-1);
      db = fopen("qa.db","w+");
      fprintf(db, string);
      free(string);
      fclose(db);
      return 1;
   }
} 
