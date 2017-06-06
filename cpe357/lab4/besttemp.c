
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
static Header *freep = NULL; /*start of the free list*/

static Header *morecore(size_t);


void *lab_malloc(size_t nbytes)
{
   Header *p, *prevp, *start; 
   Header *bestp = NULL, *bestprevp = NULL;
   size_t nunits;

   nunits = (nbytes + sizeof(Header) - 1)/ sizeof(Header) + 1;
   if ((start = freep) == NULL) {
      base.s.ptr = freep = start = prevp = &base;
      base.s.size = 0;
   }

   /*find the first adequate ptr, if there is one*/
   for (p = start; ; prevp = p, p = p->s.ptr) {
      if(p->s.size >= nunits) {
         bestp = p;
         bestprevp = prevp;
         break;
      }
      if (p == freep) {
         if ((p = morecore(nunits)) == NULL)
            return NULL;
      }
   }

   /*find best ptr*/
   /*the problem is that p == freep somewhere early on; if i just run the loop 100 times it works*/
   for (p = start; p != freep; prevp = p, p = p->s.ptr) {
      if (p->s.size >= nunits) {
         if (p->s.size < bestp->s.size) {
            bestp = p;
            bestprevp = prevp;
         }
         
      }
   }
/*printf("p %p, p.s.ptr %p size %li\n", (void*)p, (void*)p->s.ptr, (long)p->s.size);*/
   if (bestp->s.size == nunits) {
      if(bestp == freep) {
         freep = bestp->s.ptr;
      }
      bestprevp->s.ptr = bestp->s.ptr;
   }
   else {
      if(freep == bestp) {
         bestp->s.size -= nunits;
         freep = bestp;
         freep->s.ptr = bestp->s.ptr;
         bestp += bestp->s.size;
         bestp->s.size = nunits;
      }
      else {
         bestp->s.size -= nunits;
         bestp += bestp->s.size;
         bestp->s.size = nunits;
      }
   }

   /*when changing from freep to freep->s.ptr this chnages the value
   freep->s.ptr = bestprevp;*/
   return (void *)(bestp + 1);
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


