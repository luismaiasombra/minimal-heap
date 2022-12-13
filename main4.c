#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"


int comparacao(void* x, void* y){
    int* xi = (int*) x;//ponteiro de inteiro
    if((int*)x == (int*)y){
        return 0;
    }else if((int*)x > (int*)y){
        return -1;
    }else{
        return 1;
    }
}

int main(){

    COMP* comparador = comparacao; //nao precisa do &
    VETORORD* vetor = VETORD_create(10, comparador);
    
    VETORD_add(vetor, (int*) 3);
    VETORD_remove(vetor);
    VETORD_add(vetor, (int*) 4);
    VETORD_add(vetor, (int*) 6);
    VETORD_add(vetor, (int*) 7);
    VETORD_add(vetor, (int*) 8);
    VETORD_add(vetor, (int*) 5);
    VETORD_add(vetor, (int*) 4);
    VETORD_add(vetor, (int*) 2);
    
    for(int i = 0;i<vetor->P;i++){
        printf("%d\n", vetor->elems[i]);
    }

    return 0;
}