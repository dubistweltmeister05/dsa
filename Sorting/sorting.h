#ifndef __SORTING_H_
#define __SORTING_H_

#include <stdlib.h>

enum sorting {
	BUBBLE=1,
	SELECTION,
	INSERTION
};

int bubble_sort(int *arr, int size);
void print_ele(int *arr, int sie);

#endif
