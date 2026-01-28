// C++ implementation of the above approach
#include <cstdint>
#include <iostream>

struct Node {
    int data;

    // XOR of next and prev
    Node* both;
};

// Class representing XOR linked list
class XORLinkedList {
private:
    Node* head;
    Node* tail;

    // XOR function for Node pointers
    Node* XOR(Node* a, Node* b);

public:

    // Constructor to initialize 
    // an empty list
    XORLinkedList();
  
    // Insert a node at the head of the list
    void insertAtHead(int data);
  
    // Insert a node at the tail of the list
    void insertAtTail(int data);
  
    // Delete a node from the head
    // of the list
    void deleteFromHead();
  
    // Delete a node from the tail
    // of the list
    void deleteFromTail();
  
    // Print the elements of the list
    void printList();
};

XORLinkedList::XORLinkedList() {

    // Initialize head and tail to
    // nullptr for an empty list
    head = tail = nullptr; 
}

Node* XORLinkedList::XOR(Node* a, Node* b) {

    // XOR operation for Node pointers
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void XORLinkedList::insertAtHead(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->both = head;

    if (head)
        head->both = XOR(newNode, XOR(head->both, nullptr));
    else {

        // If the list was empty, the new
        // node is both the head and the tail
        tail = newNode;
    }

    // Update the head to the new node
    head = newNode;
}

void XORLinkedList::insertAtTail(int data) {

    Node* newNode = new Node();
    newNode->data = data;
    newNode->both = tail;

    if (tail)
        tail->both = XOR(XOR(tail->both, nullptr), newNode);
    else {

        // If the list was empty, the new
        // node is both the head and the tail
        head = newNode;
    }

    // Update the tail to the new node
    tail = newNode;
}

void XORLinkedList::deleteFromHead() {
    if (!head) return;

    Node* temp = head;
    Node* next = head->both;
    
    if (next) {
        Node* nextNext = XOR(head, next->both);
        next->both = nextNext;
    }
    else {
        tail = nullptr;
    }
    
    head = next;
    delete temp;
}

void XORLinkedList::deleteFromTail() {
    if (!tail) return;
    Node* temp = tail;
    Node* prev = tail->both;
    
    if (prev) {
        Node* prevPrev = XOR(tail, prev->both);
        prev->both = prevPrev;
    }
    else {
        head = nullptr;
    }
    
    tail = prev;
    delete temp;
}
void XORLinkedList::printList() {
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        std::cout << current->data << " ";
        Node* next = XOR(prev, current->both);
        prev = current;
        current = next;
    }
    std::cout << std::endl;
}

int main() {
    XORLinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    // prints 20 10 30 40
    list.printList();

    list.deleteFromHead();

    // prints 10 30 40
    list.printList();

    list.deleteFromTail();

    // prints 10 30
    list.printList();
    return 0;
}