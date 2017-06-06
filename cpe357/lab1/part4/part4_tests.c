#include <stdio.h>
#include "checkit.h"
#include "part4.h"
#include <string.h>
#include <stdlib.h>

void test_str_1()
{
   char string[] = "Hi";
   /*int len = strlen(string);*/
   char * buffer;
   buffer = malloc(sizeof(string));
   checkit_string(str_lower(string, buffer), "hi");
   checkit_string(str_lower_mutate(string), "hi");
}

int main(void)
{
   test_str_1();
   return 0;
}
