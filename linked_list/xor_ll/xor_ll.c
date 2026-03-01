// this article was use for implementation (and a lil bit of gpitty to understand xor_ll_remove():
// https://www.techiedelight.com/xor-linked-list-overview-implementation-c-cpp/ 

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

node_t* xor_ll_iter(xor_ll *list, size_t index) {

	/* iterate: optimized iterator which moves either from head or tail depending on the index */
	size_t mid_index = list->length / 2;

	node_t *curr, *prev = NULL, *next = NULL;

	if (index <= mid_index) {
		curr = list->head;

		while (index != 0 && curr != NULL) {
			next = get_next(curr, prev); // get next pointer by xoring curr->both, prev
			prev = curr;
			curr = next;
			index--;
		}

	} else {
		size_t steps = list->length - index - 1; // calc. index <from> the tail node instead of head

		curr = list->tail;

		while (steps != 0 && curr != NULL) {
			prev = get_prev(curr, next);
			next = curr;
			curr = prev;
			steps--;
		}
	}

	return curr;
}

xor_ll* xor_ll_init(void) {
	xor_ll *list = malloc(sizeof(xor_ll));

	if (list == NULL) {
		fprintf(stderr, "malloc fail\n");
		return NULL;
	}

	list->head = list->tail = NULL;
	list->length = 0;
	return list;
}

int xor_ll_insert(xor_ll *list, size_t index, int data) {
	if (!list) return 1;

	if (index > list->length) {
		fprintf(stderr, "xor_ll_insert(): index out of bounds\n");
		return 1;
	}

	node_t *node_to_insert = malloc(sizeof(node_t));
	if (!node_to_insert) return 1;

	node_to_insert->data = data;
	node_to_insert->both = 0; // uintptr_t type

	if (list->head == NULL) { // fresh list

		node_to_insert->both = (uintptr_t)NULL; 
		list->head = list->tail = node_to_insert; // new list shall have both <head> <tail> as one

	} else {

		if (index == 0) { // head node

			node_t *old_head = list->head;
			node_t *old_head_next = get_next(old_head, NULL);

			old_head->both = (uintptr_t)xor_opr(node_to_insert, old_head_next);
			node_to_insert->both = (uintptr_t)xor_opr(NULL, old_head);

			list->head = node_to_insert;

		} else if (index == list->length) { // tail node

			node_t *old_tail = list->tail;
			node_t *old_tail_prev = get_prev(old_tail, NULL);

			old_tail->both = (uintptr_t)xor_opr(old_tail_prev, node_to_insert);
			node_to_insert->both = (uintptr_t)xor_opr(old_tail, NULL);

			list->tail = node_to_insert;

		} else { // requires iter

			node_t *idx_node = xor_ll_iter(list, index);
			node_t *prev = xor_ll_iter(list, index - 1);
			node_t *next = idx_node; 

			/*
			 * inserting on mid index is bit complex becacuse
			 * we have to rewire the prev and next ptr:
			 * prev <-> node_to_insert <-> next 
			 * 
			*/

			node_t *prev_prev = get_prev(prev, idx_node); // getting the prev of previous node!
			prev->both = (uintptr_t)xor_opr(prev_prev, node_to_insert);

			node_t *next_next = get_next(next, prev); // next of next node!
			next->both = (uintptr_t)xor_opr(node_to_insert, next_next);

			node_to_insert->both = (uintptr_t)xor_opr(prev, next);
		}
	}

	list->length++;
	return 0;
}

int xor_ll_remove(xor_ll *list, size_t index) {

	if (!list) return 1;
	if (index >= list->length) return 1;

	node_t *node_to_remove;

	if (index == 0) {

		node_to_remove = list->head;
		node_t *next = get_next(node_to_remove, NULL); // fetching next node of <node_to_remove>
		if (next != NULL) {
			node_t *next_next = get_next(next, node_to_remove); // fetching next's next node
			next->both = (uintptr_t)xor_opr(NULL, next_next); 
			// we rewrite from next->both = <node_to_remoe> XOR <next_next>  to <NULL> XOR <next_next>
		}
		list->head = next;

		if (list->length == 1) { 
			list->tail = NULL;
		}

	} else if (index == list->length - 1) {

		node_to_remove = list->tail;
		node_t *prev = get_prev(node_to_remove, NULL);

		if (prev != NULL) {
			node_t *prev_prev = get_prev(prev, node_to_remove);
			prev->both = (uintptr_t)xor_opr(prev_prev, NULL);
		}

		list->tail = prev;

	} else {
		/*
		 * before we directly rewrite <prev> -- <curr> -- <next> we have to rewrite the other side 
		 * of each node. otherwise,it'll be impossible to derive the correct pointers later.
		 * prev->both = prev_prev XOR nexta
		 * next->both = prev XOR next_next
		*/
		node_t *curr = xor_ll_iter(list, index);
		node_t *prev = xor_ll_iter(list, index - 1);
		node_t *next = xor_ll_iter(list, index + 1);

		node_t *prev_prev = get_prev(prev, curr); 
		node_t *next_next = get_next(next, curr);

		prev->both = (uintptr_t)xor_opr(prev_prev, next);// rewire prev to skip curr pointer
		next->both = (uintptr_t)xor_opr(prev, next_next);

		node_to_remove = curr;
	}

	free(node_to_remove);
	list->length--;
	return 0;
}

void xor_ll_print(xor_ll *list) {
	if (!list) {
		fprintf(stderr, "xor_ll_print(): list is NULL\n");
		return;
	}

	node_t *curr = list->head;
	node_t *prev = NULL;
	node_t *next;
	while (curr != NULL) {
		printf("%d <-> ", curr->data);
		next = get_next(curr, prev);
		prev = curr;
		curr = next;
	}
	printf("NULL\n");
}

int main(void) {

	xor_ll *list = xor_ll_init();

	xor_ll_insert(list, 0, 21);
	xor_ll_insert(list, 1, 33);
	xor_ll_insert(list, 1, 10);

	xor_ll_print(list);

	xor_ll_remove(list, 1);

	xor_ll_print(list);

	return 0;
}
