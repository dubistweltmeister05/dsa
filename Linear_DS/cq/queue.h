#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct queue {
	int front;
	int rear;
	int size;
	char **data;
} queue_t;

void queue_init(queue_t **queue, char *data, int size);
int enqueue(queue_t *queue, char *data);

void display_queue(queue_t *queue);

#endif /* __QUEUE_H_ */
