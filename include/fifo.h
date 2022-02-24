#ifndef __FIFO__
#define __FIFO__

#include <stdio.h>
#include <stdlib.h>

typedef struct Fifo {
  int iEnQueue, iDeQueue, nQSize, nNbElts; // i for "Index", n for "iNteger"
  int *pFifo;                    // p for "Pointer"
} SFifo;                         // S for "Structure"

// function signatures:
int constructFifo(SFifo *p, int n);
int enQueue(SFifo *p, int n);
int deQueue(SFifo *p);
int printQueue(SFifo *p);
int destructFifo(SFifo *p);

#endif // __FIFO__