#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct deque deque;

struct deque {
	node_t *front;
	node_t *rear;
	size_t length;
};

deque* deque_init(void);

int push_front(deque *dq, int data); // insert element on the front
int push_back(deque *dq, int data); // on the back

int pop_front(deque *dq);
int pop_back(deque *dq);

int is_empty(deque *dq);

int peek_front(deque *dq);
int peek_back(deque *dq);

#endif
