#ifndef __H_QUEUE_
#define __H_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

int init(int data);
int enqueue(int data);
int dequeue(int *out);
int traverse(void);

#endif
