#include <stdio.h>
#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H

/*The following function pointer receives a function that compares elements of any type (x and y)*/
typedef int COMP(void* x, void* y);


typedef struct heap{
	int N;//size of the vector
	int P;//number of elements in the vector
	void** elems;//a vector that accepts any types of elements
	COMP* comparator;//the comparison function
}HEAP;


HEAP* HEAP_create(int n, COMP* compare);

/*the following function adds an element 'newelem' of generic type*/
void HEAP_add(HEAP* heap, void* newelem);

/*The following function removes the last element*/
void* HEAP_remove(HEAP* heap);


#endif