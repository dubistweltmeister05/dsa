#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
	int data;
	struct node *next;
};

typedef struct stack stack;

struct stack {
	node_t *head;
	size_t length;
};

stack* stack_init(void);

int push(stack *stk, int data);
int pop(stack *stk);
int is_empty(stack *stk);

int peek(stack *stk);

