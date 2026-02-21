#include <stdio.h>
#include <stdlib.h>
#include "h_table.h"

static inline node_t* h_new_node(int data) { // new node allocation helper
	node_t *n = malloc(sizeof(node_t));
	if (!n) return NULL;

	n->data = data;
	n->next = NULL;
	return n;
}

table_t* h_table_init(size_t buckets) {
	table_t* table = malloc(sizeof(table_t));
	if (!table) {
		fprintf(stderr, "[h_table:init] malloc failed\n");
		return NULL;
	}

	table->buckets = buckets;
	table->nodes = calloc(buckets, sizeof(node_t *));
	if (!table->nodes) {
		fprintf(stderr, "[h_table:init] calloc failed\n");
		free(table);
		return NULL;
	}

	for (size_t i = 0; i < buckets; i++)
		table->nodes[i] = NULL;

	return table;
}

void table_destruct(table_t *table) { // in order to completely free the allocated space to the table_t structure
	if (!table) return;
	for (size_t i = 0; i < table->buckets; i++) {
		node_t *node = table->nodes[i];
		while(node) { // iterating over the list on each <bucket>
			node_t *next = node->next;
			free(node);
			node = next;
		}
	}
	free(table->nodes); // freeing 
	free(table);
}

int table_search(table_t *table, int data) {
	size_t index = hash_int(data) % table->buckets;

	node_t *node = table->nodes[index];

	while (node != NULL) {
		if (node->data == data)
			return 0;   /* found */
		node = node->next;
	}
	fprintf(stderr, "[h_table:search] key not found\n");
	return 1;   /* not found */
}

int table_insert(table_t *table, int data) {
	size_t index = hash_int(data) % table->buckets;

	node_t *node = table->nodes[index];
	while (node != NULL) {
		if (node->data == data) { // walking over the list of nodes on the index bucket to check for duplicates
			fprintf(stderr, "[h_table:insert] duplicate key\n");
			return 1; // 1 as error since hash table can't have duplicate data
		}
		node = node->next;
	}

	node_t *new_node = h_new_node(data);
	if (!new_node) {
		fprintf(stderr, "[h_table:insert] malloc failed\n");
		return 1;
	}

	new_node->next = table->nodes[index]; // prepend to head node of bucket
	table->nodes[index] = new_node;

	return 0;
}

int table_remove(table_t *table, int data) {
	size_t index = hash_int(data) % table->buckets;

	node_t *node = table->nodes[index];
	node_t *prev = NULL;

	while (node != NULL) {
		if (node->data == data) {

			if (prev == NULL) {
				/* removing head of chain */
				table->nodes[index] = node->next;
			} else {
				/* removing non head element by iterating to next node_t in the bucket's list */
				prev->next = node->next;
			}

			free(node);
			return 0;
		}
		prev = node;
		node = node->next;
	}

	fprintf(stderr, "[h_table:remove] key not found\n");
	return 1;
}

// to understand this hash function, please read this thread: https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key

size_t hash_int(int data) {
	data = ((data >> 16) ^ data) * 0x45d9f3b;
	data = ((data >> 16) ^ data) * 0x45d9f3b;
	data = ((data >> 16) ^ data);

	return (size_t)data;
}

int main(void) {
	table_t *table = h_table_init(10);
	if (!table) {
		fprintf(stderr, "failed to initialize table\n");
		return 1;
	}

	printf("inserting values...\n");
	table_insert(table, 42);
	table_insert(table, 15);
	table_insert(table, 90);

	printf("attempting duplicate insert...\n");
	table_insert(table, 42); // should give error

	printf("searching values...\n");
	printf("search 42: %s\n", table_search(table, 42) == 0 ? "found" : "not found");
	printf("search 99: %s\n", table_search(table, 99) == 0 ? "found" : "not found");

	printf("removing 15...\n");
	table_remove(table, 15);

	printf("searching removed value...\n");
	printf("search 15: %s\n", table_search(table, 15) == 0 ? "found" : "not found");

	table_destruct(table);

	return 0;
}
