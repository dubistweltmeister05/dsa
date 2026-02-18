#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 3

void display_array(int **arr) {
	int i = 0, j = 0;

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("%4d ", arr[i][j]);
		}
		printf("\n");
	}
}

int allocate_2d(int ***arr) {
	int i = 0;
	*arr = malloc(sizeof(int *) * ROWS);

	if (*arr == NULL) {
		printf("Failed to allocate memory for ROWS");
		return -1;
	}

	for (i = 0; i < ROWS; i++) {
		/* (*arr) is the array of row pointers */
		/* (*arr)[i] is the i-th row pointer */
		(*arr)[i] = malloc(sizeof(int) * COLS);
		if (!arr[i]) {
			printf("Failed to allocate memory for COLS \n");
			return -1;
		}
	}

	return 0;
}

void get_elements(int **arr) {
	int i = 0, j = 0;

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("arr[%d][%d] =  ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void free_arr(int **arr) {
	int i = 0;

	for (i = 0; i < ROWS; i++) {
		free(arr[i]);
	}

	free(arr);
}

int main(int argc, char *argv[]) {
	int **arr = NULL;

	printf("ROWS = %d COLS  = %d\n", ROWS, COLS);
	int ret = allocate_2d(&arr);
	if (ret != 0) {
		printf("failed to allocate memory\n");
	}

	get_elements(arr);

	transpose_matrix(arr);
	if (arr != NULL) {
		printf("******* Matrix ********\n");
		display_array(arr);
		free_arr(arr);
	}

	return 0;
}
