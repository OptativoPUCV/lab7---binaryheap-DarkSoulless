#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void* heap_top(Heap* pq){
  if (pq == NULL || pq->size == 0){
    return NULL;
  }
  return pq->heapArray[0].data;
}


Heap* createHeap(){
  Heap* heap = (Heap*) malloc(sizeof(Heap));
  heap->heapArray = (heapElem*) malloc(sizeof(heapElem) * 3);
  heap->size = 0;
  heap->capac = 3;
  return heap;
}