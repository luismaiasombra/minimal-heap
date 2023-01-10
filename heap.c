#include <stdio.h>
#include <stdlib.h>
#include "heap.h"



HEAP* HEAP_create(int n, COMP* comparePointer) {
    //the heap structure is created
    HEAP* heap = malloc(sizeof(heap));
    heap->N = n;
    heap->P = 0;
    heap->elems = (void**) malloc(heap->N*sizeof(void*));
    heap->comparator = comparePointer;
    return heap;
}


void HEAP_add(HEAP* heap, void* newelem) {
    //the following function pointer receives the heap's comparison function adress
    int (*comp)(void*,void*) = heap->comparator;
   
    if (heap->P == 0) {
        //if the heap has no elements, it receives the newelement at its first position
        heap->elems[0] =newelem;
        heap->P++;
        //printf("P is zero\n");
        return;
    } else if (heap->P<heap->N) {
        //if the heap is able to receive a new elems (P<N), it receives at index P (last index).
        heap->elems[heap->P] = newelem;
        heap->P=heap->P+1;
        int i = heap->P-1;
        
        void* leftChild;void* parent;void* rightChild;
        
        while (i>0) {
            if (i==0) {
                break;
            }
            if (i%2==1) {
                //if i corresponds to a left-side child, parent = child/2
                leftChild=heap->elems[i]; parent = heap->elems[i/2];
                if (comp(leftChild,parent)==1) {
                    //printf("troca leftChild %d com %d\n",*(int*)heap->elems[i],*(int*)heap->elems[i/2]);
                    void * aux = heap->elems[i/2];
                    heap->elems[i/2] = heap->elems[i];
                    heap->elems[i] = aux;
                }
            } else {
                //if i corresponds to a right-side child, parent = child/2-1
                rightChild=heap->elems[i]; parent = heap->elems[i/2-1];
                if (comp(rightChild,parent)==1) {
                    
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
