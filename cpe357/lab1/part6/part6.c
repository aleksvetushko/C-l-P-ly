#include "part6.h"

struct point create_point(double x, double y)
{
   struct point p;

   p.x = x;
   p.y = y;

   return p;
}

struct rectangle create_rectangle(struct point a, struct point b)
{
   struct rectangle r;

   r.tl.x = a.x;
   r.tl.y = a.y;
   r.br.x = b.x;
   r.br.y = b.y;

   return r;
}

int is_a_square(struct rectangle r)
{
   if(r.tl.x - r.br.x == r.tl.y - r.br.y)
   {
      return 0;
   }
   else{
      return 1;
   }
}
