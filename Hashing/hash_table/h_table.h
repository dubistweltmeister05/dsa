/*
 note:
 normally a hash table uses a compile-time constant (e.g., a #define HASH_SIZE)
 to fix the number of buckets. This makes the table size static and not changeable
 by the user.

 in this implementation, the user provides the number of buckets when calling
 h_table_init(size_t buckets). This makes the table flexible: the user can choose
 the size based on their needs, and it also allows multiple hash-table instances
 with different bucket counts. The table_t structure keeps track of the chosen
 size through its <buckets> field.
*/

#ifndef H_TABLE_H
#define H_TABLE_H

#include <stddef.h>

typedef struct node {
	int data;
	struct node *next;
} node_t;

typedef struct table {
	size_t buckets;
	node_t **nodes;
} table_t;

table_t* h_table_init(size_t buckets);
void table_destruct(table_t *table); // in order to completely free the allocated space to the table_t structure
int table_insert(table_t *table, int data);
int table_search(table_t *table, int data);
int table_remove(table_t *table, int data);
size_t hash_int(int data);

#endif
