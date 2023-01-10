#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//The following function can be whatever comparison function you want.
int comparison(void* x, void* y){
    if(*(int*)x == *(int*)y){
        return 0;
    }else if(*(int*)x > *(int*)y){
        return -1;
    }else{
        return 1;
    }
}

int main(){
    COMP* comp = comparison;
    int initialSize = 0;
    printf("Size of the vector: ");
    scanf("%d", &initialSize);
    HEAP* heap = HEAP_create(initialSize, comp);
    int in[90] = {};
    int i = 0;
    //the following while-loop adds elements to the heap's vector
    while(in[i] >= 0){
        printf("NUM: ");
        scanf("%d", &in[i]);
        if(in[i] >= 0){
            HEAP_add(heap, &in[i]);
            i++;
        }
    }
    
    
   //the following for-loop prints all elements inside the heap's vector
    for(int i = 0;i<heap->P;i++){
        printf("%d ", *(int*)heap->elems[i]);
    }
    //printf(veto->elems[200]);
    return 0;
}
