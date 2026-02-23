#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
	int data;
	struct node *next;
};

typedef struct queue queue;

struct queue {
	node_t *front; // dequeue from here
	node_t *rear; // enqueue from here
	size_t length;
};

queue* queue_init(void);

int enqueue(queue *q, int data);
int dequeue(queue *q);
int is_empty(queue *q);
int peek(queue *q);

#endif
