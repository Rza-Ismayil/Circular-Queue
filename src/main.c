#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int main(){
  int n, nErrNo=1; // nErrNo for Error Number
  SFifo myFifo;

  printf("Enter a queue size > 0: ");scanf("%d",&n);
  nErrNo=constructFifo(&myFifo,n);
  if (nErrNo){
    fprintf(stderr,"Error code %d while creating the queue\n",nErrNo);
    return 1;
  }
  
  printf("enQueue positive numbers (dequeue with -1, end with -2)\n");
  while (n!=-2){
    scanf("%d",&n);
    if (n == -2) break;
    if (n == -1) deQueue(&myFifo);
    else enQueue(&myFifo,n);
    printQueue(&myFifo);    
  }

  destructFifo(&myFifo);

  return 0;
}
