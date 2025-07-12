#include <stdio.h>
#include <stdint.h>

void display (int *a, int size){
	for(int i=0;i<size;i++){
		printf("%d\n", a[i]);
	}

	printf("\n--------------------------------\n");
}

int delete(int *a, int size, int capacity, int index){
	if(index>=size)
	return -1;

	for(int i=index; i<=size-1;i++){
		a[i]=a[i+1];
	}
	return 1;
}
int main(){
	int size = 9;
	int arr[9] = {1,57,23,75,9,23,86,12,34};
	display(arr,size);

	delete(arr,size,9,9);

	display(arr,--size);
	return 0;
}
