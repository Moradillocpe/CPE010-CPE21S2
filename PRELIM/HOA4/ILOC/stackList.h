#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>

class Node {
public:
    char data;
    Node* next;
};

inline Node *head = NULL, *tail = NULL;

inline bool isEmpty() {
    if (head == NULL)
        return true;

    return false;
}

inline void push(char newData) {
    Node *newNode = new Node;

    newNode->data = newData;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

inline char pop() {
    char tempVal;
    Node *temp;

    if (isEmpty()) {
        std::cout << "Stack Underflow." << std::endl;
        return '\0';
    }

    temp = head;
    tempVal = temp->data;
    head = head->next;
    delete temp;

    return tempVal;
}

#endif


