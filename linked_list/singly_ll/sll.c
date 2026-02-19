#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sll.h"

singly_ll* singly_init(void) {
	singly_ll *list = malloc(sizeof(singly_ll));
	if (list == NULL) {
		fprintf(stderr, "singly_init(void): malloc failed\n");
		return NULL;
	}

	list->head = NULL;
	list->length = 0; 

	return list;
}

node_t* singly_iter(singly_ll *list, size_t index) {
	if (list == NULL) {
		fprintf(stderr, "singly_iter(): list is NULL\n");
		return NULL;
	}

	if (index >= list->length) {
		fprintf(stderr, "singly_iter(): index out of bounds\n");
		return NULL;
	}

	node_t *cursor = list->head;

	for (size_t i = 0; i < index; i++) { // iterating till the <index> and returning the node on that index
		if (cursor == NULL) {
			return NULL;
		}
		cursor = cursor->next;
	}

	return cursor;
}

int singly_insert(singly_ll *list, size_t index, int data) {
	if (list == NULL) {
		fprintf(stderr, "singly_insert(): list is NULL\n");
		return 1;
	}

	if (index > list->length) {
		fprintf(stderr, "singly_insert(): index out of bounds\n");
		return 1;
	}

	node_t *node_to_insert = malloc(sizeof(node_t));
	if (node_to_insert == NULL) {
		fprintf(stderr, "singly_insert(): malloc failed\n");
		return 1;
	}

	node_to_insert->data = data;
	node_to_insert->next = NULL;

	// insert at head
	if (index == 0) {
		node_to_insert->next = list->head; 
		list->head = node_to_insert;
	} else {
		node_t *prev = singly_iter(list, index - 1);
		if (prev == NULL) {
			free(node_to_insert);
			return 1;
		}
		node_to_insert->next = prev->next;
		prev->next = node_to_insert;
	}

	list->length++;
	return 0;
}

void singly_remove(singly_ll *list, size_t index) {
	if (list == NULL) {
		fprintf(stderr, "singly_remove(): list is NULL\n");
		return;
	}

	if (index >= list->length) {
		fprintf(stderr, "singly_remove(): index out of bounds\n");
		return;
	}

	node_t *node_to_delete;

	// remove head
	if (index == 0) {
		node_to_delete = list->head;
		list->head = node_to_delete->next;
	} else {
		node_t *prev = singly_iter(list, index - 1);
		if (prev == NULL || prev->next == NULL) {
			fprintf(stderr, "singly_remove(): invalid index\n");
			return;
		}
		node_to_delete = prev->next;
		prev->next = node_to_delete->next;
	}

	free(node_to_delete);
	list->length--;
}

void singly_print(singly_ll *list) {
	if (list == NULL) {
		fprintf(stderr, "singly_print(): the list is NULL\n");
		return;
	}

	node_t *cursor = list->head;


	while (cursor != NULL) {
		printf("%d -> ", cursor->data);
		cursor = cursor->next;
	}
	printf("NULL\n");
}

int main(void) {
	singly_ll *list = singly_init();
	printf("===> inserting integers 32, 69, 64 <===\n");
	singly_insert(list, 0, 32);
	singly_insert(list, 0, 69);
	singly_insert(list, 0, 64);

	singly_print(list);
	printf("===> removing node on index 1 <===\n");
	singly_remove(list, 1);
	singly_print(list);

	return 0;
}
