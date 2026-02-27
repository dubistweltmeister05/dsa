#include <stdio.h>
#include <sorting.h>

void print_ele(int *arr, int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please enter the size to allocate the memory via argument\n");
		printf("USAGE: ./sorting_techniques <SIZE>\n");
		return -1;
	}

	int i = 0;
	int res = 0;
	int choice = 0;
	int *arr = NULL;
	int size = atoi(argv[1]);

	printf("Size = %d\n", size);
	arr = malloc(sizeof(int) * size);

	if (!arr) {
		printf("failed to allocate memory\n");
		return -1;
	}

	printf("Enter the %d elements of array\n", size);
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Before sorting\n");
	print_ele(arr, size);

	printf("Select sorting technique\n 1. BUBBLE\t 2.SELECTION\n");
	scanf("%d", &choice);

	switch(choice){
	case BUBBLE:
		res = bubble_sort(arr, size);
		break;
	case SELECTION:
		res = selection_sort(arr, size);
		break;
	default:
		printf("Invalid choice\n");
	}

	if (res < 0) {
		printf("sorting failed\n");
	} else {
		printf("Sorting success\n");
	}

	printf("After sorting\n");
	print_ele(arr, size);

	if (arr) {
		free(arr);
	}

	return 0;
}
