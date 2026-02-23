#ifndef CIRCULAR_LL
#define CIRCULAR_LL

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
	int data;
	node_t *next;
	node_t *prev;
};

typedef struct circular_ll {
	node_t *head;
	node_t *tail; // the list keeps track of head as well as the tail pointer
	size_t length;
} circular_ll;


circular_ll* circular_init(void);
node_t* circular_iter(circular_ll *list, size_t index);

int circular_insert(circular_ll *list, size_t index, int data);
void circular_remove(circular_ll *list, size_t index);
void circular_print(circular_ll *list);

#endif
