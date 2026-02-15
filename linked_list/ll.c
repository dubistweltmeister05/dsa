#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

int init(int data)
{
    if (head)
    {
        printf("This has already been initialized");
        return -1;
    }
    printf("Before allocation, head = %p\n", (void *)head);

    head = malloc(sizeof(node_t));
    if (!head)
    {
        perror("malloc failed");
        return -2;
    }

    head->data = data;
    head->next = NULL;

    printf("After allocation, head = %p\n", (void *)head);
    printf("Stored data: %d\n", head->data);
    return 0;
}

int add(int data)
{
    if (!head)
    {
        printf("List not initialized\n");
        return -1;
    }

    node_t *new = malloc(sizeof(node_t));
    if (!new)
    {
        perror("malloc failed");
        return -2;
    }

    new->data = data;
    new->next = NULL;

    node_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
    return 0;
}

void print_ll(node_t *head)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
}
int main(void)
{
    init(101);
    for (int i = 0; i < 100000; i++)
    {
        add(i);
    }
    // print_ll(head);
    return 0;
}
