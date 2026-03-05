#include <sorting.h>

int bubble_sort(int *arr, int n) {
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return 0;
}

int selection_sort(int *arr, int n) {
	int i = 0;
	int j = 0;
	int min_idx = 0;

	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			int temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
	}

	return 0;
}

int insertion_sort(int *arr, int n) {
    int i = 0;
    int j = 0;
    int key = 0;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        /* Move elements of arr[0..i-1] that are greater than key
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    return 0;
}
