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
  if (pq == NULL || pq->size == 0){
    return NULL;
  }
  return pq->heapArray[0].data;
}


void recorrerHeap(Heap* pq, int current){
  if (current == 0){
    return; // El elemento está en la raíz, no hay padre
  }
  
  int parent=(current-1)/2;
  if (pq->heapArray[current].priority>pq->heapArray[parent].priority){
    heapElem aux=pq->heapArray[current];
    pq->heapArray[current]=pq->heapArray[parent];
    pq->heapArray[parent]=aux;
    recorrerHeap(pq,parent);
  }
}

void heap_push(Heap* pq, void* data, int p){
  if (pq->size==pq->capac){
    pq->capac=(pq->capac*2)+1;
    pq->heapArray=(heapElem*) realloc(pq->heapArray,sizeof(heapElem)*pq->capac);
  }
  pq->heapArray[pq->size].data=data;
  pq->heapArray[pq->size].priority=p;
  recorrerHeap(pq, pq->size);
  pq->size++;
}

void swap(heapElem* a, heapElem* b){
  heapElem temp=*a;
  *a=*b;
  *b=temp;
}

void heap_pop(Heap* pq){
  swap(&pq->heapArray[0], &pq->heapArray[pq->size-1]);
  pq->size--;
  heapify_down(pq, 0);
  if(pq->size <= pq->capac/4){
    int new_capacity = pq->capac/2;
    pq->heapArray = realloc(pq->heapArray, sizeof(heapElem)*new_capacity);
    pq->capac = new_capacity;
  }
}


Heap* createHeap(){
  Heap* heap = (Heap*) malloc(sizeof(Heap));
  heap->heapArray = (heapElem*) malloc(sizeof(heapElem) * 3);
  heap->size = 0;
  heap->capac = 3;
  return heap;
}