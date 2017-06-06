#include <stdio.h>

#include "checkit.h"
#include "part3.h"

void test_sum_1()
{
   int arr[6] = {5, 6, 7, 8, 9, 1};
   checkit_int(sum(arr, 6), 36);
   checkit_int(sum(arr, 0), 0);
}

void test_sum()
{
   test_sum_1();
}

int main(void)
{
   test_sum();
   return 0;
}
