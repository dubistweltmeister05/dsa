#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


// helper methods: these are basic checks that each method in stack API required again and again!

static int stack_is_null(stack *stk) {
	if (stk == NULL) {
		fprintf(stderr, "%s: stack pointer is NULL\n", __func__);
		return 1;
	}
	return 0;
}

static int stack_is_empty(stack *stk) {
	if (stk->length == 0) {
		return 1;
	}
	return 0;
}

static int validate_stack_nonempty(stack *stk) {
	if (stack_is_null(stk)) return 1;
	if (stack_is_empty(stk)) {
		fprintf(stderr, "%s: stack is empty\n", __func__);
		return 1;
	}
	return 0;
}

// stack data structure methods: https://www.geeksforgeeks.org/dsa/stack-data-structure/

stack* stack_init(void) {
	stack *stk = malloc(sizeof(stack));
	if (!stk) {
		fprintf(stderr, "%s: malloc failed\n", __func__);
		return NULL;
	}
	stk->length = 0;
	stk->head = NULL;
	return stk;
}

int push(stack *stk, int data) {
	if (stack_is_null(stk)) return 1;

	node_t *node_to_insert = malloc(sizeof(node_t));
	if (!node_to_insert) {
		fprintf(stderr, "%s: malloc failed\n", __func__);
		return 1;
	}

	node_to_insert->data = data;
	node_to_insert->next = stk->head;
	stk->head = node_to_insert;
	stk->length++;

	return 0;
}

int pop(stack *stk) {
	if (validate_stack_nonempty(stk)) return 1;

	node_t *node_to_remove = stk->head;
	stk->head = node_to_remove->next;

	free(node_to_remove);
	stk->length--;

	return 0;
}

int is_empty(stack *stk) {
	if (stack_is_null(stk)) return 1;
	return stack_is_empty(stk);
}

int peek(stack *stk) {
	if (validate_stack_nonempty(stk)) {
		return -1;   // Error code; adjust based on API design
	}
	return stk->head->data;
}

int main(void) {
    stack *s = stack_init();
    if (!s) {
        printf("Failed to initialize stack\n");
        return 1;
    }

    printf("Pushing 10\n");
    push(s, 10);
    printf("Pushing 20\n");
    push(s, 20);
    printf("Pushing 30\n");
    push(s, 30);

    printf("Top element (peek): %d\n", peek(s));

    printf("Popping...\n");
    pop(s);
    printf("New top: %d\n", peek(s));

    printf("Popping...\n");
    pop(s);
    printf("New top: %d\n", peek(s));

    printf("Is empty? %d\n", is_empty(s));

    printf("Popping last...\n");
    pop(s);

    printf("is empty now? %d\n", is_empty(s));

    return 0;
}

