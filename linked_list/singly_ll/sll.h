#ifndef SINGLY_LL
#define SINGLY_LL

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
	int data;
	node_t *next;
};

typedef struct singly_ll {
	node_t *head;
	size_t length;
} singly_ll;


singly_ll* singly_init(void);
node_t* singly_iter(singly_ll *list, size_t index);

int singly_insert(singly_ll *list, size_t index, int data);
void singly_remove(singly_ll *list, size_t index);
void singly_print(singly_ll *list);

#endif
