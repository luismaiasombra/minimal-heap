#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
//heap.c ta ok


HEAP* HEAP_create(int n, COMP* compara) {
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
        
        heap->elems[0] =newelem;
        heap->P++;
        //printf("P is zero\n");
        return;
    } else if (heap->P<heap->N) {
        heap->elems[heap->P] = newelem;
        heap->P=heap->P+1;
        int i = heap->P-1;
        
        void* fe;void* pai;void* fd;
        
        while (i>0) {
            if (i==0) {
                break;
            }
            if (i%2==1) {
                //se o i for filho esquerda, neste caso pai = filho/2
                fe=heap->elems[i]; pai = heap->elems[i/2];
                if (comp(fe,pai)==1) {
                    //printf("troca fe %d com %d\n",*(int*)heap->elems[i],*(int*)heap->elems[i/2]);
                    void * aux = heap->elems[i/2];
                    heap->elems[i/2] = heap->elems[i];
                    heap->elems[i] = aux;
                }
            } else {
                
                //se o i for índice de filho direito, pai = filho/2-1
                //se o i for filho esquerdo, neste caso pai = filho/2
                fd=heap->elems[i]; pai = heap->elems[i/2-1];
                if (comp(fd,pai)==1) {
                    
                    void * aux = heap->elems[i];
                    heap->elems[i] = heap->elems[i/2-1];
                    heap->elems[i/2-1] = aux;
                }
            }
            
            if (i%2==1) {
                i = i /2;
            } else {
                i = i/2 -1;
            }
        }
        
        return;
    } else {
        //printf("the heap is complete\n");
        //quando o P é igual a N
        return;
    }
    
}
