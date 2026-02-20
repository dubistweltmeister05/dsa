#include "queue.h"
#include <string.h>

void queue_init(queue_t **queue, char *data, int size){
	queue_t *q = malloc(sizeof(queue_t));
	if (!q) {
		printf("failed to allocate memory\n");
		free(q);
		return;
	}

	q->data = malloc(sizeof(char *) * size);
	if (q->data ==  NULL) {
		printf("failed to allocate memory for queue->data\n");
		free(q->data);
		return;
	}

	q->front = -1;
	q->rear = -1;
	q->size = size;

	if (data) {
		q->data[0] = data;
		if (!q->data[0]) {
			printf("Failed to add data\n");
			free(q);
			return;
		}
		q->front = 0;
		q->rear = 0;
	}

	*queue = q;
}

int enqueue(queue_t *queue, char *data) {
	if (queue->front == (queue->rear + 1) % queue->size) {
		printf("Queue is full");
		return -1;
	}

	/* When Queue is empty */
	if (queue->front == -1 && queue->rear == -1) {
		queue->front = 0;
		queue->rear = 0;
	} else {
		queue->rear = (queue->rear + 1) % queue->size;
	}

	queue->data[queue->rear] = data;
	
	return 0;
}
