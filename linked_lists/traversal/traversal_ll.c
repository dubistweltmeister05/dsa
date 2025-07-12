#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
struct node {
	int data;
	struct node * next;
};

void print_ll(struct node *head){
	struct node* temp = head;

	while(temp->next !=NULL){
		printf("%d\n", temp->data);
		temp=temp->next;
	}
	printf("-----------------------------\n");
}

int main(void){

struct node *head = (struct node *)malloc(sizeof(struct node));
struct node * first = (struct node *)malloc(sizeof(struct node));
struct node * second = (struct node *)malloc(sizeof(struct node));
struct node * third = (struct node *)malloc(sizeof(struct node));
struct node * fourth = (struct node *)malloc(sizeof(struct node));


head->data = 1;
head->next = first;

first->data = 4;
first->next = second;

second->data = 6;
second->next = third;

third->data = 21;
third->next= fourth;

fourth->data = 69;
fourth->next = NULL;

print_ll(head);


return 0;
}

