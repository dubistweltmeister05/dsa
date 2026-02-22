#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
    char data;
    struct node *l_child;
    struct node *r_child;
} __attribute__((packed)) node_s;

node_s *__root=NULL;

#define allocate (node_s*)malloc(sizeof(node_s))
void add (char data);