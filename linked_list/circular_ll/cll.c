#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cll.h"

// the implementation is almost similar to doubly_insert() with an exception that
// the tail and head nodes must be connected to each other and maintained during insertion and removal of node

circular_ll* circular_init(void) {
	circular_ll *list = malloc(sizeof(circular_ll));

	if (!list) {
		fprintf(stderr, "circular_init(): malloc failed\n");
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}


node_t* circular_iter(circular_ll *list, size_t index) {
	// iterator is simply a copy of doubly_iter()
	if (!list) {
		fprintf(stderr, "circular_iter(): list is NULL\n");
		return NULL;
	}

	if (index >= list->length) {
		fprintf(stderr, "circular_iter(): index out of bounds\n");
		return NULL;
	}

	size_t mid = list->length / 2;
	node_t *cursor;

	if (index <= mid) {
		cursor = list->head;
		while (index != 0) { 
			cursor = cursor->next; 
			index--;
		}
	} else {
		cursor = list->tail;
		size_t steps = list->length - index - 1;
		while (steps != 0) { 
			cursor = cursor->prev;
			steps--;
		}
	}
	return cursor;
}

int circular_insert(circular_ll *list, size_t index, int data) {

	if (!list) {
		fprintf(stderr, "circular_insert(): list is NULL\n");
		return 1;
	}

	if (index > list->length) {
		fprintf(stderr, "circular_insert(): index out of bounds\n");
		return 1;
	}

	node_t *new_node = malloc(sizeof(node_t));
	if (!new_node) {
		fprintf(stderr, "circular_insert(): malloc failed\n");
		return 1;
	}

	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (list->length == 0) {
		list->head = new_node;
		list->tail = new_node;

		new_node->next = new_node;
		new_node->prev = new_node;
	} else if (index == 0) {
		new_node->next = list->head;
		new_node->prev = list->tail;

		list->head->prev = new_node;
		list->tail->next = new_node;

		list->head = new_node;
	} else if (index == list->length) {
		new_node->next = list->head;
		new_node->prev = list->tail;

		list->tail->next = new_node;
		list->head->prev = new_node;

		list->tail = new_node;
	} else {
		node_t *on_index_node = circular_iter(list, index);

		new_node->prev = on_index_node->prev;
		new_node->next = on_index_node;

		on_index_node->prev->next = new_node;
		on_index_node->prev = new_node;
	}

	list->length++;
	return 0;
}

void circular_remove(circular_ll *list, size_t index) {
	if (!list) {
		fprintf(stderr, "circular_remove(): list is NULL\n");
		return;
	}

	if (index >= list->length) {
		fprintf(stderr, "circular_remove(): index out of bounds\n");
		return;
	}

	node_t *target;

	if (index == 0) {
		target = list->head;

		if (list->length == 1) {
			list->head = NULL;
			list->tail = NULL;
		} else {
			list->head = target->next;

			list->tail->next = list->head;
			list->head->prev = list->tail;
		}
	}

	else if (index == list->length - 1) {
		target = list->tail;

		list->tail = target->prev;

		list->tail->next = list->head;
		list->head->prev = list->tail;
	}

	else {
		target = circular_iter(list, index);

		target->prev->next = target->next;
		target->next->prev = target->prev;
	}
	free(target);
	list->length--;
}

void circular_print(circular_ll *list) {
	if (!list) {
		fprintf(stderr, "circular_print(): list is NULL\n");
		return;
	}

	if (list->length == 0) {
		printf("List is empty\n");
		return;
	}
	node_t *cursor = list->head;

	do {
		printf("%d <-> ", cursor->data);
		cursor = cursor->next;
	} while (cursor != list->head);

	printf("(back to head)\n");
}

int main(void) {
	circular_ll *list = circular_init();

	circular_insert(list, 0, 10);   
	circular_insert(list, 1, 20);  
	circular_insert(list, 2, 30); 
	circular_insert(list, 1, 15);

	printf("after inserts:\n");
	circular_print(list);

	circular_remove(list, 0);
	printf("after removing head:\n");
	circular_print(list);

	circular_remove(list, list->length - 1);
	printf("after removing tail:\n");
	circular_print(list);

	/* Remove middle */
	if (list->length > 1) {
		circular_remove(list, 1);
		printf("After removing middle index 1:\n");
		circular_print(list);
	}

	printf("final:\n");
	circular_print(list);

	return 0;
}
