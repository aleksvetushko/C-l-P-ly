
char * readInput(int yes, int no);
char * readlineToPopulateTree(FILE * file);
void populateTree();
void freeTree(void);
void traverse(void);
void getNewElement(char * oldAnimal, char * start, int positionInTree);
void answer(char *start, int positionInTree);
int question(char *start, int yes, int no, int positionInTree);
