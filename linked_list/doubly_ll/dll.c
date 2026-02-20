#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dll.h"


doubly_ll* doubly_init(void) {
	doubly_ll *list = malloc(sizeof(doubly_ll));
	if (list == NULL) {
		fprintf(stderr, "doubly_init(void): malloc failed\n");
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	return list;
}

node_t* doubly_iter(doubly_ll *list, size_t index) {
	if (list == NULL) {
		fprintf(stderr, "doubly_iter(): list is NULL\n");
		return NULL;
	}

	if (index >= list->length) {
		fprintf(stderr, "doubly_iter(): index out of bounds\n");
		return NULL;
	}

	// this optimization for iteration makes doubly ll much more flexible for traversal. since the list
	// can be traversed from either <head> or <tail> nodes using next and prev pointers

	size_t mid_index = list->length / 2;
	node_t *cursor;

	if (index <= mid_index) {
		cursor = list->head;
		while (index != 0) {
			cursor = cursor->next;
			index--;
		}
	} else {
		cursor = list->tail;
		size_t steps = list->length - index - 1; // steps is basically <index> but from the tail pointer perspective!
		while (steps != 0) {
			cursor = cursor->prev;
			steps--;
		}
	}
	return cursor;
}

int doubly_insert(doubly_ll *list, size_t index, int data) {
	if (list == NULL) {
		fprintf(stderr, "doubly_insert(): list is NULL\n");
		return 1;
	}

	if (index > list->length) {
		fprintf(stderr, "doubly_insert(): index out of bounds\n");
		return 1;
	}

	node_t *node_to_insert = malloc(sizeof(node_t));
	if (node_to_insert == NULL) {
		fprintf(stderr, "doubly_insert(): malloc failed\n");
		return 1;
	}

	node_to_insert->data = data;
	node_to_insert->next = NULL;
	node_to_insert->prev = NULL;

	/* insert at head */
	if (index == 0) {
		if (list->length == 0) { // if the list is newly initialized
			list->head = node_to_insert;
			list->tail = node_to_insert;   
		} else {
			node_to_insert->next = list->head;
			list->head->prev = node_to_insert;
			list->head = node_to_insert;
		}
	} else if (index == list->length) {
		node_to_insert->prev = list->tail;
		list->tail->next = node_to_insert;
		list->tail = node_to_insert;
	} else {
		node_t *on_index_node = doubly_iter(list, index);

		if (on_index_node == NULL) {
			free(node_to_insert);
			return 1;
		}
		node_to_insert->prev = on_index_node->prev;
		node_to_insert->next = on_index_node;

		on_index_node->prev->next = node_to_insert;
		on_index_node->prev = node_to_insert;
	}
	list->length++;
	return 0;
}

void doubly_remove(doubly_ll *list, size_t index) {
	if (list == NULL) {
		fprintf(stderr, "doubly_remove(): list is NULL\n");
		return;
	}
	if (index >= list->length) {
		fprintf(stderr, "doubly_remove(): index out of bounds\n");
		return;
	}

	node_t *node_to_remove;

	if (index == 0) {
		node_to_remove = list->head;

		if (list->length < 2) {
			list->head = NULL;
			list->tail = NULL;
		} else {
			list->head = node_to_remove->next;
			list->head->prev = NULL;
		}
	} else if (index == list->length - 1) {
		node_to_remove = list->tail;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	} else {
		node_to_remove = doubly_iter(list, index);

		node_to_remove->next->prev = node_to_remove->prev;
		node_to_remove->prev->next = node_to_remove->next;
	}

	free(node_to_remove);
	list->length--;
}

void doubly_print(doubly_ll *list) {
	if (list == NULL) {
		fprintf(stderr, "doubly_print(): the list is NULL\n");
		return;
	}

	node_t *cursor = list->head;

	while (cursor != NULL) {
		printf("%d <-> ", cursor->data);
		cursor = cursor->next;
	}
	printf("NULL\n");
}

int main(void) {
	doubly_ll *list = doubly_init();

	doubly_insert(list, 0, 32);
	doubly_insert(list, 0, 432);
	doubly_insert(list, 1, 2);
	doubly_insert(list, 0, 2);

	doubly_print(list);
	printf("==<< remove element on index 2 >>===\n");
	doubly_remove(list, 2);
	doubly_print(list);
	return 0;
}
