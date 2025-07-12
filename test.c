#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct node{
	int data;
	struct node* next;
};

int main(void){
printf("%d\n", sizeof(struct node));
return 0;
}

