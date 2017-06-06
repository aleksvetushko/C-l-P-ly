#include <stdio.h>

#include "checkit.h"
#include "part6.h"

/* define testing functions */
void test_create_point1(void)
{
   struct point p = create_point(1.9, -2.7);

   checkit_double(p.x, 1.9);
   checkit_double(p.y, -2.7);
}

void test_create_point2(void)
{
   struct point p = create_point(0.2, 12.1);

   checkit_double(p.x, 0.2);
   checkit_double(p.y, 12.1);
}

void test_create_rectangle(void)
{
   struct point p1 = create_point(5.0, 5.0);
   struct point p2 = create_point(1.0, 1.0);
   struct point p3 = create_point(5.0, 5.0);
   struct point p4 = create_point(1.0, 0.0);

   struct rectangle r = create_rectangle(p1, p2);
   struct rectangle r1 = create_rectangle(p3, p4);
   checkit_double(r.tl.x, 5.0);
   checkit_double(r.tl.y, 5.0);
   checkit_double(r.br.x, 1.0);
   checkit_double(r.br.y, 1.0);

   checkit_int(is_a_square(r), 0);
   checkit_int(is_a_square(r1), 1);
}

void test_create_point(void)
{
   test_create_point1();
   test_create_point2();
   test_create_rectangle();
}

int main(int arg, char *argv[])
{
   /* call testing function(s) here */
   test_create_point();

   return 0;
}
