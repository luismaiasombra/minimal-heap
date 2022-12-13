#include "ordvetor.h"

//creates an instance of type VETORORD, which contains a vector of void elements
VETORORD* VETORD_create(int n,COMP* comparador) {
    VETORORD* vetor_h = malloc(sizeof(VETORORD));
    if (vetor_h==NULL) {
        return NULL;
    }
    
    vetor_h->N = n;
    vetor_h->P = 0;
    vetor_h->elems = (void**) malloc(vetor_h->N*sizeof(void*));
    vetor_h->comparador = comparador;
    return vetor_h;
}
//adds an element to the vector
void VETORD_add(VETORORD* vetor, void * newelem) {
        if (vetor->P>=vetor->N) {
            return;
        }
    
        if (vetor->P<vetor->N) {
            vetor->elems[vetor->P]=newelem;
            vetor->P++;
        }


        for (int i =0;i<vetor->P;i++) {
            for (int j = 0;j<vetor->P;j++) {
                if (vetor->comparador(vetor->elems[i], vetor->elems[j])==1) {
                    void* aux = vetor->elems[i];
                    vetor->elems[i] = vetor->elems[j];
                    vetor->elems[j] = aux;
                }
            }
        }
        return;
}

//this function is to be removed in future versions
void VETOR_add(VETORORD* vetor,void* newelem) {
    int range = vetor->P;
    for (int i = 0;i<range;i++) {
        printf("");
    }
}

//removes first element
void* VETORD_remove(VETORORD* vetor) {
    vetor->P--;
    void* x = vetor->elems[0];
    for (int k =0;k<vetor->P;k++) {
        vetor->elems[k] = vetor->elems[k+1];
    }
    return x;
}
