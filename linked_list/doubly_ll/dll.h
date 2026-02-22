#ifndef DOUBLY_LL
#define DOUBLY_LL

#include <stdlib.h>

typedef struct node node_t;

struct node {
	int data;
	node_t *next;
	node_t *prev;
};

typedef struct doubly_ll {
	node_t *head;
	node_t *tail; // the list keeps track of head as well as the tail pointer
	size_t length;
} doubly_ll;


doubly_ll* doubly_init(void);
node_t* doubly_iter(doubly_ll *list, size_t index);

int doubly_insert(doubly_ll *list, size_t index, int data);
void doubly_remove(doubly_ll *list, size_t index);
void doubly_print(doubly_ll *list);

#endif
