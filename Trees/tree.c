#include "tree.h"
void add(char data)
{

    node_s *node = allocate;
    node->data = data;
    node->l_child = NULL;
    node->r_child = NULL;
    if (!__root)
    {
        __root = node;
    }

    if (__root->l_child == NULL)
    {
        __root->l_child = node;
        return;
    }
    else
    {
        enqueue(__root->l_child);
    }

    if (__root->r_child == NULL)
    {
        __root->r_child = node;
        return;
        destroy();
    }
    else
    {
        enqueue(__root->r_child);
    }
    while (queue_empty() == false)
    {
        node_s *node_free_exp = dequeue();
        if (node_free_exp->l_child == NULL)
        {
            node_free_exp->l_child = node;
        }
        else
        {
            enqueue(node_free_exp->l_child);
        }

        if (node_free_exp->r_child == NULL)
        {
            node_free_exp->r_child = node;
        }
        else
        {
            enqueue(node_free_exp->r_child);
        }
    }
}
int main()
{
    printf("Hello world!\n");

    return 0;
}