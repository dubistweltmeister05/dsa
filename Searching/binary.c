#include <stdio.h>

int binary_search(const int *arr, size_t size, int target){
    size_t low = 0;
    size_t high = size-1;
    while(low<=high){
        size_t mid = low + (high - low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    size_t size = sizeof(arr)/sizeof(arr[0]);
    int target = 5;
    int idx = binary_search(arr, size, target);
    if(idx!=-1){
        printf("target element found at index: %d\n", idx);
    } else {
        printf("target element not found\n");
    }
    return 0;
}