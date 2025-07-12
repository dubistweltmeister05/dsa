#include <stdio.h>
#include <string.h>
#include <stdint.h>

int bin_sea(int *a, int size, int target){
	int left=0, right=size-1;
	while(left<right){
		int mid=(left+right)/2;

		if(a[mid]==target)
		{
			printf("The number is at %d\n",mid);
			return 1;
		}
		if(a[mid]>target)
			right=mid;
		if(a[mid]<target)
			left = mid+1;

	}

	printf("Couldn't find the number\n");

	printf("--------------------------------------");

	return -1;
}
int main(void){
int arr[11] = {1,2,4,6,21,34,56,78,89,99,100};
int x= 0;
printf("enter a nubmer that you'd like to search for ");
scanf("%d",&x);
int a =	bin_sea(arr,11,x);
return 0;
}

