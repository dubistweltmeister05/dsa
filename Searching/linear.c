#include <stdio.h>

int linear_search(const int *arr, size_t size, int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target) return i;
    }
    return -1;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    int target = 5;
    int idx = linear_search(arr, size, target);
    if(idx!=-1){
        printf("target element found at index: %d\n", idx);
    } else {
        printf("target element not found\n");
    }
    return 0;
}