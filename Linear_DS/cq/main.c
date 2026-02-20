#include <stdio.h>
#include "queue.h"
#include <stdbool.h>


void display_queue(queue_t *queue) {
    printf("--- Queue Display ---\n");

    if (queue == NULL || queue->front == -1) {
	    printf("queue is empty\n");
	    return;
    }

    int i = queue->front;

    while (1) {
	    printf("pos = %d data = %s\n", i, queue->data[i]);

	    if (i == queue->rear)
		    break;
	    i = (i + 1) % queue->size;
    }
}

int main(void) {
	queue_t *queue = NULL;
	int size = 10;
	char *str = "first";

	printf("Queue initialization\n");
	queue_init(&queue, str, size);
	printf("Queue_data\n");
	display_queue(queue);

	printf("***** Enqueue ******\n");
	int ret = enqueue(queue, "2");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
        ret = enqueue(queue, "3");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "4");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "5");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "6");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "7");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "8");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "9");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "10");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	ret = enqueue(queue, "11");
	if (ret < 0) {
		printf("Enqueue failed\n");
	}
	display_queue(queue);

	return 0;
			
}
