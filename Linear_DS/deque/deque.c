#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// helper methods
static int deque_is_null(deque *dq) {
	if (dq == NULL) {
		fprintf(stderr, "%s: deque pointer is NULL\n", __func__);
		return 1;
	}
	return 0;
}

static int deque_is_empty(deque *dq) {
	return dq->length == 0; // checks if it's empty
}

static int validate_deque_nonempty(deque *dq) {
	if (deque_is_null(dq)) return 1;
	if (deque_is_empty(dq)) {
		fprintf(stderr, "%s: deque is empty\n", __func__);
		return 1;
	}
	return 0;
}


deque* deque_init(void) {
	deque *dq = malloc(sizeof(deque));
	if (!dq) {
		fprintf(stderr, "%s: malloc failed\n", __func__);
		return NULL;
	}
	dq->front = NULL;
	dq->rear  = NULL;
	dq->length = 0; // initializing default struct
	return dq;
}

// push_front
int push_front(deque *dq, int data) {
	if (deque_is_null(dq)) return 1; // check for nulls 

	node_t *node_to_insert = malloc(sizeof(node_t));
	if (!node_to_insert) {
		fprintf(stderr, "%s: malloc failed\n", __func__);
		return 1;
	}

	node_to_insert->data = data;
	node_to_insert->next = dq->front;
	node_to_insert->prev = NULL;

	if (dq->length == 0) {
		dq->front = node_to_insert;
		dq->rear  = node_to_insert;
	} else {
		dq->front->prev = node_to_insert;
		dq->front = node_to_insert;
	}

	dq->length++;
	return 0;
}


int push_back(deque *dq, int data) {
	if (deque_is_null(dq)) return 1;

	node_t *node_to_insert = malloc(sizeof(node_t));
	if (!node_to_insert) {
		fprintf(stderr, "%s: malloc failed\n", __func__);
		return 1;
	}

	node_to_insert->data = data;
	node_to_insert->next = NULL;
	node_to_insert->prev = dq->rear;

	if (dq->length == 0) {
		dq->front = node_to_insert;
		dq->rear  = node_to_insert;
	} else {
		dq->rear->next = node_to_insert;
		dq->rear = node_to_insert;
	}

	dq->length++;
	return 0;
}

int pop_front(deque *dq) {
	if (validate_deque_nonempty(dq)) return 1;

	node_t *node_to_remove = dq->front;
	dq->front = node_to_remove->next;

	if (dq->front == NULL) {
		dq->rear = NULL; // deque is now empty
	} else {
		dq->front->prev = NULL;
	}

	free(node_to_remove);
	dq->length--;

	return 0;
}

int pop_back(deque *dq) {
	if (validate_deque_nonempty(dq)) return 1;

	node_t *node_to_remove = dq->rear;
	dq->rear = node_to_remove->prev;

	if (dq->rear == NULL) {
		dq->front = NULL; // deque empty
	} else {
		dq->rear->next = NULL;
	}

	free(node_to_remove);
	dq->length--;

	return 0;
}

int is_empty(deque *dq) {
	if (deque_is_null(dq)) return 1;
	return deque_is_empty(dq);
}

int peek_front(deque *dq) {
	if (validate_deque_nonempty(dq)) return -1;
	return dq->front->data;
}

int peek_back(deque *dq) {
	if (validate_deque_nonempty(dq)) return -1;
	return dq->rear->data;
}

// although the behaviour of strcuture is pretty self explanatory. give this article a read if you still don't understand: https://www.geeksforgeeks.org/dsa/deque-set-1-introduction-applications/

int main(void) {
	deque *dq = deque_init();
	if (!dq) {
		printf("Failed to initialize deque\n");
		return 1;
	}

	printf("Push front 10\n");
	push_front(dq, 10);

	printf("Push back 20\n");
	push_back(dq, 20);

	printf("Push front 5\n");
	push_front(dq, 5);

	printf("Front peek: %d\n", peek_front(dq));
	printf("Back peek: %d\n", peek_back(dq));

	printf("Pop front...\n");
	pop_front(dq);
	printf("New front: %d\n", peek_front(dq));

	printf("Pop back...\n");
	pop_back(dq);
	printf("New back: %d\n", peek_back(dq));

	printf("Is empty? %d\n", is_empty(dq));

	printf("Pop last...\n");
	pop_front(dq);

	printf("Is empty now? %d\n", is_empty(dq));

	return 0;
}

