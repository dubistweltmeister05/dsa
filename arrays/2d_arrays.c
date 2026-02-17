#include <stdio.h>

#define NUM 3

void display_array(int arr[NUM][NUM]) {
	int i = 0, j = 0;

	for (i = 0; i < NUM; i++) {
		for (j = 0; j < NUM; j++) {
			printf("arr[%d][%d] = %d ", i, i, arr[i][j]);
		}
		printf("\n");
	}
}

void transpose(int arr[NUM][NUM]) {
	int i = 0, j = 0, temp = 0;

	for (i = 0; i < NUM; i++) {
		for (j = i + 1; j < NUM; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
}

int main(int argc, char *argv[]) {
	int arr[NUM][NUM] = {{1, 2, 3},
			     {4, 5, 6},
			     {7, 8, 9}};

	printf("Before Transpose\n");
	display_array(arr);

	printf("After Transpose\n");
	transpose(arr);
	display_array(arr);

	return 0;
}
