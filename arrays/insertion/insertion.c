#include <stdint.h>
#include <stdio.h>

void display (int *a, int size){
	for(int i=0;i<size;i++){
		printf("\n%d\n", a[i]);
	}
	printf("-------------------------------------------");
}

int insertion(int *a, int size, int capacity, int element, int index){
	if(size>=capacity)
		return -1;
	for(int i=size-1; i>=index;i--){
		a[i+1]= a[i];
	} 
	a[index] = element;
	return 1;
}

int main(void){
	int arr[100]= {7,8,12,27,88};
	int size= 5, element = 45, index = 3;
	display(arr,size);
	insertion(arr,size,100,69,index);
	size+=1;
	display(arr,size);
	return 0;
}
