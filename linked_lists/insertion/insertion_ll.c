#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

#define allocate() ((struct node *)malloc(sizeof(struct node)))

void print_ll(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("-----------------------------\n");
}

struct node *insert_at_head(struct node *head, int val)
{
    struct node *tmp = allocate();
    tmp->data = val;
    tmp->next = head;
    head = tmp;

    return head;
}

struct node *insert_at_tail(struct node *head, int val)
{
    struct node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    struct node *tmp_1 = allocate();
    tmp_1->data = val;
    tmp_1->next = NULL;
    tmp->next = tmp_1;
    return head;
}

struct node *insert_at_node(struct node *head, int val, int index)
{
    struct node *tmp = head;
    struct node *tmp_1 = allocate();
    tmp_1->data = val;

    int count = 0;
    while (count != index)
    {
        tmp = tmp->next;
        count++;
    }

    tmp_1->next = tmp->next;
    tmp->next = tmp_1;
    return head;
}

int main(void)
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = first;

    first->data = 4;
    first->next = second;

    second->data = 6;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 69;
    fourth->next = NULL;

    print_ll(head);

    head = insert_at_head(head, 68);

    print_ll(head);

    head = insert_at_tail(head, 71);

    print_ll(head);

    head = insert_at_node(head, 23, 3);

    print_ll(head);
    return 0;
}
