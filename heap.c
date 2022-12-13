#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
//heap.c ta ok

/*

typedef struct heap{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}HEAP;

*/
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
        //printf("inserindo %d \n",*(int*)newelem);
        heap->elems[0] =newelem;
        heap->P++;
        //printf("P is zero\n");
        return;
    } else if (heap->P<heap->N) {
        heap->elems[heap->P] = newelem;
        heap->P=heap->P+1;
        int i = heap->P-1;
        //printf("inserindo %d \n",*(int*)newelem);
        //printf("iniciando no i = %d\n",i);
        void* fe;void* pai;void* fd;
        //printf("last element is %p at index %d\n", heap->elems[i],i);
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
                
                //se o i for index de filho direito, pai = filho/2-1
                //se o i for filho esquerda, neste caso pai = filho/2
                fd=heap->elems[i]; pai = heap->elems[i/2-1];
                if (comp(fd,pai)==1) {
                    //printf("troca fd %d com %d\n",*(int*)heap->elems[i],*(int*)heap->elems[i/2-1]);
                    void * aux = heap->elems[i];
                    heap->elems[i] = heap->elems[i/2-1];
                    heap->elems[i/2-1] = aux;
                }
            }
            //printf("up to level %d\n",i);
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
    //printf("fim das trocas\n");
}
/*
void* HEAP_remove(HEAP* heap) {
    return;
    void* last = heap->elems[heap->P-1];
    void* lixo = heap->elems[0];
    heap->elems[0] = last; int i = 0; void* fd;void* fe;void* aux;
    while (i<heap->N/2) {
        fe = heap->elems[2*i];fd = heap->elems[2*i+1];
        if (heap->comparador(fe,fd)==-1) { //filho esquerdo maior que o direito
            int k =0;
        } else {
            int k =0;
        }
    }
    //diminuir o P e ajeitar a posicao
    return heap;
}
*/