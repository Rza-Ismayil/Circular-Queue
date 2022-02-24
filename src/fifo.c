#include "fifo.h"

// implemented functions:

int constructFifo(SFifo *p, int nQSize) {
  if (nQSize < 0) return 1;

  p->pFifo = (int *) calloc(nQSize, sizeof(int));
  if (p->pFifo == NULL) return 2;

  p->nQSize = nQSize;
  p->iEnQueue = p->iDeQueue = p->nNbElts = 0;
  
  return 0;
}

int enQueue(SFifo *p, int n) {
  if (p->nNbElts == p->nQSize) return  1;

  p->pFifo[p->iEnQueue] = n;
  p->nNbElts++;
  p->iEnQueue = (p->iEnQueue + 1) % p->nQSize;
  
  return 0;
}

int deQueue(SFifo *p) {
  if (p->nNbElts == 0) return 1;

  p->nNbElts--;
  p->iDeQueue = (p->iDeQueue + 1) % p->nQSize;

  return 0;
}

int printQueue(SFifo *p) {
  if (p->nNbElts == 0) {
    return 1;
  }
  for (int i = p->iDeQueue; i < p->iDeQueue + p->nNbElts; i++) {
    printf("%d ", p->pFifo[i % p->nQSize]);
  }
  printf("\n"); return 0;
}

int destructFifo(SFifo *p) {
  if (p ->pFifo == NULL) return 1;
  free(p->pFifo);
  return 0;
}