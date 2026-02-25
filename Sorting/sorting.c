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
