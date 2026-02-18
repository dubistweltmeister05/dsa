#include <stdio.h>

void print_arr(char arr[], int size, int index){
    for(int i=index;i<size+index;i++){
        printf("\t%c\n", arr[i%size]);
    }
}

int main(){

    char a[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    int n = sizeof(a) / sizeof(a[0]);
    print_arr(a, n, 3);
    return 0;
}