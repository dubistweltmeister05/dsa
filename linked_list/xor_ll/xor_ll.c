#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "xor_ll.h"

static inline node_t* xor_opr(node_t *a, node_t *b) {
	// to understand *uintptr_t* type give this article a read: 
	// https://www.tutorialpedia.org/blog/what-is-the-uintptr-t-data-type/
	return (node_t *)((uintptr_t)(a) ^ (uintptr_t)(b)); // xor operation of prev and next ptrs
}

static inline node_t* get_next(node_t* curr, node_t* prev) {
	return xor_opr((node_t *)curr->both, prev);
}

static inline node_t* get_prev(node_t* curr, node_t* next) {
	return xor_opr((node_t *)curr->both, next);
}

xor_ll* xor_ll_init(void) {
	xor_ll *list = malloc(sizeof(xor_ll));

	if (list == NULL) {
		fprintf(stderr, "malloc fail\n");
		return NULL;
	}

	list->head = list->tail = NULL;
	return list;
}

int xor_ll_insert(xor_ll *list, size_t index, int data) {
	if (!list) return 1;

	node_t *node_to_insert = malloc(sizeof(node_t));
	node_to_insert->data = data;
	node_to_insert->both = 0; // uintptr_t type

	if (list->head == NULL) { // fresh list
		node_to_insert->both = (uintptr_t)node_to_insert;
		list->head = list->tail = node_to_insert; // new list shall have both <head> <tail> as one
		
	} else {
		if (index == 0) { // head node
			node_t *next = get_next(list->head, NULL);
			list->head->both = (uintptr_t)xor_opr(node_to_insert, next); // update the old head both
			node_to_insert->both = (uintptr_t)xor_opr(NULL, list->head);
			list->head = node_to_insert;

		} else if (index == list->length) { // tail node
			node_t *prev = get_prev(list->tail, NULL);
			list->tail->both = (uintptr_t)xor_opr(prev, node_to_insert); 
			node_to_insert->both = (uintptr_t)xor_opr(NULL, list->tail);
			list->tail= node_to_insert;

		} else { // requires iter

		}
	}

	return 0;
}

int xor_ll_remove(xor_ll *list, size_t index);
void xor_ll_print(xor_ll *list);

int main(void) {
	xor_ll *list = xor_ll_init();
	xor_ll_insert(list, 0, 21);
	printf("data; %d\n", list->head->data);
}
