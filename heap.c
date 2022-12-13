#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
//heap.c ta ok


HEAP* HEAP_create(int n, COMP* compara) {
    //the heap structure is created
    HEAP* heap = malloc(sizeof(heap));
    heap->N = n;
    heap->P = 0;
    heap->elems = (void**) malloc(heap->N*sizeof(void*));
    heap->comparador = compara;
    return heap;
}


void HEAP_add(HEAP* heap, void* newelem) {
    int (*comp)(void*,void*) = heap->comparador;
   
    if (heap->P == 0) {
        //if the heap has no elements, it receives the newelement in its first position
        heap->elems[0] =newelem;
        heap->P++;
        //printf("P is zero\n");
        return;
    } else if (heap->P<heap->N) {
        //if the heap is able to receive a new elems (P<N), it receives at index P.
        heap->elems[heap->P] = newelem;
        heap->P=heap->P+1;
        int i = heap->P-1;
        
        void* fe;void* pai;void* fd;
        
        while (i>0) {
            if (i==0) {
                break;
            }
            if (i%2==1) {
                //if i corresponds to a left-side child, parent = child/2
                fe=heap->elems[i]; pai = heap->elems[i/2];
                if (comp(fe,pai)==1) {
                    //printf("troca fe %d com %d\n",*(int*)heap->elems[i],*(int*)heap->elems[i/2]);
                    void * aux = heap->elems[i/2];
                    heap->elems[i/2] = heap->elems[i];
                    heap->elems[i] = aux;
                }
            } else {
                //if i corresponds to a right-side child, parent = child/2-1
                fd=heap->elems[i]; pai = heap->elems[i/2-1];
                if (comp(fd,pai)==1) {
                    
                    void * aux = heap->elems[i];
                    heap->elems[i] = heap->elems[i/2-1];
                    heap->elems[i/2-1] = aux;
                }
            }
            //now we "bubble up"
            if (i%2==1) {
                i = i /2;
            } else {
                i = i/2 -1;
            }
        }
        
        return;
    } else {
        //this condition happens if P == N;
        return;
    }
    
}
