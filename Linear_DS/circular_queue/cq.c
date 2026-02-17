#include <stdio.h>
#include <stdlib.h>
#include "cq.h"

static node_t *head = NULL;
static node_t *tail = NULL;

int init(int data)
{
    if (head)
        return -1;

    head = tail = malloc(sizeof(node_t));
    if (!head)
        return -2;

    head->data = data;
    head->next = head;   // circular link

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
    new->next = head;

    tail->next = new;
    tail = new;

    return 0;
}

int dequeue(int *out)
{
    if (!head)
        return -1;

    *out = head->data;

    /* single element case */
    if (head == tail) {
        free(head);
        head = tail = NULL;
        return 0;
    }

    node_t *temp = head;
    head = head->next;
    tail->next = head;

    free(temp);
    return 0;
}

int traverse(void)
{
    if (!head)
        return -1;

    node_t *temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);

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
