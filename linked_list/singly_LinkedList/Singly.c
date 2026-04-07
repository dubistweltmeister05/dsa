#include <stdio.h>
#include <stdlib.h>


// Defining the Node for a Linked List
typedef struct node {
    int data;                  // Data stored in the node
    struct node *next_node;    // Pointer to the next node
}__attribute__((packed)) node_s;

node_s *__head = NULL;         // Head pointer for the linked list


// This function initializes the head of the linked list
int inti(int data){
    if(__head){
        printf("List already allocated !\n");
        return -1;
    }
    __head = malloc(sizeof(node_s)); // Allocate memory for head node

    if(!__head){
        printf("memmory allocation failed!");
        return -2;
    }

    __head -> next_node = NULL; // Set next pointer to NULL
    __head->data = data;        // Set data for head node

    return 0;
}


// This function adds a new node at the beginning of the linked list
int add(int data){
    node_s *node_n = malloc(sizeof(node_s)); // Allocate memory for new node

    if (!node_n){
        printf("Allocation Failed");
        return -2;
    }

    node_n->next_node = __head; // New node points to current head
    node_n->data = data;        // Set data for new node

    __head = node_n;            // Update head to new node

    return 0;
}

// This function adds a new node at the end of the linked list
int add_at_the_end(int data){
    node_s *cur;
    node_s *node_n = malloc(sizeof(node_s)); // Allocate memory for new node

    node_n->next_node = NULL; // New node will be the last node
    node_n->data = data;      // Set data for new node

    if (!node_n) {
        printf("Data Allocation Failed!");
        return -1;
    }

    // Traverse to the end of the list
    for (cur = __head; cur->next_node != NULL; cur = cur->next_node){
        // No operation needed, just moving to the end
    }

    cur -> next_node = node_n; // Link last node to new node
}

int Search(int data){
    node_s *cursor = __head;
    for (cursor = __head ; cursor !=NULL ; cursor = cursor -> next_node){
        if (cursor->data == data){
            return 1;

        }
    return 0;
    } 

}

int delete(int data){
    for(node_s *p1=NULL ,*p2= __head; p2 != NULL; p1 = p2 , p2 = p2->next_node){
        if (p2->data == data){
            p1->next_node = p2 ->next_node;
            free(p2);
            printf("Value Deleted : %d\n",data);
            return 1;
            }
    }
    return 0;
}

// This function traverses and prints all nodes in the linked list
void traverse(void){
    node_s *cursor = __head;
    for (cursor = __head ; cursor !=NULL ; cursor = cursor -> next_node){
        printf("%d ", cursor->data); // Print data of each node
    } 
    printf("\n");
}

int Insert_node(int key,int data){

    node_s *k ,*n;
    for (k = __head ; k !=NULL ;k = k->next_node){

        if (k->data == key){
            break;
        }
        
        if(!k){
            printf("Cannot locate Key");
            return 0;
        }

        n = malloc(sizeof(node_s)); 
         
        if(!n){
            printf("Could not enter Node");
            return -1;
        }

        n->data = data;
        n->next_node = k->next_node;

        k->next_node = n;

    return 1;
    } 

}

// Main function to demonstrate linked list operations
int main (){
    inti(100); // Initialize list with head node data 

    // Add 10 nodes at the beginning
    for (int i = 0; i < 10; i++ ){
        add(i);
    }

    // Add 10 nodes at the end
    for (int j = 0; j < 10; j++ ){
        add_at_the_end(j);
    }

    traverse(); // Print all nodes in the list
    printf("Value : %d\n",Search(100));

    delete(100);
    traverse();

    Insert_node(11,10);
    traverse();
    return 0;
}
