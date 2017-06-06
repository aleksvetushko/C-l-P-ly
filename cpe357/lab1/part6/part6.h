#ifndef PART5_H
#define PART5_H

struct point
{
   double x;
   double y;
};

struct point create_point(double x, double y);

struct rectangle
{
   struct point tl;
   struct point br;
};

struct rectangle create_rectangle(struct point a, struct point b);

int is_a_square(struct rectangle r);

#endif
