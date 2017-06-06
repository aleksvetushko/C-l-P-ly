#include <stdio.h>
#include <unistd.h>

#include "mem.h"

typedef long Align;

union header
{
   struct
   {
      union header *ptr;
      size_t size;
   } s;
   Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

static Header *morecore(size_t);

void *lab_malloc(size_t nbytes)
{
   Header *p, *prevp, *bestp, *bestprevp;
   size_t nunits;

   nunits = (nbytes + sizeof(Header) - 1)/ sizeof(Header) + 1;
   if ((prevp = freep) == NULL)
   {
      base.s.ptr = freep = prevp = &base;
      base.s.size = 0;
   }

   /*find the first adequate block*/
   for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
   {
      if (p->s.size >= nunits)
      {
         if (p->s.size == nunits)
         {
            prevp->s.ptr = p->s.ptr;
            freep = prevp;
            return (void *)(p + 1);
         }
         else {
            bestp = p;
            bestprevp = prevp;
            break;
         }
      }
      if (p == freep)
      {
         if ((p = morecore(nunits)) == NULL)
         {
            return NULL;
         }
      }
   }
   
   /*go through the free list and find the smallest-sized adequate block*/
   for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
   {
      if (p->s.size >= nunits)
      {
         if (p->s.size < sizeof(bestp))
         {
            bestp = p;
            bestprevp = prevp;
         }
      }
      if (p == freep)
      {
         break;
      }
   }
   
   p = bestp;
   prevp = bestprevp;
   p->s.size -= nunits;
   p += p->s.size;
   p->s.size = nunits;
   freep = prevp;
   return (void *)(p + 1);
}

#define NALLOC 1024
static Header *morecore(size_t nu)
{
   char *cp;
   Header *up;

   if (nu < NALLOC)
   {
      nu = NALLOC;
   }
   cp = sbrk(nu * sizeof(Header));
   if (cp == (char *) -1)
   {
      return NULL;
   }
   up = (Header *) cp;
   up->s.size = nu;
   lab_free((void *)(up + 1));
   return freep;
}

void lab_free(void *ap)
{
   Header *bp, *p;

   bp = (Header *)ap - 1;
   for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
   {
      if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      {
         break;
      }
   }
   if (bp + bp->s.size == p->s.ptr)
   {
      bp->s.size += p->s.ptr->s.size;
      bp->s.ptr = p->s.ptr->s.ptr;
   }
   else
   {
      bp->s.ptr = p->s.ptr;
   }
   if (p + p->s.size == bp)
   {
      p->s.size += bp->s.size;
      p->s.ptr = bp->s.ptr;
   }
   else
   {
      p->s.ptr = bp;
   }
   freep = p;
}

