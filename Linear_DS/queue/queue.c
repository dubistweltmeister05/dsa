#include "queue.h"

static node_t *head = NULL;
static node_t *tail = NULL;


int init(int data)
{
    if (head) {
        printf("Queue already initialized\n");
        return -1;
    }

    head = tail = malloc(sizeof(node_t));
    if (!head)
        return -2;

    head->data = data;
    head->next = NULL;

    return 0;
}

int enqueue(int data)
{
    if (!head)
        return -1;

    node_t *new = malloc(sizeof(node_t));
    if (!new)
        return -2;

    new->data = data;
    new->next = NULL;

    tail->next = new;
    tail = new;

    return 0;
}
int dequeue(int *out)
{
    if (!head)
        return -1;

    node_t *temp = head;
    *out = head->data;
    head = head->next;

    if (!head)          // queue became empty
        tail = NULL;

    free(temp);
    return 0;
}

/* Traverse queue */
int traverse(void)
{
    if (!head)
        return -1;

    node_t *temp = head;
    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    return 0;
}
int main(void)
{
    init(69);

    for (int i = 0; i < 10; i++)
        enqueue(i);

    traverse();

    int val;
    dequeue(&val);
    printf("Dequeued: %d\n", val);

    return 0;
}