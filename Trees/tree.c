#include "tree.h"

typedef struct qnode
{
    node_s *tree_node;
    struct qnode *next;
} qnode_s;

static qnode_s *q_front = NULL;
static qnode_s *q_rear = NULL;

static void enqueue(node_s *node)
{
    qnode_s *new_qnode = (qnode_s *)malloc(sizeof(qnode_s));
    if (!new_qnode)
    {
        fprintf(stderr, "%s: malloc failed\n", __func__);
        return;
    }

    new_qnode->tree_node = node;
    new_qnode->next = NULL;

    if (q_rear == NULL)
    {
        q_front = new_qnode;
        q_rear = new_qnode;
    }
    else
    {
        q_rear->next = new_qnode;
        q_rear = new_qnode;
    }
}

static node_s *dequeue(void)
{
    if (q_front == NULL)
    {
        return NULL;
    }

    qnode_s *temp = q_front;
    node_s *node = temp->tree_node;
    q_front = q_front->next;
    if (q_front == NULL)
    {
        q_rear = NULL;
    }
    free(temp);
    return node;
}

static bool queue_empty(void)
{
    return (q_front == NULL);
}

static void destroy(void)
{
    while (!queue_empty())
    {
        qnode_s *temp = q_front;
        q_front = q_front->next;
        free(temp);
    }
    q_rear = NULL;
}

void add(char data)
{
    node_s *node = allocate;
    if (!node)
    {
        fprintf(stderr, "%s: malloc failed\n", __func__);
        return;
    }

    node->data = data;
    node->l_child = NULL;
    node->r_child = NULL;

    if (!__root)
    {
        __root = node;
        return;
    }

    enqueue(__root);

    while (!queue_empty())
    {
        node_s *current = dequeue();
        if (current->l_child == NULL)
        {
            current->l_child = node;
            destroy();
            return;
        }
        else
        {
            enqueue(current->l_child);
        }

        if (current->r_child == NULL)
        {
            current->r_child = node;
            destroy();
            return;
        }
        else
        {
            enqueue(current->r_child);
        }
    }

    destroy();
}

static void inorder_traversal(node_s *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->l_child);
    printf("%c ", root->data);
    inorder_traversal(root->r_child);
}

int main(void)
{
    add('A');
    add('B');
    add('C');
    add('D');
    add('E');

    printf("\nInorder traversal: ");
    inorder_traversal(__root);
    printf("\n");

    return 0;
}