#ifndef __SORTING_H_
#define __SORTING_H_

#include <stdlib.h>

enum sorting {
	BUBBLE=1,
	SELECTION,
	INSERTION
};

int bubble_sort(int *arr, int size);
int selection_sort(int *arr, int size);
int insertion_sort(int *arr, int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void print_ele(int *arr, int sie);

#endif
