#ifndef XOR_LL_H
#define XOR_LL_H

#include <stdio.h>
#include <stdint.h>

typedef struct node node_t;
typedef struct xor_ll xor_ll;

struct node {
	int data;
	uintptr_t both;
};

struct xor_ll {
	struct node *head;
	struct node *tail;
	size_t length;
};

xor_ll* xor_ll_init(void);
node_t* xor_ll_iter(xor_ll *list, size_t index);

int xor_ll_insert(xor_ll *list, size_t index, int data);
int xor_ll_remove(xor_ll *list, size_t index);
void xor_ll_print(xor_ll *list);

#endif
