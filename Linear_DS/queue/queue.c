#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// helper methods

static int queue_is_null(queue *q) {
	if (q == NULL) {
		fprintf(stderr, "%s: queue pointer is NULL\n", __func__);
		return 1;
	}
	return 0;
}

static int queue_is_empty(queue *q) {
	if (q->length == 0) {
		return 1;
	}
	return 0;
}

static int validate_queue_nonempty(queue *q) {
	if (queue_is_null(q)) return 1;
	if (queue_is_empty(q)) {
		fprintf(stderr, "%s: queue is empty\n", __func__);
		return 1;
	}
	return 0;
}

queue* queue_init(void) {
	queue *q = (queue *) malloc(sizeof(queue));
	if (!q) {
		fprintf(stderr, "%s: malloc failed\n", __func__);
		return NULL;
	}
	q->front = NULL;
	q->rear  = NULL;
	q->length = 0;
	return q;
}

int enqueue(queue *q, int data) {
	if (queue_is_null(q)) return 1;

	node_t *node_to_insert = (node_t *)malloc(sizeof(node_t));
	if (!node_to_insert) {
		fprintf(stderr, "%s: malloc failed\n", __func__);
		return 1;
	}

	node_to_insert->data = data;
	node_to_insert->next = NULL;

	if (q->length == 0) {
		q->front = node_to_insert;
		q->rear  = node_to_insert;
	} else {
		q->rear->next = node_to_insert;
		q->rear = node_to_insert;
	}

	q->length++;
	return 0;
}

int dequeue(queue *q) {
	if (validate_queue_nonempty(q)) return 1;

	node_t *node_to_remove = q->front;
	q->front = node_to_remove->next;

	if (q->front == NULL)
		q->rear = NULL; // queue is now empty

	free(node_to_remove);
	q->length--;

	return 0;
}

int is_empty(queue *q) {
	if (queue_is_null(q)) return 1;
	return queue_is_empty(q);
}

int peek(queue *q) {
	if (validate_queue_nonempty(q)) {
		return -1;
	}
	return q->front->data;
}

int main(void) {
    queue *q = queue_init();

    printf("enqueue 10\n");
    enqueue(q, 10);
    printf("enqueue 20\n");
    enqueue(q, 20);
    printf("enqueue 30\n");
    enqueue(q, 30);

    printf("front element by invoking peek() : %d\n", peek(q));

    printf("dequeue invoke.\n");
    dequeue(q);
    printf("New front: %d\n", peek(q));

    printf("dequeue invoked\n");
    dequeue(q);
    printf("New front: %d\n", peek(q));

    printf("Is empty? %d\n", is_empty(q));

    printf("Dequeue last\n");
    dequeue(q);

    printf("is_empty() %d\n", is_empty(q));

    return 0;
}

